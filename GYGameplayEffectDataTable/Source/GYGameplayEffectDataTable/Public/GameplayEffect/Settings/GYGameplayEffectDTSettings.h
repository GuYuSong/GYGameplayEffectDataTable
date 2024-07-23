// Fill out your copyright notice in the Description page of Project Settings.

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

	UPROPERTY(config, EditAnywhere, meta = (AllowedClasses = "/Script/Engine.DataTable"))
		FSoftObjectPath GameplayEffectsDT;

	UPROPERTY(config, BlueprintReadWrite, EditAnywhere)
		TSubclassOf<UGYGameplayEffect> GYGameplayEffectClass = UGYGameplayEffect::StaticClass();
	
	virtual FName GetCategoryName() const override;
};
