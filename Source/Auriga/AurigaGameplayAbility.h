// Copyright 2019 Malebisse

#pragma once

#include "Auriga.h"
#include "GameplayAbility.h"
#include "AurigaAbilityTypes.h"
#include "AurigaGameplayAbility.generated.h"

/**
 * Game specific subclass of GameplayAbility
 */

UENUM(BlueprintType)
enum class EAbilityTargetTypeEnum : uint8
{
	TT_Self     UMETA(DisplayName = "Self"),
	TT_Allies   UMETA(DisplayName = "Allies"),
	TT_Any      UMETA(DisplayName = "Any"),
	TT_Enemies  UMETA(DisplayName = "Enemies"),
};



UCLASS()
class AURIGA_API UAurigaGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	//Constructor and overrides
	UAurigaGameplayAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	EAbilityTargetTypeEnum AbilityTargetTypeEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	UTexture2D* Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	float CastRange;

	UFUNCTION(BlueprintCallable, Category = "AbilityInfo")
	FAurigaGameplayAbilityInfo GetAbilityInfo();

	UFUNCTION(BlueprintImplementableEvent, Category = "Valor", meta = (DisplayName = "ApplyValorGain"))
	void BP_ApplyValorGain();

};
