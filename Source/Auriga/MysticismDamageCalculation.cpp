// Copyright 2019 Malebisse


#include "MysticismDamageCalculation.h"

#include "AurigaAttributeSet.h"
#include "Engine.h"
#include "AbilitySystemComponent.h"

//*** Required
struct MysticismDamageStatics
{
	//*** These are required in order to capture the stats from the source and target. The stat name must match the AttributeSet.
	DECLARE_ATTRIBUTE_CAPTUREDEF(Mysticism);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageToTake);
	DECLARE_ATTRIBUTE_CAPTUREDEF(OutputHealingMultiplier);
	DECLARE_ATTRIBUTE_CAPTUREDEF(ReceivedHealingMultiplier);

	//*** Required
	MysticismDamageStatics()
	{
		//*** These are required in order to capture the stats from the source and target. The Backing Capture Definition in the GE must be set to the output, which should always be Damage.
		//*** Syntax: (Name of the AttributeSet class, stat name from AttributeSet, from source or target, snapshot bool)

		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, Mysticism, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, DamageToTake, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, OutputHealingMultiplier, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, ReceivedHealingMultiplier, Target, true);
	}
};

//*** Required
static const MysticismDamageStatics& DamageStatics()
{
	static MysticismDamageStatics DmgStatics;
	return DmgStatics;
}

//** Required
UMysticismDamageCalculation::UMysticismDamageCalculation()
{
	//*** Required to capture the attributes from the struct above.
	RelevantAttributesToCapture.Add(DamageStatics().MysticismDef);
	RelevantAttributesToCapture.Add(DamageStatics().DamageToTakeDef);
	RelevantAttributesToCapture.Add(DamageStatics().OutputHealingMultiplierDef);
	RelevantAttributesToCapture.Add(DamageStatics().ReceivedHealingMultiplierDef);
}

//*** Required - This is an override declared in the header file.
void UMysticismDamageCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
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

	float mysticism = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().MysticismDef, EvaluationParameters, mysticism);

	float outputmultiplier = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().OutputHealingMultiplierDef, EvaluationParameters, outputmultiplier);

	float receivedmultiplier = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ReceivedHealingMultiplierDef, EvaluationParameters, receivedmultiplier);

	float DamageDone = -((outputmultiplier * receivedmultiplier) * (mysticism));

	//*** Debug message
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("DamageDone: %f = (%f * (%f * (1 - %f)))"), DamageDone, outputmultiplier, receivedmultiplier, mysticism));

	if (DamageDone < 0.f)
	{
		//*** This is the code to output the damage. In the GE, set the modifier to be the attribute to receive additional changes.
		//*** AttributeSet.cpp has code in PostGameplayEffectExecute where the damage is received and health reduced.
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageToTakeProperty, EGameplayModOp::Additive, DamageDone));
	}
}