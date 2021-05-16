// Copyright 2019 Malebisse


#include "SorceryDamageCalculation.h"
#include "AurigaAttributeSet.h"
#include "Engine.h"
#include "AbilitySystemComponent.h"

//*** Required
struct SorceryDamageStatics
{
	//*** These are required in order to capture the stats from the source and target. The stat name must match the AttributeSet.
	DECLARE_ATTRIBUTE_CAPTUREDEF(Sorcery);
	DECLARE_ATTRIBUTE_CAPTUREDEF(BarrierModifier);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageToTake);
	DECLARE_ATTRIBUTE_CAPTUREDEF(ReceivedDamageMultiplier);
	DECLARE_ATTRIBUTE_CAPTUREDEF(OutputDamageMultiplier);

	//*** Required
	SorceryDamageStatics()
	{
		//*** These are required in order to capture the stats from the source and target. The Backing Capture Definition in the GE must be set to the output, which should always be Damage.
		//*** Syntax: (Name of the AttributeSet class, stat name from AttributeSet, from source or target, snapshot bool)

		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, Sorcery, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, BarrierModifier, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, DamageToTake, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, OutputDamageMultiplier, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAurigaAttributeSet, ReceivedDamageMultiplier, Target, true);
	}
};

//*** Required
static const SorceryDamageStatics& DamageStatics()
{
	static SorceryDamageStatics DmgStatics;
	return DmgStatics;
}

//** Required
USorceryDamageCalculation::USorceryDamageCalculation()
{
	//*** Required to capture the attributes from the struct above.
	RelevantAttributesToCapture.Add(DamageStatics().SorceryDef);
	RelevantAttributesToCapture.Add(DamageStatics().BarrierModifierDef);
	RelevantAttributesToCapture.Add(DamageStatics().DamageToTakeDef);
	RelevantAttributesToCapture.Add(DamageStatics().OutputDamageMultiplierDef);
	RelevantAttributesToCapture.Add(DamageStatics().ReceivedDamageMultiplierDef);
}

//*** Required - This is an override declared in the header file.
void USorceryDamageCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
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

	float sorcery = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().SorceryDef, EvaluationParameters, sorcery);

	float barrierModifer = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().BarrierModifierDef, EvaluationParameters, barrierModifer);

	float outputmultiplier = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().OutputDamageMultiplierDef, EvaluationParameters, outputmultiplier);

	float receivedmultiplier = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ReceivedDamageMultiplierDef, EvaluationParameters, receivedmultiplier);

	float DamageDone = (outputmultiplier * receivedmultiplier) * (sorcery * (1 - barrierModifer));

	//*** Debug message
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("DamageDone: %f = (%f * (%f * (1 - %f)))"), DamageDone, damage , sorcery, barrierModifer));

	if (DamageDone > 0.f)
	{
		//*** This is the code to output the damage. In the GE, setting the Modifier Magnitude to Scalable Float 1.0 will use this raw output.
		//*** AttributeSet.cpp has code in PostGameplayEffectExecute where the damage is received and health reduced.
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageToTakeProperty, EGameplayModOp::Additive, DamageDone));
	}
}