// Copyright 2024 GY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffectComponent.h"
#include "GameplayEffectComponents/CustomCanApplyGameplayEffectComponent.h"
#include "GYCustomCanApplyGameplayEC.generated.h"


USTRUCT(BlueprintType)
struct FGY_CustomCanApplyGameplayECInfor : public FGY_GameplayEffectComponentInfor
{
	GENERATED_USTRUCT_BODY()

	/** Custom application requirements */
	UPROPERTY(EditDefaultsOnly, Category = Application, meta = (DisplayName = "Custom Application Requirement"))
	TArray<TSubclassOf<UGameplayEffectCustomApplicationRequirement>> ApplicationRequirements;
};

/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYCustomCanApplyGameplayEC : public UCustomCanApplyGameplayEffectComponent
{
	GENERATED_BODY()
	
	
	
	
};
