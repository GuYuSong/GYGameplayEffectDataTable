// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffectComponent.h"
#include "GameplayEffectComponents/AbilitiesGameplayEffectComponent.h"
#include "GYAbilitiesGameplayEC.generated.h"


USTRUCT(BlueprintType)
struct FGY_AbilitiesGameplayECInfor : public FGY_GameplayEffectComponentInfor
{
	GENERATED_USTRUCT_BODY()

		/** Abilities to Grant to the Target while this Gameplay Effect is active */
	UPROPERTY(EditDefaultsOnly, Category = GrantAbilities)
		TArray<FGameplayAbilitySpecConfig>	GrantAbilityConfigs;
};

/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYAbilitiesGameplayEC : public UAbilitiesGameplayEffectComponent
{
	GENERATED_BODY()
	
	
	
	
};
