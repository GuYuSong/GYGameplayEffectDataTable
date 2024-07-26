// Copyright 2024 GY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffectComponent.h"
#include "GameplayEffectComponents/RemoveOtherGameplayEffectComponent.h"
#include "GYRemoveOtherGameplayEC.generated.h"


USTRUCT(BlueprintType)
struct FGY_RemoveOtherGameplayECInfor : public FGY_GameplayEffectComponentInfor
{
	GENERATED_USTRUCT_BODY()

	/** On Application of the owning Gameplay Effect, any Active GameplayEffects that *match* these queries will be removed. */
	UPROPERTY(EditDefaultsOnly, Category = None)
	TArray<FGameplayEffectQuery> RemoveGameplayEffectQueries;
};

/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYRemoveOtherGameplayEC : public URemoveOtherGameplayEffectComponent
{
	GENERATED_BODY()
	
	
	
	
};
