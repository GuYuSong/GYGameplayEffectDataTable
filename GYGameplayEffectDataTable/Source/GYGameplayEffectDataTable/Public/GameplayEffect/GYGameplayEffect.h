// Copyright 2024 GY. All Rights Reserved.

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
