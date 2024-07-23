// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GYGameplayEffect.h"
#include "GYGameplayEffectsDT.h"
#include "GYGameplayEffectSubsystem.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GYGAMEPLAYEFFECTDATATABLE_API UGYGameplayEffectSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UDataTable* GameplayEffectsDT = nullptr;
	
	UFUNCTION(BlueprintCallable)
	void SetGameplayEffectsDT(UDataTable* NewDataTable);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGYGameplayEffect> GYGameplayEffectClass;

	UFUNCTION(BlueprintCallable)
	void SetGameplayEffectClass(TSubclassOf<UGYGameplayEffect> NewGameplayEffectClass);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	template<class T1, class T2>
	T1* SubsCastFStruct(T2 InData)
	{
		uint8* uint8Data = reinterpret_cast<uint8*>(InData);
		if (!uint8Data)
		{
			return nullptr;
		}

		T1* OutData = reinterpret_cast<T1*>(uint8Data);
		if (!OutData)
		{
			return nullptr;
		}

		return OutData;
	}

	template<class T>
	UGYGameplayEffect* GetGameplayEffectWithClass(FName RowID, TSubclassOf<UGYGameplayEffect> NewGYGameplayEffectClass)
	{
		if (NewGYGameplayEffectClass)
		{
			if (GameplayEffectsDT)
			{
				FString DTName = GameplayEffectsDT->GetName();
				T* GY_GameplayEffectsDT = GameplayEffectsDT->FindRow<T>(RowID, DTName);
				if (GY_GameplayEffectsDT)
				{
					UGYGameplayEffect* GameplayEffect = NewObject<UGYGameplayEffect>(this, NewGYGameplayEffectClass, GY_GameplayEffectsDT->GameplayEffectName);
					if (!GameplayEffect)
					{
						return nullptr;
					}

					InitGameplayEffect(GY_GameplayEffectsDT, GameplayEffect, RowID);
					
					PostInitGameplayEffect(SubsCastFStruct<uint8>(GY_GameplayEffectsDT), GameplayEffect, RowID);
					return GameplayEffect;
				}
			}
		}

		return nullptr;
	}

	template<class T>
	UGYGameplayEffect* GetGameplayEffect(FName RowID)
	{
		return GetGameplayEffectWithClass<T>(RowID, GYGameplayEffectClass);
	}

	template<class T>
	void InitGameplayEffect(T* GameplayEffectsDT, UGYGameplayEffect* OutGameplayEffect, FName RowID);

	//重写这个函数,用户可以自己初始化自己的组件
	virtual void PostInitGameplayEffect(uint8* GameplayEffectsRowDT, UGYGameplayEffect* OutGameplayEffect, FName RowID);

	void Add_GEAbilitiesGameplayEffectComponents(TArray<FGY_AbilitiesGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect);
	void Add_GEAdditionalEffectsGameplayEffectComponents(TArray<FGY_AdditionalEffectsGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect);
	void Add_GEAssetTagsGameplayEffectComponents(TArray<FGY_AssetTagsGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect);
	void Add_GEBlockAbilityTagsGameplayEffectComponents(TArray<FGY_BlockAbilityTagsGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect);
	void Add_GEChanceToApplyGameplayEffectComponents(TArray<FGY_ChanceToApplyGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect);
	void Add_GECustomCanApplyGameplayEffectComponents(TArray<FGY_CustomCanApplyGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect);
	void Add_GEImmunityGameplayEffectComponents(TArray<FGY_ImmunityGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect);
	void Add_GERemoveOtherGameplayEffectComponents(TArray<FGY_RemoveOtherGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect);
	void Add_GETargetTagRequirementsGameplayEffectComponents(TArray<FGY_TargetTagRequirementsGECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect);
	void Add_GETargetTagsGameplayEffectComponents(TArray<FGY_TargetTagsGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect);
};

template<class T>
void UGYGameplayEffectSubsystem::InitGameplayEffect(T* GameplayEffectsDT, UGYGameplayEffect* OutGameplayEffect, FName RowID)
{
	if (GameplayEffectsDT && OutGameplayEffect)
	{
		OutGameplayEffect->DurationPolicy = GameplayEffectsDT->DurationPolicy;
		OutGameplayEffect->DurationMagnitude = GameplayEffectsDT->DurationMagnitude;
		OutGameplayEffect->Period = GameplayEffectsDT->Period;
		OutGameplayEffect->bExecutePeriodicEffectOnApplication = GameplayEffectsDT->bExecutePeriodicEffectOnApplication;
		OutGameplayEffect->PeriodicInhibitionPolicy = GameplayEffectsDT->PeriodicInhibitionPolicy;
		OutGameplayEffect->Modifiers = GameplayEffectsDT->Modifiers;
		OutGameplayEffect->Executions = GameplayEffectsDT->Executions;
		OutGameplayEffect->OverflowEffects = GameplayEffectsDT->OverflowEffects;
		OutGameplayEffect->bDenyOverflowApplication = GameplayEffectsDT->bDenyOverflowApplication;
		OutGameplayEffect->bClearStackOnOverflow = GameplayEffectsDT->bClearStackOnOverflow;
		OutGameplayEffect->bRequireModifierSuccessToTriggerCues = GameplayEffectsDT->bRequireModifierSuccessToTriggerCues;
		OutGameplayEffect->bSuppressStackingCues = GameplayEffectsDT->bSuppressStackingCues;
		OutGameplayEffect->GameplayCues = GameplayEffectsDT->GameplayCues;
		OutGameplayEffect->StackingType = GameplayEffectsDT->StackingType;
		OutGameplayEffect->StackLimitCount = GameplayEffectsDT->StackLimitCount;
		OutGameplayEffect->StackDurationRefreshPolicy = GameplayEffectsDT->StackDurationRefreshPolicy;
		OutGameplayEffect->StackPeriodResetPolicy = GameplayEffectsDT->StackPeriodResetPolicy;
		OutGameplayEffect->StackExpirationPolicy = GameplayEffectsDT->StackExpirationPolicy;


		Add_GEAbilitiesGameplayEffectComponents(GameplayEffectsDT->GEAbilitiesGameplayEffectComponents, OutGameplayEffect);
		Add_GEAdditionalEffectsGameplayEffectComponents(GameplayEffectsDT->GEAdditionalEffectsGameplayEffectComponents, OutGameplayEffect);
		Add_GEAssetTagsGameplayEffectComponents(GameplayEffectsDT->GEAssetTagsGameplayEffectComponents, OutGameplayEffect);
		Add_GEBlockAbilityTagsGameplayEffectComponents(GameplayEffectsDT->GEBlockAbilityTagsGameplayEffectComponents, OutGameplayEffect);
		Add_GEChanceToApplyGameplayEffectComponents(GameplayEffectsDT->GEChanceToApplyGameplayEffectComponents, OutGameplayEffect);
		Add_GECustomCanApplyGameplayEffectComponents(GameplayEffectsDT->GECustomCanApplyGameplayEffectComponents, OutGameplayEffect);
		Add_GEImmunityGameplayEffectComponents(GameplayEffectsDT->GEImmunityGameplayEffectComponents, OutGameplayEffect);
		Add_GERemoveOtherGameplayEffectComponents(GameplayEffectsDT->GERemoveOtherGameplayEffectComponents, OutGameplayEffect);
		Add_GETargetTagRequirementsGameplayEffectComponents(GameplayEffectsDT->GETargetTagRequirementsGameplayEffectComponents, OutGameplayEffect);
		Add_GETargetTagsGameplayEffectComponents(GameplayEffectsDT->GETargetTagsGameplayEffectComponents, OutGameplayEffect);
	}
}
