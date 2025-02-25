// Copyright 2024 GY. All Rights Reserved.

#include "GYGameplayEffectDataTable.h"
#include "GameplayEffect/Settings/GYGameplayEffectDTSettings.h"
#include "GameplayEffect/BlueprintFunctionLibrary/GYGameplayEffectBFL.h"

#define LOCTEXT_NAMESPACE "FGYGameplayEffectDataTableModule"

void FGYGameplayEffectDataTableModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	CreateSettings();

}

void FGYGameplayEffectDataTableModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	DeleteSettings();
}

void FGYGameplayEffectDataTableModule::CreateSettings()
{
	UClass* GameplayEffectDTSettingsClass = UGYGameplayEffectDTSettings::StaticClass();

	if (GameplayEffectDTSettingsClass)
	{
		GameplayEffectDTSettings = Cast<UGYGameplayEffectDTSettings>(GameplayEffectDTSettingsClass->GetDefaultObject());
	}
}


void FGYGameplayEffectDataTableModule::DeleteSettings()
{

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGYGameplayEffectDataTableModule, GYGameplayEffectDataTable)