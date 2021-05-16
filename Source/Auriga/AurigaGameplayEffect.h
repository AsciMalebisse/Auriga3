// Copyright 2019 Malebisse

#pragma once

#include "CoreMinimal.h"
#include "Auriga.h"
#include "AurigaAttributeSet.h"
#include "GameplayEffect.h"
#include "AurigaGameplayEffect.generated.h"

/**
 *  Game specific subclass of GameplayEffect
 */

UENUM(BlueprintType)
enum class EEquipmentType : uint8
{
	ET_None0       UMETA(DisplayName = "NONE"),
	ET_Head1       UMETA(DisplayName = "Head"),
	ET_Neck2       UMETA(DisplayName = "Neck"),
	ET_Shoulders3  UMETA(DisplayName = "Shoulders"),
	ET_Back4	      UMETA(DisplayName = "Back"),
	ET_Chest5      UMETA(DisplayName = "Chest"),
	ET_Wrists6     UMETA(DisplayName = "Wrists"),
	ET_Hands7      UMETA(DisplayName = "Hands"),
	ET_Waist8      UMETA(DisplayName = "Waist"),
	ET_Legs9       UMETA(DisplayName = "Legs"),
	ET_Feet10       UMETA(DisplayName = "Feet"),
	ET_Ring11       UMETA(DisplayName = "Ring"),
	ET_Curio12	    UMETA(DisplayName = "Curio"),
	ET_Weapon13	    UMETA(DisplayName = "Weapon"),
	ET_Offhand13	UMETA(DisplayName = "Offhand")

};


UCLASS()
class AURIGA_API UAurigaGameplayEffect : public UGameplayEffect
{
	GENERATED_BODY()
	
public:
	//Constructor and overrides
	UAurigaGameplayEffect();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		UTexture2D* Image;

};
