// Fill out your copyright notice in the Description page of Project Settings.


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
