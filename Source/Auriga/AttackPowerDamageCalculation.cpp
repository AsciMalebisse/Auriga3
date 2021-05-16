// Copyright 2019 Malebisse


#include "AttackPowerDamageCalculation.h"

#include "AurigaAttributeSet.h"
#include "Engine.h"
#include "AbilitySystemComponent.h"

//*** Required
struct AttackPowerDamageStatics
{
	//*** These are required in order to capture the stats from the source and target. The stat name must match the AttributeSet.
	DECLARE_ATTRIBUTE_CAPTUREDEF(Prowess);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Sorcery);
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(ArmorModifier);
	DECLARE_ATTRIBUTE_CAPTUREDEF(BarrierModifier);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageToTake);
	DECLARE_ATTRIBUTE_CAPTUREDEF(ReceivedDamageMultiplier);
	DECLARE_ATTRIBUTE_CAPTUREDEF(OutputDamageMultiplier);

	//*** Required
	AttackPowerDamageStatics()
	{
		//*** These are required in order to capture the stats from the source and target. The Backing Capture Definition in the GE must be set to the output, which should always be Damage.
		//*** Syntax: (Name of the AttributeSet class, stat name from AttributeSet, from source or target, snapshot bool)

		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, Prowess, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, Sorcery, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, AttackPower, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, ArmorModifier, Target, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, BarrierModifier, Target, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, DamageToTake, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, OutputDamageMultiplier, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, ReceivedDamageMultiplier, Target, true);
	}
};

//*** Required
static const AttackPowerDamageStatics& DamageStatics()
{
	static AttackPowerDamageStatics DmgStatics;
	return DmgStatics;
}

//** Required
UAttackPowerDamageCalculation::UAttackPowerDamageCalculation()
{
	//*** Required to capture the attributes from the struct above.
	RelevantAttributesToCapture.Add(DamageStatics().ProwessDef);
	RelevantAttributesToCapture.Add(DamageStatics().SorceryDef);
	RelevantAttributesToCapture.Add(DamageStatics().AttackPowerDef);
	RelevantAttributesToCapture.Add(DamageStatics().ArmorModifierDef);
	RelevantAttributesToCapture.Add(DamageStatics().BarrierModifierDef);
	RelevantAttributesToCapture.Add(DamageStatics().DamageToTakeDef);
	RelevantAttributesToCapture.Add(DamageStatics().OutputDamageMultiplierDef);
	RelevantAttributesToCapture.Add(DamageStatics().ReceivedDamageMultiplierDef);
}

//*** Required - This is an override declared in the header file.
void UAttackPowerDamageCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	////////////////////////////////////////
	//*** BEGIN REQUIRED FOUNDATION CODE
	////////////////////////////////////////

	UAbilitySystemComponent* TargetAbilitySystemComponent = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceAbilitySystemComponent = ExecutionParams.GetSourceAbilitySystemComponent();


	AActor* SourceActor = SourceAbilitySystemComponent ? SourceAbilitySystemComponent->AvatarActor : nullptr;
	AActor* TargetActor = TargetAbilitySystemComponent ? TargetAbilitySystemComponent->AvatarActor : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	// Gather the tags from the source and target as that can affect which buffs should be used
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	////////////////////////////////////////
	//*** END REQUIRED FOUNDATION CODE
	////////////////////////////////////////

	//*** The rest of the code below is the actual damage calculation that should be modified.
	float prowess = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().AttackPowerDef, EvaluationParameters, prowess);

	float sorcery = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().AttackPowerDef, EvaluationParameters, sorcery);

	float attackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().AttackPowerDef, EvaluationParameters, attackPower);

	float armorModifier = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorModifierDef, EvaluationParameters, armorModifier);

	float barrierModifier = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorModifierDef, EvaluationParameters, barrierModifier);

	float outputmultiplier = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().OutputDamageMultiplierDef, EvaluationParameters, outputmultiplier);

	float receivedmultiplier = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ReceivedDamageMultiplierDef, EvaluationParameters, receivedmultiplier);

	float DamageDone = 0.f;

	if (prowess >= sorcery)
	{
		DamageDone = (outputmultiplier * receivedmultiplier) * (prowess * (1 - armorModifier));
	}
	else
	{
		DamageDone = (outputmultiplier * receivedmultiplier) * (sorcery * (1 - barrierModifier));
	}

	//*** Debug message
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("DamageDone: %f = (%f * (%f * (1 - %f)))"), DamageDone, damage, AttackPower, armorModifier));

	if (DamageDone > 0.f)
	{
		//*** This is the code to output the damage. In the GE, setting the Modifier Magnitude Scalable Float to 1.0 will use this raw output.
		//*** AttributeSet.cpp has code in PostGameplayEffectExecute where the damage is received and health reduced.
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageToTakeProperty, EGameplayModOp::Additive, DamageDone));
	}
}