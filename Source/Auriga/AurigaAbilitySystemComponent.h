// Copyright 2019 Malebisse

#pragma once

#include "Auriga.h"
#include "AbilitySystemComponent.h"
#include "AurigaAbilitySystemComponent.generated.h"

class UAurigaAbilitySystemComponent;

/**
 * Game specific subclass of AbilitySystemComponent
 */
UCLASS()
class AURIGA_API UAurigaAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	//Constructor and overrides
	UAurigaAbilitySystemComponent();

	//Version of function in AbilitySystemGlobals that returns correct type
	static UAurigaAbilitySystemComponent* GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent = false);

	UFUNCTION(BlueprintCallable)
	void AddGameplayTagToComponent(const FGameplayTag& Tag);

	UFUNCTION(BlueprintCallable)
	void RemoveGameplayTagFromComponent(const FGameplayTag& Tag);

};
