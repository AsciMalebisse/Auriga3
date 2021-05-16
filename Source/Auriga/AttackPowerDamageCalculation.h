// Copyright 2019 Malebisse

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "AttackPowerDamageCalculation.generated.h"

/**
 * 
 */
UCLASS()
class AURIGA_API UAttackPowerDamageCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	// Constructor and overrides
	UAttackPowerDamageCalculation();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

};
