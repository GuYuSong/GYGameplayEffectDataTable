// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffectComponent.h"
#include "GameplayEffectComponents/TargetTagsGameplayEffectComponent.h"
#include "GYTargetTagsGameplayEC.generated.h"

USTRUCT(BlueprintType)
struct FGY_TargetTagsGameplayECInfor : public FGY_GameplayEffectComponentInfor
{
	GENERATED_USTRUCT_BODY()

	/** These tags are applied (granted) to the target actor of the Gameplay Effect.  The Target would then "own" these Tags. */
	UPROPERTY(EditDefaultsOnly, Category = None, meta = (DisplayName = "Add Tags", Categories = "OwnedTagsCategory"))
	FInheritedTagContainer InheritableGrantedTagsContainer;
};
/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYTargetTagsGameplayEC : public UTargetTagsGameplayEffectComponent
{
	GENERATED_BODY()
	
	
	
	
};
