// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffectComponent.h"
#include "GameplayEffectComponents/BlockAbilityTagsGameplayEffectComponent.h"
#include "GYBlockAbilityTagsGameplayEC.generated.h"


USTRUCT(BlueprintType)
struct FGY_BlockAbilityTagsGameplayECInfor : public FGY_GameplayEffectComponentInfor
{
	GENERATED_USTRUCT_BODY()

	/** These tags are applied to the target actor of the Gameplay Effect.  Blocked Ability Tags prevent Gameplay Abilities with these tags from executing. */
	UPROPERTY(EditDefaultsOnly, Category = None, meta = (DisplayName = "Block Abilities w/ Tags"))
	FInheritedTagContainer InheritableBlockedAbilityTagsContainer;
};

/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYBlockAbilityTagsGameplayEC : public UBlockAbilityTagsGameplayEffectComponent
{
	GENERATED_BODY()
	
	
	
	
};
