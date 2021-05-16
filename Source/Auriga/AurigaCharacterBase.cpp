// Copyright 2019 Malebisse

#include "AurigaCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "Engine.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "AurigaAbilitySystemComponent.h"
#include "AurigaGameplayAbility.h"
#include "AurigaGameplayEffect.h"
#include "AurigaAttributeSet.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// AAurigaCharacterBase

AAurigaCharacterBase::AAurigaCharacterBase()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera. TODO: Implement this for left mouse button camera rotation.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create AbilitySystem component
	AbilitySystem = CreateDefaultSubobject<UAurigaAbilitySystemComponent>(TEXT("AbilitySystem"));
	AbilitySystem->SetIsReplicated(true);

	// Create the AttributeSet, this replicates by default
	AttributeSet = CreateDefaultSubobject<UAurigaAttributeSet>(TEXT("AttributeSet"));

	//Set action bar length
	AbilitiesOnActionBar.SetNum(8);

	Inventory.SetNum(24);

	bIsDead = false;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

}

void AAurigaCharacterBase::GrantAbility(TSubclassOf<UAurigaGameplayAbility> AbilityToGrant)
{
	if (AbilitySystem)
	{
		if (HasAuthority() && AbilityToGrant)
		{
			AbilitySystem->GiveAbility(FGameplayAbilitySpec(AbilityToGrant, 1, INDEX_NONE, this));

			//Add the ability to the list of abilities the character is able to use
			AbilitiesGranted.Add(AbilityToGrant);

			AbilitySystem->InitAbilityActorInfo(this, this);

			UpdateAbilities();
			OnUpdateAbilities.Broadcast(AbilitiesOnActionBar);
		}

	}



}

void AAurigaCharacterBase::HandleDamage(float DamageAmount, const struct FGameplayTagContainer& DamageTags, AAurigaCharacterBase* InstigatorPawn, AActor* DamageCauser)
{
	OnDamaged(DamageAmount, DamageTags, InstigatorPawn, DamageCauser);
}

void AAurigaCharacterBase::HandleHealthChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags)
{
	OnHealthChanged(DeltaValue, EventTags);
}

void AAurigaCharacterBase::AddToInventory(TSubclassOf<UAurigaGameplayEffect> GameplayEffect)
{
	int index = -1;
	int indexToUse = -1;

	for (TSubclassOf<UAurigaGameplayEffect> Item : Inventory)
	{
		index = index + 1;

		if (!Item)
		{
			if (indexToUse == -1)
			{
				indexToUse = index;
			}
		}
	}

	if ((indexToUse < (Inventory.Num() - 1)) && (index != -1))
	{
		Inventory[indexToUse] = GameplayEffect;
	}
	
	OnUpdateInventory.Broadcast(Inventory);
}

void AAurigaCharacterBase::AddToEquippedGear(TSubclassOf<UAurigaGameplayEffect> GameplayEffect)
{
	EquippedGear.Add(GameplayEffect);

	OnUpdateEquipment.Broadcast(EquippedGear);
}

void AAurigaCharacterBase::PrintInventory()
{
	FString sInv = "";

	for (TSubclassOf<UAurigaGameplayEffect> Item : Inventory)
	{
		if (!Item)
		{
			sInv.Append("NONE");
		}
		else if (Item)
		{
			sInv.Append(Item->GetName());
			sInv.Append(" | ");
		}
	}

	GEngine->AddOnScreenDebugMessage(1, 5, FColor::White, *sInv);
}

void AAurigaCharacterBase::PrintEquippedGear()
{
	FString sGear = "";

	for (TSubclassOf<UAurigaGameplayEffect> Gear : EquippedGear)
	{
		sGear.Append(Gear->GetName());
		sGear.Append(" | ");
	}

	GEngine->AddOnScreenDebugMessage(1, 5, FColor::White, *sGear);
}

FString AAurigaCharacterBase::GetCharacterName()
{
	return CharacterName;
}

void AAurigaCharacterBase::DropToInventorySlot(TSubclassOf<UAurigaGameplayEffect> GameplayEffect)
{
	OnUpdateInventory.Broadcast(Inventory);
}

void AAurigaCharacterBase::DropToEquipmentSlot(TSubclassOf<UAurigaGameplayEffect> GameplayEffect)
{
	OnUpdateEquipment.Broadcast(EquippedGear);
}


void AAurigaCharacterBase::PrintAbilitiesGranted()
{
	//Print AbilitiesGranted
	FString sAbilitiesGranted = "";

	for (TSubclassOf<UAurigaGameplayAbility> AbilityName : AbilitiesGranted)
	{
		sAbilitiesGranted.Append(AbilityName->GetName());
		sAbilitiesGranted.Append(" | ");
	}

	GEngine->AddOnScreenDebugMessage(1, 5, FColor::White, *sAbilitiesGranted);

	//Print AbilitiesOnActionBar
	FString sAbilitiesOnActionBar = "";

	for (TSubclassOf<UAurigaGameplayAbility> AbilityName : AbilitiesOnActionBar)
	{
		if (AbilityName)
		{
			sAbilitiesOnActionBar.Append(AbilityName->GetName());
			sAbilitiesOnActionBar.Append(" | ");
		}

		if (!AbilityName)
		{
			sAbilitiesOnActionBar.Append("NONE | ");
		}

	}

	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Magenta, *sAbilitiesOnActionBar);

}

void AAurigaCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	//if (UAurigaAbilitySystem)
	//{
	//	FGameplayAbilityActorInfo* actorInfo = new FGameplayAbilityActorInfo();
	//	actorInfo->InitFromActor(this, this, UAurigaAbilitySystem);
	//	UAurigaAbilitySystem->AbilityActorInfo = TSharedPtr<FGameplayAbilityActorInfo>(actorInfo);

	//	if (HasAuthority() && Ability)
	//	{
	//		// Grant abilities, but only on the server	
	//		for (TSubclassOf<UAurigaGameplayAbility>& OnCreationAbilities : GameplayAbilities)
	//		{
	//			AbilitySystem->GiveAbility(FGameplayAbilitySpec(StartupAbility, 1, INDEX_NONE, this));
	//		}
	//	}
	//	AbilitySystem->InitAbilityActorInfo(this, this);
	//}
}

void AAurigaCharacterBase::PossessedBy(AController * NewController)
{
	Super::PossessedBy(NewController);

	AbilitySystem->RefreshAbilityActorInfo();
}

void AAurigaCharacterBase::UpdateAbilities()
{
	OnUpdateAbilities.Broadcast(AbilitiesGranted);
}

void AAurigaCharacterBase::UpdateInventory()
{
	OnUpdateInventory.Broadcast(Inventory);
}

void AAurigaCharacterBase::DropToActionBar(TSubclassOf<UAurigaGameplayAbility> pickup)
{
	OnUpdateActionBar.Broadcast(AbilitiesOnActionBar);
}

bool AAurigaCharacterBase::IsOtherHostile(AAurigaCharacterBase* target)
{
	if (GetTeamID() != target->GetTeamID())
	{
		return true;
	}
	else
	{
		return false;
	}

}

uint32 AAurigaCharacterBase::GetTeamID()
{
	return TeamID;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AAurigaCharacterBase::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AAurigaCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAurigaCharacterBase::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

}

void AAurigaCharacterBase::MoveForward(float Value)
{
	
	if ((Controller != NULL) && (Value != 0.0f))
	{
		AutoRunEnabled = false; //TODO: Fix AutoRun enabling

		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AAurigaCharacterBase::AutoRun()
{
	if ((Controller != NULL))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, 1);
	}

}

void AAurigaCharacterBase::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}