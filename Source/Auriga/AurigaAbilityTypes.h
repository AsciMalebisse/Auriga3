// Copyright 2019 Malebisse

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AurigaAbilityTypes.generated.h"

class UAurigaGameplayAbility;

/**
 * 
 */

UENUM(BlueprintType)
enum class EAbilityCostType : uint8
{
	Health,
	Zeal,
	Valor

};

USTRUCT(BlueprintType)
struct FAurigaGameplayAbilityInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	float CooldownDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	float Cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	EAbilityCostType CostType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	TSubclassOf<UAurigaGameplayAbility> AbilityClass;

	FAurigaGameplayAbilityInfo();
	FAurigaGameplayAbilityInfo(float InCooldownDuration, float InCost, EAbilityCostType InCostType, TSubclassOf<UAurigaGameplayAbility> InAbilityClass);



};

