// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AbilitySystemInterface.h"
#include "CoreMinimal.h"
#include "Delegate.h"
#include "GameFramework/Character.h"
#include "UObject/ScriptInterface.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagAssetInterface.h"
#include "AurigaAbilitySystemComponent.h"
#include "AurigaGameplayEffect.h"
#include "AurigaGameplayAbility.h"
#include "Auriga/AurigaAttributeSet.h"
#include "AurigaCharacterBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateAbilitiesDelegate, const TArray<TSubclassOf<UAurigaGameplayAbility>>&, AbilitiesGranted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateInventoryDelegate, const TArray<TSubclassOf<UAurigaGameplayEffect>>&, Inventory);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateEquipmentDelegate, const TArray<TSubclassOf<UAurigaGameplayEffect>>&, EquippedGear);

UCLASS(config=Game)
class AAurigaCharacterBase : public ACharacter, public IAbilitySystemInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

	/** Spring Arm / CameraBoom */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** AbilitySystemComponent */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UAurigaAbilitySystemComponent* AbilitySystem;

public:

	AAurigaCharacterBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CurrentTarget")
	AActor* CurrentTarget;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void UpdateAbilities();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void UpdateInventory();

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FUpdateAbilitiesDelegate OnUpdateAbilities;

	UFUNCTION(BlueprintCallable)
	void DropToActionBar(TSubclassOf<UAurigaGameplayAbility> pickup);

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FUpdateAbilitiesDelegate OnUpdateActionBar;

	UFUNCTION(BlueprintImplementableEvent, Category = "Attribute", meta = (DisplayName = "OnAttributeModifierUpdate"))
	void BP_OnAttributeModifierUpdate();

	UFUNCTION(BlueprintImplementableEvent, Category = "Attribute", meta = (DisplayName = "CharacterDeath"))
	void BP_CharacterDeath();

	UFUNCTION(BlueprintCallable, Category = "Combat", meta = (DisplayName = "IsOtherHostile"))
	bool IsOtherHostile(AAurigaCharacterBase* target);

	UFUNCTION(Category = "Combat", meta = (DisplayName = "IsOtherHostile"))
	uint32 GetTeamID();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDamaged(float DamageAmount, const struct FGameplayTagContainer& DamageTags, AAurigaCharacterBase* InstigatorCharacter, AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHealthChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags);

	// Called in AurigaAttributeSet
	void HandleDamage(float DamageAmount, const struct FGameplayTagContainer& DamageTags, AAurigaCharacterBase* InstigatorCharacter, AActor* DamageCauser);
	void HandleHealthChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags);

	UFUNCTION(BlueprintCallable)
	void AddToInventory(TSubclassOf<UAurigaGameplayEffect> GameplayEffect);

	UFUNCTION(BlueprintCallable)
	void AddToEquippedGear(TSubclassOf<UAurigaGameplayEffect> GameplayEffect);

	UFUNCTION(BlueprintCallable)
	void PrintInventory();

	UFUNCTION(BlueprintCallable)
	void PrintEquippedGear();

	UFUNCTION(BlueprintCallable)
	FString GetCharacterName();

	UFUNCTION(BlueprintCallable)
	void DropToInventorySlot(TSubclassOf<UAurigaGameplayEffect> GameplayEffect);

	UFUNCTION(BlueprintCallable)
	void DropToEquipmentSlot(TSubclassOf<UAurigaGameplayEffect> GameplayEffect);

	UPROPERTY(BlueprintAssignable, Category = "Pickup")
	FUpdateInventoryDelegate OnUpdateInventory;

	UPROPERTY(BlueprintAssignable, Category = "Pickup")
	FUpdateInventoryDelegate OnUpdateEquipment;


private:
	
	UAurigaAbilitySystemComponent* GetAbilitySystemComponent() const override //We add this function, overriding it from IAbilitySystemInterface.
	{
		return AbilitySystem;
	};

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override { TagContainer = GameplayTagContainer; return; }



protected:

	bool bIsDead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	FString CharacterName;

	/** Character's assigned TeamID to determine hostile/friendly characters */
	UPROPERTY(EditAnywhere, Category = "Attribute")
	uint32 TeamID;

	/** Character GameplayTagContainer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTags")
	FGameplayTagContainer GameplayTagContainer;

	/** Abilities on action bar */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TArray<TSubclassOf<UAurigaGameplayAbility>> AbilitiesOnActionBar;

	/** Inventory */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TArray<TSubclassOf<UAurigaGameplayEffect>> Inventory;

	/** Equipped Gear */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TArray<TSubclassOf<UAurigaGameplayEffect>> EquippedGear;

	/** List of attributes modified by the ability system */
	UPROPERTY()
	UAurigaAttributeSet* AttributeSet;

	/** Calls GiveAbility - For use in Blueprints */
	UFUNCTION(BlueprintCallable)
	void GrantAbility(TSubclassOf<UAurigaGameplayAbility> AbilityToGrant);

	/** Abilities to grant to this character on creation. These will be activated by tag or event and are not bound to specific inputs */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	TArray<TSubclassOf<UAurigaGameplayAbility>> AbilitiesToGiveOnCreation;

	/** Abilities the character has been granted  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	TArray<TSubclassOf<UAurigaGameplayAbility>> AbilitiesGranted;

	/** Debug funtion to print all abilities granted*/
	UFUNCTION(BlueprintCallable)
	void PrintAbilitiesGranted();

	// Override BeginPlay
	virtual void BeginPlay() override;

	// Override PossessedBy
	void PossessedBy(AController * NewController) override;

	/** Called for forwards/backward input - BlueprintCallable for mouse movement*/
	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);

	/** Toggles Auto Run */
	UFUNCTION(BlueprintCallable)
	void AutoRun();

	/** Variable that Enables/Disables AutoRun*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool AutoRunEnabled = false; 

	/** Called for side to side input */
	void MoveRight(float Value);

	// Override SetupPlayerInputComponent
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

