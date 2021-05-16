// Copyright 2019 Malebisse


#include "AurigaAbilitySystemComponent.h"
#include "AurigaCharacterBase.h"
#include "AurigaGameplayAbility.h"
#include "AbilitySystemGlobals.h"

UAurigaAbilitySystemComponent::UAurigaAbilitySystemComponent() {}

UAurigaAbilitySystemComponent* UAurigaAbilitySystemComponent::GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent)
{
	return Cast<UAurigaAbilitySystemComponent>(UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor, LookForComponent));
}

void UAurigaAbilitySystemComponent::AddGameplayTagToComponent(const FGameplayTag & Tag)
{
	
	SetTagMapCount(Tag, 1);

}

void UAurigaAbilitySystemComponent::RemoveGameplayTagFromComponent(const FGameplayTag & Tag)
{
	SetTagMapCount(Tag, 0);

}

