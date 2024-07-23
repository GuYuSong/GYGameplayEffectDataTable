// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffectComponent.h"
#include "GameplayEffectComponents/AssetTagsGameplayEffectComponent.h"
#include "GYAssetTagsGameplayEC.generated.h"


USTRUCT(BlueprintType)
struct FGY_AssetTagsGameplayECInfor : public FGY_GameplayEffectComponentInfor
{
	GENERATED_USTRUCT_BODY()

	/** The GameplayEffect's Tags: tags the the GE *has* and DOES NOT give to the actor. */
	UPROPERTY(EditDefaultsOnly, Category = Tags, meta = (DisplayName = "AssetTags", Categories = "OwnedTagsCategory"))
	FInheritedTagContainer InheritableAssetTags;
};


/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYAssetTagsGameplayEC : public UAssetTagsGameplayEffectComponent
{
	GENERATED_BODY()
	
	
	
	
};
