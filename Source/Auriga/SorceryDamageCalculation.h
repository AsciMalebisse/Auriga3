// Copyright 2019 Malebisse

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "SorceryDamageCalculation.generated.h"

/**
 * 
 */
UCLASS()
class AURIGA_API USorceryDamageCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	// Constructor and overrides
	USorceryDamageCalculation();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;


};
