// Copyright 2024 GY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GYGameplayEffect.h"
#include "GYGameplayEffectDTSettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig)
class GYGAMEPLAYEFFECTDATATABLE_API UGYGameplayEffectDTSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:

	UPROPERTY(config, EditAnywhere, meta = (AllowedClasses = "/Script/Engine.DataTable"), Category = "DataTable")
		FSoftObjectPath GameplayEffectsDT;

	UPROPERTY(config, BlueprintReadWrite, EditAnywhere, Category = "GameplayEffectClass")
		TSubclassOf<UGYGameplayEffect> GYGameplayEffectClass = UGYGameplayEffect::StaticClass();
	
	virtual FName GetCategoryName() const override;
};
