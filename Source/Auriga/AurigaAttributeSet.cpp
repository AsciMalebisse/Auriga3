// Copyright 2019 Malebisse


#include "AurigaAttributeSet.h"
#include "AurigaCharacterBase.h"
#include "GameplayEffect.h"
#include "AurigaGameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Engine/DataTable.h"
#include "Engine.h"
#include "Net/UnrealNetwork.h"

UAurigaAttributeSet::UAurigaAttributeSet()
	: Level (1.f)
	, Ignis(0.f)			
	, IgnisModifier(0.f)
	, Aqua(0.f)			
	, AquaModifier(0.f)
	, Voltaic(0.f)			
	, VoltaicModifier(0.f)
	, Terra(0.f)			
	, TerraModifier(0.f)
	, Lux(0.f)			
	, LuxModifier(0.f)
	, Void(0.f)			
	, VoidModifier(0.f)
	, Gaia(0.f)			
	, GaiaModifier(0.f)
	, Aether(0.f)			
	, AetherModifier(0.f)
	, Psionic(0.f)			
	, PsionicModifier(0.f)
	, Ruin(0.f)			
	, RuinModifier(0.f)
	, Vitality(10.f)			
	, CurrentHealth(100.f)
	, MaxHealth(100.f)		
	, CurrentZeal(100.f)
	, MaxZeal(100.f)
	, CurrentValor(0.f)
	, MaxValor(100.f)
	, Prowess(10.f)			
	, BaseAttackPower(10.f)				
	, AttackPower(0.f)				
	, Sorcery(10.f)			
	, MagicPower(10.f)		   //Not used
	, Mysticism(10.f)			
	, HealingPower(10.f)		//Not Used
	, CriticalHitChance(0.f)			
	, CritChance(0.0f)			
	, CriticalHitDamage(0.f)			
	, CritDamageModifier(0.f)		
	, Haste(0.f)			
	, AttackSpeed(0.f)				
	, CastSpeed(0.f)				
	, Instincts(0.f)			
	, InstinctsModifier(0.f)	
	, Synthesis(0.f)			
	, SynthesisModifier(0.f)	
	, Armor(0.f)			
	, ArmorModifier(0.f)		
	, Barrier(0.f)			
	, BarrierModifier(0.f)		
	, BlockChance(0.f)		
	, DodgeChance(0.05f)		
	, ParryChance(0.05f)		
	, MoveSpeedModifier(1.f)		
	, DamageToTake(0.f)
	, OutputDamageMultiplier(1.f)
	, ReceivedDamageMultiplier(1.f)
	, OutputHealingMultiplier(1.f)
	, ReceivedHealingMultiplier(1.f)
	, BaseAttackTime(1.5f)
	, AttackRange(200.f)
{
}


void UAurigaAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAurigaAttributeSet, Level);
	DOREPLIFETIME(UAurigaAttributeSet, Ignis);
	DOREPLIFETIME(UAurigaAttributeSet, IgnisModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Aqua);
	DOREPLIFETIME(UAurigaAttributeSet, AquaModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Voltaic);
	DOREPLIFETIME(UAurigaAttributeSet, VoltaicModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Terra);
	DOREPLIFETIME(UAurigaAttributeSet, TerraModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Lux);
	DOREPLIFETIME(UAurigaAttributeSet, LuxModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Void);
	DOREPLIFETIME(UAurigaAttributeSet, VoidModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Gaia);
	DOREPLIFETIME(UAurigaAttributeSet, GaiaModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Aether);
	DOREPLIFETIME(UAurigaAttributeSet, AetherModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Psionic);
	DOREPLIFETIME(UAurigaAttributeSet, PsionicModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Ruin);
	DOREPLIFETIME(UAurigaAttributeSet, RuinModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Vitality);
	DOREPLIFETIME(UAurigaAttributeSet, CurrentHealth);
	DOREPLIFETIME(UAurigaAttributeSet, MaxHealth);
	DOREPLIFETIME(UAurigaAttributeSet, CurrentZeal);
	DOREPLIFETIME(UAurigaAttributeSet, MaxZeal);
	DOREPLIFETIME(UAurigaAttributeSet, CurrentValor);
	DOREPLIFETIME(UAurigaAttributeSet, MaxValor);
	DOREPLIFETIME(UAurigaAttributeSet, Prowess);
	DOREPLIFETIME(UAurigaAttributeSet, BaseAttackPower);
	DOREPLIFETIME(UAurigaAttributeSet, AttackPower);
	DOREPLIFETIME(UAurigaAttributeSet, Sorcery);
	DOREPLIFETIME(UAurigaAttributeSet, MagicPower);
	DOREPLIFETIME(UAurigaAttributeSet, Mysticism);
	DOREPLIFETIME(UAurigaAttributeSet, HealingPower);
	DOREPLIFETIME(UAurigaAttributeSet, CriticalHitChance);
	DOREPLIFETIME(UAurigaAttributeSet, CritChance);
	DOREPLIFETIME(UAurigaAttributeSet, CriticalHitDamage);
	DOREPLIFETIME(UAurigaAttributeSet, CritDamageModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Haste);
	DOREPLIFETIME(UAurigaAttributeSet, AttackSpeed);
	DOREPLIFETIME(UAurigaAttributeSet, CastSpeed);
	DOREPLIFETIME(UAurigaAttributeSet, Instincts);
	DOREPLIFETIME(UAurigaAttributeSet, InstinctsModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Synthesis);
	DOREPLIFETIME(UAurigaAttributeSet, SynthesisModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Armor);
	DOREPLIFETIME(UAurigaAttributeSet, ArmorModifier);
	DOREPLIFETIME(UAurigaAttributeSet, Barrier);
	DOREPLIFETIME(UAurigaAttributeSet, BarrierModifier);
	DOREPLIFETIME(UAurigaAttributeSet, BlockChance);
	DOREPLIFETIME(UAurigaAttributeSet, DodgeChance);
	DOREPLIFETIME(UAurigaAttributeSet, ParryChance);
	DOREPLIFETIME(UAurigaAttributeSet, MoveSpeedModifier);
	DOREPLIFETIME(UAurigaAttributeSet, DamageToTake);
	DOREPLIFETIME(UAurigaAttributeSet, OutputDamageMultiplier);
	DOREPLIFETIME(UAurigaAttributeSet, ReceivedDamageMultiplier);
	DOREPLIFETIME(UAurigaAttributeSet, OutputHealingMultiplier);
	DOREPLIFETIME(UAurigaAttributeSet, ReceivedHealingMultiplier);
	DOREPLIFETIME(UAurigaAttributeSet, BaseAttackTime);
	DOREPLIFETIME(UAurigaAttributeSet, AttackRange);

}

void UAurigaAttributeSet::OnRep_Level()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Level, 0);
}

void UAurigaAttributeSet::OnRep_Ignis()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Ignis, 0);
}

void UAurigaAttributeSet::OnRep_IgnisModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, IgnisModifier, 0);
}

void UAurigaAttributeSet::OnRep_Aqua()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Aqua, 0);
}

void UAurigaAttributeSet::OnRep_AquaModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, AquaModifier, 0);
}

void UAurigaAttributeSet::OnRep_Voltaic()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Voltaic, 0);
}

void UAurigaAttributeSet::OnRep_VoltaicModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, VoltaicModifier, 0);
}

void UAurigaAttributeSet::OnRep_Terra()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Terra, 0);
}

void UAurigaAttributeSet::OnRep_TerraModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, TerraModifier, 0);
}

void UAurigaAttributeSet::OnRep_Lux()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Lux, 0);
}

void UAurigaAttributeSet::OnRep_LuxModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, LuxModifier, 0);
}

void UAurigaAttributeSet::OnRep_Void()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Void, 0);
}

void UAurigaAttributeSet::OnRep_VoidModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, VoidModifier, 0);
}

void UAurigaAttributeSet::OnRep_Gaia()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Gaia, 0);
}

void UAurigaAttributeSet::OnRep_GaiaModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, GaiaModifier, 0);
}

void UAurigaAttributeSet::OnRep_Aether()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Aether, 0);
}

void UAurigaAttributeSet::OnRep_AetherModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, AetherModifier, 0);
}

void UAurigaAttributeSet::OnRep_Psionic()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Psionic, 0);
}

void UAurigaAttributeSet::OnRep_PsionicModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, PsionicModifier, 0);
}

void UAurigaAttributeSet::OnRep_Ruin()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Ruin, 0);
}

void UAurigaAttributeSet::OnRep_RuinModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, RuinModifier, 0);
}

void UAurigaAttributeSet::OnRep_Vitality()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Vitality, 0);
}

void UAurigaAttributeSet::OnRep_CurrentHealth()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, CurrentHealth, 0);
}

void UAurigaAttributeSet::OnRep_MaxHealth()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, MaxHealth, 0);
}

void UAurigaAttributeSet::OnRep_CurrentZeal()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, CurrentZeal, 0);
}

void UAurigaAttributeSet::OnRep_MaxZeal()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, MaxZeal, 0);
}

void UAurigaAttributeSet::OnRep_CurrentValor()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, CurrentValor, 0);
}

void UAurigaAttributeSet::OnRep_MaxValor()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, MaxValor, 0);
}

void UAurigaAttributeSet::OnRep_Prowess()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Prowess, 0);
}

void UAurigaAttributeSet::OnRep_BaseAttackPower()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, BaseAttackPower, 0);
}

void UAurigaAttributeSet::OnRep_AttackPower()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, AttackPower, 0);
}

void UAurigaAttributeSet::OnRep_Sorcery()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Sorcery, 0);
}

void UAurigaAttributeSet::OnRep_MagicPower()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, MagicPower, 0);
}

void UAurigaAttributeSet::OnRep_Mysticism()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Mysticism, 0);
}

void UAurigaAttributeSet::OnRep_HealingPower()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, HealingPower, 0);
}

void UAurigaAttributeSet::OnRep_CriticalHitChance()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, CriticalHitChance, 0);
}

void UAurigaAttributeSet::OnRep_CritChance()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, CritChance, 0);
}

void UAurigaAttributeSet::OnRep_CriticalHitDamage()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, CriticalHitDamage, 0);
}

void UAurigaAttributeSet::OnRep_CritDamageModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, CritDamageModifier, 0);
}

void UAurigaAttributeSet::OnRep_Haste()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Haste, 0);
}

void UAurigaAttributeSet::OnRep_AttackSpeed()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, AttackSpeed, 0);
}

void UAurigaAttributeSet::OnRep_CastSpeed()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, CastSpeed, 0);
}

void UAurigaAttributeSet::OnRep_Instincts()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Instincts, 0);
}

void UAurigaAttributeSet::OnRep_InstinctsModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, InstinctsModifier, 0);
}

void UAurigaAttributeSet::OnRep_Synthesis()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Synthesis, 0);
}

void UAurigaAttributeSet::OnRep_SynthesisModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, SynthesisModifier, 0);
}

void UAurigaAttributeSet::OnRep_Armor()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Armor, 0);
}

void UAurigaAttributeSet::OnRep_ArmorModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, ArmorModifier, 0);
}

void UAurigaAttributeSet::OnRep_Barrier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, Barrier, 0);
}

void UAurigaAttributeSet::OnRep_BarrierModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, BarrierModifier, 0);
}

void UAurigaAttributeSet::OnRep_BlockChance()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, BlockChance, 0);
}

void UAurigaAttributeSet::OnRep_DodgeChance()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, DodgeChance, 0);
}

void UAurigaAttributeSet::OnRep_ParryChance()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, ParryChance, 0);
}

void UAurigaAttributeSet::OnRep_MoveSpeedModifier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, MoveSpeedModifier, 0);
}

void UAurigaAttributeSet::OnRep_DamageToTake()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, DamageToTake, 0);
}

void UAurigaAttributeSet::OnRep_OutputDamageMultiplier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, OutputDamageMultiplier, 0);
}

void UAurigaAttributeSet::OnRep_ReceivedDamageMultiplier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, ReceivedDamageMultiplier, 0);
}

void UAurigaAttributeSet::OnRep_OutputHealingMultiplier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, OutputHealingMultiplier, 0);
}

void UAurigaAttributeSet::OnRep_ReceivedHealingMultiplier()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, ReceivedHealingMultiplier, 0);
}

void UAurigaAttributeSet::OnRep_BaseAttackTime()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, BaseAttackTime, 0);
}

void UAurigaAttributeSet::OnRep_AttackRange()
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurigaAttributeSet, AttackRange, 0);
}

void UAurigaAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
	UAbilitySystemComponent* AbilityComp = GetOwningAbilitySystemComponent();
	const float CurrentMaxValue = MaxAttribute.GetCurrentValue();
	if (!FMath::IsNearlyEqual(CurrentMaxValue, NewMaxValue) && AbilityComp)
	{
		// Change current value to maintain the current Val / Max percent
		const float CurrentValue = AffectedAttribute.GetCurrentValue();
		float NewDelta = (CurrentMaxValue > 0.f) ? (CurrentValue * NewMaxValue / CurrentMaxValue) - CurrentValue : NewMaxValue;

		AbilityComp->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Additive, NewDelta);
	}
}

void UAurigaAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	// This is called whenever attributes change, so for max health/zeal/valor we want to scale the current totals to match
	if (Attribute == GetMaxHealthAttribute())
	{
		AdjustAttributeForMaxChange(CurrentHealth, MaxHealth, NewValue, GetCurrentHealthAttribute());
	}
	if (Attribute == GetMaxZealAttribute())
	{
		AdjustAttributeForMaxChange(CurrentZeal, MaxZeal, NewValue, GetCurrentZealAttribute());

	}
	if (Attribute == GetMaxValorAttribute())
	{
		AdjustAttributeForMaxChange(CurrentValor, MaxValor, NewValue, GetCurrentValorAttribute());
	}

}

void UAurigaAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* Source = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();

	// Compute the delta between old and new, if it is available
	float DeltaValue = 0;
	if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive)
	{
		// If this was additive, store the raw delta value to be passed along later
		DeltaValue = Data.EvaluatedData.Magnitude;
	}

	// Get the Target actor, which should be our owner
	AActor* TargetActor = nullptr;
	AController* TargetController = nullptr;
	AAurigaCharacterBase* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<AAurigaCharacterBase>(TargetActor);
	}

	// Perform Damage on Target
	if (Data.EvaluatedData.Attribute == GetDamageToTakeAttribute())
	{
		// Get the Source actor
		AActor* SourceActor = nullptr;
		AController* SourceController = nullptr;
		AAurigaCharacterBase* SourceCharacter = nullptr;
		if (Source && Source->AbilityActorInfo.IsValid() && Source->AbilityActorInfo->AvatarActor.IsValid())
		{
			SourceActor = Source->AbilityActorInfo->AvatarActor.Get();
			SourceController = Source->AbilityActorInfo->PlayerController.Get();
			if (SourceController == nullptr && SourceActor != nullptr)
			{
				if (APawn* Pawn = Cast<APawn>(SourceActor))
				{
					SourceController = Pawn->GetController();
				}
			}

			// Use the controller to find the source pawn
			if (SourceController)
			{
				SourceCharacter = Cast<AAurigaCharacterBase>(SourceController->GetPawn());
			}
			else
			{
				SourceCharacter = Cast<AAurigaCharacterBase>(SourceActor);
			}

			// Set the causer actor based on context if it's set
			if (Context.GetEffectCauser())
			{
				SourceActor = Context.GetEffectCauser();
			}
		}

		// Store a local copy of the amount of damage done and clear the damage attribute
		const float LocalDamageDone = GetDamageToTake();
		SetDamageToTake(0.f);

		//Apply Damage
		if (LocalDamageDone > 0)
		{
			// Apply the health change and then clamp it
			const float OldHealth = GetCurrentHealth();
			SetCurrentHealth(FMath::Clamp(OldHealth - LocalDamageDone, 0.0f, GetMaxHealth()));

			//if (TargetCharacter)
			//{
				// This is proper damage
				//TargetCharacter->HandleDamage(LocalDamageDone, SourceTags, SourceCharacter, SourceActor);

				// Call for all health changes
				//TargetCharacter->HandleHealthChanged(-LocalDamageDone, SourceTags);
			//}
		}
		
		//Apply Healing
		if (LocalDamageDone < 0)
		{
			// Apply the health change and then clamp it
			const float OldHealth = GetCurrentHealth();
			SetCurrentHealth(FMath::Clamp(OldHealth - LocalDamageDone, 0.0f, GetMaxHealth()));

			//if (TargetCharacter)
			//{
				// This is proper damage
				//TargetCharacter->HandleDamage(LocalDamageDone, SourceTags, SourceCharacter, SourceActor);

				// Call for all health changes
				//TargetCharacter->HandleHealthChanged(-LocalDamageDone, SourceTags);
			//}
		}

	}


	//Clamp Health
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, CurrentHealth)))
	{
		SetCurrentHealth(FMath::Clamp(CurrentHealth.GetCurrentValue(), 0.0f, MaxHealth.GetCurrentValue()));
	}

	//Clamp Zeal
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, CurrentZeal)))
	{
		SetCurrentZeal(FMath::Clamp(CurrentZeal.GetCurrentValue(), 0.0f, MaxZeal.GetCurrentValue()));
	}

	//Clamp Valor
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, CurrentValor)))
	{
		SetCurrentValor(FMath::Clamp(CurrentValor.GetCurrentValue(), 0.0f, MaxValor.GetCurrentValue()));
	}

	//Updates BaseAttackPower to equal Prowess or Sorcery, whichever is higher.
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, Prowess)) ||
		Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, Sorcery)))
	{
		if (Prowess.GetCurrentValue() >= Sorcery.GetCurrentValue())
		{
			SetBaseAttackPower(Prowess.GetCurrentValue()); 
		
		}
		else if (Sorcery.GetCurrentValue() > Prowess.GetCurrentValue())
		{
			SetBaseAttackPower(Sorcery.GetCurrentValue());
		}
	}

	//If a derived attribute needs updated, calls the event to calculate derived attributes.
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, CriticalHitChance)) || 
		Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, CriticalHitDamage)) || 
		Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, Haste)) || 
		Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, Instincts)) || 
		Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, Synthesis)) || 
		Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, Armor)) || 
		Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAurigaAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAurigaAttributeSet, Barrier))
		)
	{
		AActor* Actor;
		AAurigaCharacterBase* Character;

		Actor = this->GetOwningActor();
		Character = Cast<AAurigaCharacterBase>(Actor);
		Character->BP_OnAttributeModifierUpdate();

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Modifiers are being called."));
	}
	
}
