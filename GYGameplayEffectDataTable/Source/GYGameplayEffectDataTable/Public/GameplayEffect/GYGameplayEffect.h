// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GYGameplayEffect.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew)
class GYGAMEPLAYEFFECTDATATABLE_API UGYGameplayEffect : public UGameplayEffect
{
	GENERATED_BODY()
	
public:
	
	void AddGEComponents(TObjectPtr<UGameplayEffectComponent> GameplayEffectComponent);
};
