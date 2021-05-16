// Copyright 2019 Malebisse


#include "AurigaGameplayAbility.h"
#include "AurigaAbilitySystemComponent.h"
#include "AurigaAbilityTypes.h"
#include "AurigaCharacterBase.h"

UAurigaGameplayAbility::UAurigaGameplayAbility() 
{
}

//Insert functions below

FAurigaGameplayAbilityInfo UAurigaGameplayAbility::GetAbilityInfo()
{
	UGameplayEffect* CooldownEffect = GetCooldownGameplayEffect();
	UGameplayEffect* CostEffect = GetCostGameplayEffect();

	
	if (CooldownEffect && CostEffect)
	{
		float CooldownDuration = 0;
		float CostAmount = 0;
		EAbilityCostType CostType;

		CooldownEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(1, CooldownDuration);

		if (CostEffect->Modifiers.Num() > 0)
		{

			FGameplayModifierInfo EffectInfo = CostEffect->Modifiers[0];
			EffectInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(1, CostAmount);
			FGameplayAttribute CostAttribute = EffectInfo.Attribute;
			FString AttributeName = CostAttribute.AttributeName;
			if (AttributeName == "CurrentHealth")
			{
				CostType = EAbilityCostType::Health;
			}
			else if (AttributeName == "CurrentZeal")
			{
				CostType = EAbilityCostType::Zeal;
			}
			else if (AttributeName == "CurrentValor")
			{
				CostType = EAbilityCostType::Valor;
			}
		}

		return FAurigaGameplayAbilityInfo(CooldownDuration, CostAmount, CostType, GetClass());
	}

	return FAurigaGameplayAbilityInfo();

	
}



