// Copyright 2024 GY. All Rights Reserved.


#include "GameplayEffect/BlueprintFunctionLibrary/GYGameplayEffectBFL.h"

void UGYGameplayEffectBFL::SetGameplayEffectsDT(UDataTable* NewDataTable, UObject* ContextObject)
{
	UGYGameplayEffectSubsystem* GYGameplayEffectSubsystem = Cast<UGYGameplayEffectSubsystem>(USubsystemBlueprintLibrary::GetGameInstanceSubsystem(ContextObject, UGYGameplayEffectSubsystem::StaticClass()));
	if (!GYGameplayEffectSubsystem)
	{
		return;
	}

	GYGameplayEffectSubsystem->SetGameplayEffectsDT(NewDataTable);
}

void UGYGameplayEffectBFL::SetGameplayEffectClass(TSubclassOf<UGYGameplayEffect> NewGameplayEffectClass, UObject* ContextObject)
{
	UGYGameplayEffectSubsystem* GYGameplayEffectSubsystem = Cast<UGYGameplayEffectSubsystem>(USubsystemBlueprintLibrary::GetGameInstanceSubsystem(ContextObject, UGYGameplayEffectSubsystem::StaticClass()));
	if (!GYGameplayEffectSubsystem)
	{
		return;
	}

	GYGameplayEffectSubsystem->SetGameplayEffectClass(NewGameplayEffectClass);
}
