// Copyright 2019 Malebisse

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ProwessDamageCalculation.generated.h"

/**
 * 
 */
UCLASS()
class AURIGA_API UProwessDamageCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	// Constructor and overrides
	UProwessDamageCalculation();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;


};
