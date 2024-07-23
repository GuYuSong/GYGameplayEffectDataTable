// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GYGameplayEffect.h"
#include "GameplayEffectComponent/GYAbilitiesGameplayEC.h"
#include "GameplayEffectComponent/GYAdditionalEffectsGameplayEC.h"
#include "GameplayEffectComponent/GYAssetTagsGameplayEC.h"
#include "GameplayEffectComponent/GYBlockAbilityTagsGameplayEC.h"
#include "GameplayEffectComponent/GYChanceToApplyGameplayEC.h"
#include "GameplayEffectComponent/GYCustomCanApplyGameplayEC.h"
#include "GameplayEffectComponent/GYImmunityGameplayEC.h"
#include "GameplayEffectComponent/GYRemoveOtherGameplayEC.h"
#include "GameplayEffectComponent/GYTargetTagRequirementsGEC.h"
#include "GameplayEffectComponent/GYTargetTagsGameplayEC.h"
#include "GYGameplayEffectsDT.generated.h"


USTRUCT(BlueprintType)
struct FGY_GameplayEffectsDT : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		FName GameplayEffectName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Describe;

	/** Policy for the duration of this effect */
	UPROPERTY(EditDefaultsOnly, Category = Duration)
		EGameplayEffectDurationType DurationPolicy;

	/** Duration in seconds. 0.0 for instantaneous effects; -1.0 for infinite duration. */
	UPROPERTY(EditDefaultsOnly, Category = Duration, meta = (EditCondition = "DurationPolicy == EGameplayEffectDurationType::HasDuration", EditConditionHides))
		FGameplayEffectModifierMagnitude DurationMagnitude;

	/** Period in seconds. 0.0 for non-periodic effects */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Duration",
		meta = (EditCondition = "DurationPolicy != EGameplayEffectDurationType::Instant", EditConditionHides))
		FScalableFloat Period;

	/** If true, the effect executes on application and then at every period interval. If false, no execution occurs until the first period elapses. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Duration", meta = (EditCondition = "true", EditConditionHides)) // EditCondition in FGameplayEffectDetails
		bool bExecutePeriodicEffectOnApplication;

	/** How we should respond when a periodic gameplay effect is no longer inhibited */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Duration", meta = (EditCondition = "true", EditConditionHides)) // EditCondition in FGameplayEffectDetails
		EGameplayEffectPeriodInhibitionRemovedPolicy PeriodicInhibitionPolicy;

	/** Array of modifiers that will affect the target of this effect */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GameplayEffect, meta = (TitleProperty = Attribute))
		TArray<FGameplayModifierInfo> Modifiers;

	/** Array of executions that will affect the target of this effect */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GameplayEffect)
		TArray<FGameplayEffectExecutionDefinition> Executions;


	/** Effects to apply when a stacking effect "overflows" its stack count through another attempted application. Added whether the overflow application succeeds or not. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stacking", meta = (EditConditionHides, EditCondition = "StackingType != EGameplayEffectStackingType::None"))
		TArray<TSubclassOf<UGameplayEffect>> OverflowEffects;

	/** If true, stacking attempts made while at the stack count will fail, resulting in the duration and context not being refreshed */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stacking", meta = (EditConditionHides, EditCondition = "StackingType != EGameplayEffectStackingType::None"))
		bool bDenyOverflowApplication;

	/** If true, the entire stack of the effect will be cleared once it overflows */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stacking",
		meta = (EditConditionHides, EditCondition = "(StackingType != EGameplayEffectStackingType::None) && bDenyOverflowApplication"))
		bool bClearStackOnOverflow;

	/** If true, cues will only trigger when GE modifiers succeed being applied (whether through modifiers or executions) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayCues")
		bool bRequireModifierSuccessToTriggerCues;

	/** If true, GameplayCues will only be triggered for the first instance in a stacking GameplayEffect. */
	UPROPERTY(EditDefaultsOnly, Category = "GameplayCues")
		bool bSuppressStackingCues;

	/** Cues to trigger non-simulated reactions in response to this GameplayEffect such as sounds, particle effects, etc */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayCues")
		TArray<FGameplayEffectCue> GameplayCues;

	// ----------------------------------------------------------------------
	//	Stacking
	// ----------------------------------------------------------------------

	/** How this GameplayEffect stacks with other instances of this same GameplayEffect */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Stacking)
		EGameplayEffectStackingType StackingType;

	/** Stack limit for StackingType */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Stacking, meta = (EditConditionHides, EditCondition = "StackingType != EGameplayEffectStackingType::None"))
		int32 StackLimitCount;

	/** Policy for how the effect duration should be refreshed while stacking */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Stacking, meta = (EditConditionHides, EditCondition = "StackingType != EGameplayEffectStackingType::None"))
		EGameplayEffectStackingDurationPolicy StackDurationRefreshPolicy;

	/** Policy for how the effect period should be reset (or not) while stacking */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Stacking, meta = (EditConditionHides, EditCondition = "StackingType != EGameplayEffectStackingType::None"))
		EGameplayEffectStackingPeriodPolicy StackPeriodResetPolicy;

	/** Policy for how to handle duration expiring on this gameplay effect */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Stacking, meta = (EditConditionHides, EditCondition = "StackingType != EGameplayEffectStackingType::None"))
		EGameplayEffectStackingExpirationPolicy StackExpirationPolicy;


	/** These Gameplay Effect Components define how this Gameplay Effect behaves when applied */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffectComponents")
		TArray<FGY_AbilitiesGameplayECInfor> GEAbilitiesGameplayEffectComponents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffectComponents")
		TArray<FGY_AdditionalEffectsGameplayECInfor> GEAdditionalEffectsGameplayEffectComponents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffectComponents")
		TArray<FGY_AssetTagsGameplayECInfor> GEAssetTagsGameplayEffectComponents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffectComponents")
		TArray<FGY_BlockAbilityTagsGameplayECInfor> GEBlockAbilityTagsGameplayEffectComponents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffectComponents")
		TArray<FGY_ChanceToApplyGameplayECInfor> GEChanceToApplyGameplayEffectComponents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffectComponents")
		TArray<FGY_CustomCanApplyGameplayECInfor> GECustomCanApplyGameplayEffectComponents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffectComponents")
		TArray<FGY_ImmunityGameplayECInfor> GEImmunityGameplayEffectComponents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffectComponents")
		TArray<FGY_RemoveOtherGameplayECInfor> GERemoveOtherGameplayEffectComponents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffectComponents")
		TArray<FGY_TargetTagRequirementsGECInfor> GETargetTagRequirementsGameplayEffectComponents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffectComponents")
		TArray<FGY_TargetTagsGameplayECInfor> GETargetTagsGameplayEffectComponents;
};
