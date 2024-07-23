// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FGYGameplayEffectDataTableModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


	class UGYGameplayEffectDTSettings* GameplayEffectDTSettings = nullptr;

	void CreateSettings();
	void DeleteSettings();
};
