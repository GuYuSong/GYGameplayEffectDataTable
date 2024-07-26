// Copyright 2024 GY. All Rights Reserved.


#include "GYGameplayEffect.h"

void UGYGameplayEffect::AddGEComponents(TObjectPtr<UGameplayEffectComponent> GameplayEffectComponent)
{
	if (GameplayEffectComponent)
	{
		GEComponents.Add(GameplayEffectComponent);
	}
}
