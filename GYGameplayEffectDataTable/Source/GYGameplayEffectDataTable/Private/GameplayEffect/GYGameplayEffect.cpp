// Fill out your copyright notice in the Description page of Project Settings.


#include "GYGameplayEffect.h"

void UGYGameplayEffect::AddGEComponents(TObjectPtr<UGameplayEffectComponent> GameplayEffectComponent)
{
	if (GameplayEffectComponent)
	{
		GEComponents.Add(GameplayEffectComponent);
	}
}
