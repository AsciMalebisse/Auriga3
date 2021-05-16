// Copyright 2019 Malebisse


#include "AurigaAbilityTypes.h"

FAurigaGameplayAbilityInfo::FAurigaGameplayAbilityInfo()
	:CooldownDuration(0),
	Cost(0),
	CostType(EAbilityCostType::Zeal),
	AbilityClass(nullptr)
{
}

FAurigaGameplayAbilityInfo::FAurigaGameplayAbilityInfo(float InCooldownDuration, float InCost, EAbilityCostType InCostType, TSubclassOf<UAurigaGameplayAbility> InAbilityClass)
	:CooldownDuration(InCooldownDuration),
	Cost(InCost),
	CostType(InCostType),
	AbilityClass(InAbilityClass)
{
}
