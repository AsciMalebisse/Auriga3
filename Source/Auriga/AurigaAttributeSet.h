// Copyright 2019 Malebisse

#pragma once

#include "Auriga.h"
#include "AttributeSet.h"
#include "AurigaGameplayEffect.h"
#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"
#include "AurigaAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/** This holds all of the attributes used by abilities, it instantiates a copy of this on every character */
UCLASS()
class AURIGA_API UAurigaAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	//Constructor and overrides
	UAurigaAttributeSet();
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Character Level */
	UPROPERTY(BlueprintReadOnly, Category = "Level", ReplicatedUsing = OnRep_Level)
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Level)

	///////////////////////////////
	// Elements
	///////////////////////////////

	/** Ignis Element Stat */
	UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_Ignis)
	FGameplayAttributeData Ignis;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Ignis)

		UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_IgnisModifier)
		FGameplayAttributeData IgnisModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, IgnisModifier)

	/** Aqua Element Stat */
	UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_Aqua)
	FGameplayAttributeData Aqua;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Aqua)

		UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_AquaModifier)
		FGameplayAttributeData AquaModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, AquaModifier)

	/** Voltaic Element Stat */
	UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_Voltaic)
	FGameplayAttributeData Voltaic;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Voltaic)

		UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_VoltaicModifier)
		FGameplayAttributeData VoltaicModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, VoltaicModifier)

	/** Terra Element Stat */
	UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_Terra)
	FGameplayAttributeData Terra;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Terra)

		UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_TerraModifier)
		FGameplayAttributeData TerraModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, TerraModifier)

	/** Lux Element Stat */
	UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_Lux)
	FGameplayAttributeData Lux;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Lux)

		UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_LuxModifier)
		FGameplayAttributeData LuxModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, LuxModifier)

	/** Void Element Stat */
	UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_Void)
	FGameplayAttributeData Void;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Void)

		UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_VoidModifier)
		FGameplayAttributeData VoidModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, VoidModifier)

	/** Gaia Element Stat */
	UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_Gaia)
	FGameplayAttributeData Gaia;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Gaia)

		UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_GaiaModifier)
		FGameplayAttributeData GaiaModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, GaiaModifier)

	/** Aether Element Stat */
	UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_Aether)
	FGameplayAttributeData Aether;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Aether)

		UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_AetherModifier)
		FGameplayAttributeData AetherModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, AetherModifier)

	/** Psionic Element Stat */
	UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_Psionic)
	FGameplayAttributeData Psionic;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Psionic)

		UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_PsionicModifier)
		FGameplayAttributeData PsionicModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, PsionicModifier)

	/** Ruin Element Stat */
	UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_Ruin)
	FGameplayAttributeData Ruin;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Ruin)

		UPROPERTY(BlueprintReadOnly, Category = "Element", ReplicatedUsing = OnRep_RuinModifier)
		FGameplayAttributeData RuinModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, RuinModifier)

	///////////////////////////////
	// Attributes
	///////////////////////////////

	/** Vitality Stat used to calculate Max Health */
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_Vitality)
	FGameplayAttributeData Vitality;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Vitality)

	/** Current Health of the character */
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_CurrentHealth)
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, CurrentHealth)

	/** Max Health calculated from Vitality */
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, MaxHealth)

	/** Current Zeal of the character */
	UPROPERTY(BlueprintReadOnly, Category = "Zeal", ReplicatedUsing = OnRep_CurrentZeal)
	FGameplayAttributeData CurrentZeal;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, CurrentZeal)

	/** Max Zeal of the character */
	UPROPERTY(BlueprintReadOnly, Category = "Zeal", ReplicatedUsing = OnRep_MaxZeal)
	FGameplayAttributeData MaxZeal;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, MaxZeal)

	/** Current Valor of the character */
	UPROPERTY(BlueprintReadOnly, Category = "Valor", ReplicatedUsing = OnRep_CurrentValor)
	FGameplayAttributeData CurrentValor;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, CurrentValor)

	/** Max Valor of the character */
	UPROPERTY(BlueprintReadOnly, Category = "Valor", ReplicatedUsing = OnRep_MaxValor)
	FGameplayAttributeData MaxValor;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, MaxValor)

	/** Prowess Stat used to calculate Physical Power */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Prowess)
	FGameplayAttributeData Prowess;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Prowess)

	/** Base Attack Power based on Prowess/Sorcery, whichever is higher */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_BaseAttackPower)
	FGameplayAttributeData BaseAttackPower;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, BaseAttackPower)

	/** Attack Power Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_AttackPower)
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, AttackPower)

	/** Sorcery Stat used to calculate Magic Power */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Sorcery)
	FGameplayAttributeData Sorcery;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Sorcery)

	/** Magic Power Stat used used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_MagicPower)
	FGameplayAttributeData MagicPower;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, MagicPower)

	/** Mysticism Stat used to calculate Healing Power */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Mysticism)
	FGameplayAttributeData Mysticism;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Mysticism)

	/** Healing Power Stat used used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_HealingPower)
	FGameplayAttributeData HealingPower;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, HealingPower)

	/** Critical Hit Chance Stat used to calculate Crit Chance */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_CriticalHitChance)
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, CriticalHitChance)

	/** Crit Chance Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_CritChance)
	FGameplayAttributeData CritChance;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, CritChance)

	/** Critical Hit Damage Stat used to calculate Crit Damage Modifier */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_CriticalHitDamage)
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, CriticalHitDamage)

	/** Crit Damage Modifier Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_CritDamageModifier)
	FGameplayAttributeData CritDamageModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, CritDamageModifier)

	/** Haste Stat used to calculate Attack Speed and Cast Speed */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Haste)
	FGameplayAttributeData Haste;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Haste)

	/** Attack Soeed Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_AttackSpeed)
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, AttackSpeed)

	/** Cast Speed Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_CastSpeed)
	FGameplayAttributeData CastSpeed;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, CastSpeed)

	/** Instincts Stat used to calculate Instincts Modifier */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Instincts)
	FGameplayAttributeData Instincts;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Instincts)

	/** Instincts Modifier Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_InstinctsModifier)
	FGameplayAttributeData InstinctsModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, InstinctsModifier)

	/** Synthesis Stat used to calculate Synthesis Modifier */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Synthesis)
	FGameplayAttributeData Synthesis;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Synthesis)

	/** Synthesis Modifier Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_SynthesisModifier)
	FGameplayAttributeData SynthesisModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, SynthesisModifier)

	/** Armor Stat used to calculate Armor Modifier */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Armor)
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Armor)

	/** Armor Modifier Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_ArmorModifier)
	FGameplayAttributeData ArmorModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, ArmorModifier)

	/** Barrier Stat used to calculate Barrier Modifier */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Barrier)
	FGameplayAttributeData Barrier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, Barrier)

	/** Barrier Modifier Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_BarrierModifier)
	FGameplayAttributeData BarrierModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, BarrierModifier)

	/** Block Chance Modifier Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_BlockChance)
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, BlockChance)

	/** Dodge Chance Modifier Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_DodgeChance)
	FGameplayAttributeData DodgeChance;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, DodgeChance)

	/** Parry Chance Modifier Stat used for Damage Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_ParryChance)
	FGameplayAttributeData ParryChance;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, ParryChance)

	/** Move Speed Modifier Stat used for Movement Calculations */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_MoveSpeedModifier)
	FGameplayAttributeData MoveSpeedModifier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, MoveSpeedModifier)

	/** Damage is a 'temporary' attribute used by the DamageExecution to calculate final damage, which then turns into -Health */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_DamageToTake)
	FGameplayAttributeData DamageToTake;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, DamageToTake)

	/** Output Damage Multiplier is used to multiply output damage such as with charms/hexes that modify percentage of damage done */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_OutputDamageMultiplier)
	FGameplayAttributeData OutputDamageMultiplier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, OutputDamageMultiplier)

	/** Recieved Damage Multiplier is used to multiply incoming damage such as with charms/hexes that modify percentage of damage received */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_ReceivedDamageMultiplier)
	FGameplayAttributeData ReceivedDamageMultiplier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, ReceivedDamageMultiplier)

	/** Output Healing Multiplier is used to multiply outgoing healing such as with charms/hexes that modify percentage of healing done */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_OutputHealingMultiplier)
	FGameplayAttributeData OutputHealingMultiplier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, OutputHealingMultiplier)

	/** Recieved Healing Multiplier is used to multiply incoming healing such as with charms/hexes that modify percentage of healing received */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_ReceivedHealingMultiplier)
	FGameplayAttributeData ReceivedHealingMultiplier;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, ReceivedHealingMultiplier)

	/** Base Attack Time is based on the weapon type equipped */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_BaseAttackTime)
	FGameplayAttributeData BaseAttackTime;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, BaseAttackTime)

	/** Attack Range is based on the weapon type equipped */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_AttackRange)
	FGameplayAttributeData AttackRange;
	ATTRIBUTE_ACCESSORS(UAurigaAttributeSet, AttackRange)

protected:

	/** Helper function to proportionally adjust the value of an attribute when it's associated max attribute changes. (i.e. When MaxHealth increases, Health increases by an amount that maintains the same percentage as before) */
	void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty);

	// These OnRep functions exist to make sure that the ability system internal representations are synchronized properly during replication
	UFUNCTION()
	virtual void OnRep_Level();
	
	UFUNCTION()
	virtual void OnRep_Ignis();

	UFUNCTION()
	virtual void OnRep_IgnisModifier();

	UFUNCTION()
	virtual void OnRep_Aqua();

	UFUNCTION()
		virtual void OnRep_AquaModifier();

	UFUNCTION()
	virtual void OnRep_Voltaic();

	UFUNCTION()
		virtual void OnRep_VoltaicModifier();

	UFUNCTION()
	virtual void OnRep_Terra();

	UFUNCTION()
		virtual void OnRep_TerraModifier();

	UFUNCTION()
	virtual void OnRep_Lux();

	UFUNCTION()
		virtual void OnRep_LuxModifier();

	UFUNCTION()
	virtual void OnRep_Void();

	UFUNCTION()
		virtual void OnRep_VoidModifier();

	UFUNCTION()
	virtual void OnRep_Gaia();

	UFUNCTION()
		virtual void OnRep_GaiaModifier();

	UFUNCTION()
	virtual void OnRep_Aether();

	UFUNCTION()
		virtual void OnRep_AetherModifier();

	UFUNCTION()
	virtual void OnRep_Psionic();

	UFUNCTION()
		virtual void OnRep_PsionicModifier();

	UFUNCTION()
	virtual void OnRep_Ruin();

	UFUNCTION()
		virtual void OnRep_RuinModifier();

	UFUNCTION()
	virtual void OnRep_Vitality();

	UFUNCTION()
	virtual void OnRep_CurrentHealth();

	UFUNCTION()
	virtual void OnRep_MaxHealth();

	UFUNCTION()
	virtual void OnRep_CurrentZeal();

	UFUNCTION()
	virtual void OnRep_MaxZeal();

	UFUNCTION()
	virtual void OnRep_CurrentValor();

	UFUNCTION()
	virtual void OnRep_MaxValor();

	UFUNCTION()
	virtual void OnRep_Prowess();

	UFUNCTION()
	virtual void OnRep_BaseAttackPower();

	UFUNCTION()
	virtual void OnRep_AttackPower();

	UFUNCTION()
	virtual void OnRep_Sorcery();

	UFUNCTION()
	virtual void OnRep_MagicPower();

	UFUNCTION()
	virtual void OnRep_Mysticism();

	UFUNCTION()
	virtual void OnRep_HealingPower();

	UFUNCTION()
	virtual void OnRep_CriticalHitChance();

	UFUNCTION()
	virtual void OnRep_CritChance();

	UFUNCTION()
	virtual void OnRep_CriticalHitDamage();

	UFUNCTION()
	virtual void OnRep_CritDamageModifier();

	UFUNCTION()
	virtual void OnRep_Haste();

	UFUNCTION()
	virtual void OnRep_AttackSpeed();

	UFUNCTION()
	virtual void OnRep_CastSpeed();

	UFUNCTION()
	virtual void OnRep_Instincts();

	UFUNCTION()
	virtual void OnRep_InstinctsModifier();

	UFUNCTION()
	virtual void OnRep_Synthesis();

	UFUNCTION()
	virtual void OnRep_SynthesisModifier();

	UFUNCTION()
	virtual void OnRep_Armor();

	UFUNCTION()
	virtual void OnRep_ArmorModifier();

	UFUNCTION()
	virtual void OnRep_Barrier();

	UFUNCTION()
	virtual void OnRep_BarrierModifier();

	UFUNCTION()
	virtual void OnRep_BlockChance();

	UFUNCTION()
	virtual void OnRep_DodgeChance();

	UFUNCTION()
	virtual void OnRep_ParryChance();

	UFUNCTION()
	virtual void OnRep_MoveSpeedModifier();

	UFUNCTION()
	virtual void OnRep_DamageToTake();

	UFUNCTION()
	virtual void OnRep_OutputDamageMultiplier();

	UFUNCTION()
	virtual void OnRep_ReceivedDamageMultiplier();

	UFUNCTION()
	virtual void OnRep_OutputHealingMultiplier();

	UFUNCTION()
	virtual void OnRep_ReceivedHealingMultiplier();

	UFUNCTION()
	virtual void OnRep_BaseAttackTime();

	UFUNCTION()
	virtual void OnRep_AttackRange();


};
