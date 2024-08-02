// Copyright 2024 GY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffectComponent.h"
#include "GameplayEffectComponents/AdditionalEffectsGameplayEffectComponent.h"
#include "GYAdditionalEffectsGameplayEC.generated.h"


USTRUCT(BlueprintType)
struct FGY_AdditionalEffectsGameplayECInfor : public FGY_GameplayEffectComponentInfor
{
	GENERATED_USTRUCT_BODY()

	/**
	* This will copy all of the data (e.g. SetByCallerMagnitudes) from the GESpec that Applied this GameplayEffect to the new OnApplicationGameplayEffect Specs.
	* One would think this is normally desirable (and how OnComplete works by default), but we default to false here for backwards compatability.
	*/
	UPROPERTY(EditDefaultsOnly, Category = OnApplication)
		bool bOnApplicationCopyDataFromOriginalSpec = false;

	/** Other gameplay effects that will be applied to the target of this effect if the owning effect applies */
	UPROPERTY(EditDefaultsOnly, Category = OnApplication)
		TArray<FConditionalGameplayEffect> OnApplicationGameplayEffects;

	/** Effects to apply when this effect completes, regardless of how it ends */
	UPROPERTY(EditDefaultsOnly, Category = OnComplete)
		TArray<TSubclassOf<UGameplayEffect>> OnCompleteAlways;

	/** Effects to apply when this effect expires naturally via its duration */
	UPROPERTY(EditDefaultsOnly, Category = OnComplete)
		TArray<TSubclassOf<UGameplayEffect>> OnCompleteNormal;

	/** Effects to apply when this effect is made to expire prematurely (e.g. via a forced removal, clear tags, etc.) */
	UPROPERTY(EditDefaultsOnly, Category = OnComplete)
		TArray<TSubclassOf<UGameplayEffect>> OnCompletePrematurely;
};

/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYAdditionalEffectsGameplayEC : public UAdditionalEffectsGameplayEffectComponent
{
	GENERATED_BODY()
	
	
	
	
};
