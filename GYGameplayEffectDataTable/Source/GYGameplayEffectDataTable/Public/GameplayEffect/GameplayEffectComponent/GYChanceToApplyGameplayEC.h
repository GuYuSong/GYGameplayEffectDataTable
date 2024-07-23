// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffectComponent.h"
#include "GameplayEffectComponents/ChanceToApplyGameplayEffectComponent.h"
#include "GYChanceToApplyGameplayEC.generated.h"

USTRUCT(BlueprintType)
struct FGY_ChanceToApplyGameplayECInfor : public FGY_GameplayEffectComponentInfor
{
	GENERATED_USTRUCT_BODY()

	/** Probability that this gameplay effect will be applied to the target actor (0.0 for never, 1.0 for always) */
	UPROPERTY(EditDefaultsOnly, Category = Application, meta = (GameplayAttribute = "True"))
	FScalableFloat ChanceToApplyToTarget;
};


/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYChanceToApplyGameplayEC : public UChanceToApplyGameplayEffectComponent
{
	GENERATED_BODY()
	
	
	
	
};
