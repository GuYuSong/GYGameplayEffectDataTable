// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffectComponent.h"
#include "GameplayEffectComponents/TargetTagRequirementsGameplayEffectComponent.h"
#include "GYTargetTagRequirementsGEC.generated.h"

USTRUCT(BlueprintType)
struct FGY_TargetTagRequirementsGECInfor : public FGY_GameplayEffectComponentInfor
{
	GENERATED_USTRUCT_BODY()

	/** Tag requirements the target must have for this GameplayEffect to be applied. This is pass/fail at the time of application. If fail, this GE fails to apply. */
	UPROPERTY(EditDefaultsOnly, Category = Tags)
		FGameplayTagRequirements ApplicationTagRequirements;

	/** Once Applied, these tags requirements are used to determined if the GameplayEffect is "on" or "off". A GameplayEffect can be off and do nothing, but still applied. */
	UPROPERTY(EditDefaultsOnly, Category = Tags)
		FGameplayTagRequirements OngoingTagRequirements;

	/** Tag requirements that if met will remove this effect. Also prevents effect application. */
	UPROPERTY(EditDefaultsOnly, Category = Tags)
		FGameplayTagRequirements RemovalTagRequirements;
};
/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYTargetTagRequirementsGEC : public UTargetTagRequirementsGameplayEffectComponent
{
	GENERATED_BODY()
	
	
	
	
};
