// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffectComponent.h"
#include "GameplayEffectComponents/ImmunityGameplayEffectComponent.h"
#include "GYImmunityGameplayEC.generated.h"

USTRUCT(BlueprintType)
struct FGY_ImmunityGameplayECInfor : public FGY_GameplayEffectComponentInfor
{
	GENERATED_USTRUCT_BODY()

	/** Grants immunity to GameplayEffects that match this query. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = None)
	TArray<FGameplayEffectQuery> ImmunityQueries;
};

/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYImmunityGameplayEC : public UImmunityGameplayEffectComponent
{
	GENERATED_BODY()
	
	
	
	
};
