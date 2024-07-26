// Copyright 2024 GY. All Rights Reserved.


#include "GameplayEffect/Subsystem/GYGameplayEffectSubsystem.h"
#include "GameplayEffect/DataAsset/GYGameplayEffectsDT.h"
#include "GYGameplayEffectDataTable.h"
#include "GameplayEffect/Settings/GYGameplayEffectDTSettings.h"




void UGYGameplayEffectSubsystem::SetGameplayEffectsDT(UDataTable* NewDataTable)
{
	GameplayEffectsDT = NewDataTable;
}


void UGYGameplayEffectSubsystem::SetGameplayEffectClass(TSubclassOf<UGYGameplayEffect> NewGameplayEffectClass)
{
	GYGameplayEffectClass = NewGameplayEffectClass;
}


void UGYGameplayEffectSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FGYGameplayEffectDataTableModule& GameplayEffectDTModule = FModuleManager::GetModuleChecked<FGYGameplayEffectDataTableModule>(TEXT("GYGameplayEffectDataTable"));

	if (GameplayEffectDTModule.GameplayEffectDTSettings)
	{
		if (GameplayEffectDTModule.GameplayEffectDTSettings->GYGameplayEffectClass)
		{
			SetGameplayEffectClass(GameplayEffectDTModule.GameplayEffectDTSettings->GYGameplayEffectClass);
		}
		
		UDataTable* NewGameplayEffectDT = LoadObject<UDataTable>(nullptr, *GameplayEffectDTModule.GameplayEffectDTSettings->GameplayEffectsDT.ToString());
		if (NewGameplayEffectDT)
		{
			SetGameplayEffectsDT(NewGameplayEffectDT);
		}
	}
}

void UGYGameplayEffectSubsystem::PostInitGameplayEffect(uint8* GameplayEffectsRowDT, UGYGameplayEffect* OutGameplayEffect, FName RowID)
{

}

void UGYGameplayEffectSubsystem::Add_GEAbilitiesGameplayEffectComponents(TArray<FGY_AbilitiesGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect)
{
	if (OutGameplayEffect)
	{
		for (FGY_AbilitiesGameplayECInfor& Item : InGEComponents)
		{
			TObjectPtr<UGYAbilitiesGameplayEC> Instance = NewObject<UGYAbilitiesGameplayEC>(OutGameplayEffect, NAME_None, GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
			if (Instance)
			{
				for (FGameplayAbilitySpecConfig& GameplayAbilitySpecConfig : Item.GrantAbilityConfigs)
				{
					Instance->AddGrantedAbilityConfig(GameplayAbilitySpecConfig);
				}
				OutGameplayEffect->AddGEComponents(Instance);
			}
		}
	}
}

void UGYGameplayEffectSubsystem::Add_GEAdditionalEffectsGameplayEffectComponents(TArray<FGY_AdditionalEffectsGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect)
{
	if (OutGameplayEffect)
	{
		for (FGY_AdditionalEffectsGameplayECInfor& Item : InGEComponents)
		{
			TObjectPtr<UGYAdditionalEffectsGameplayEC> Instance = NewObject<UGYAdditionalEffectsGameplayEC>(OutGameplayEffect, NAME_None, GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
			if (Instance)
			{
				Instance->bOnApplicationCopyDataFromOriginalSpec = Item.bOnApplicationCopyDataFromOriginalSpec;
				Instance->OnApplicationGameplayEffects = Item.OnApplicationGameplayEffects;
				Instance->OnCompleteAlways = Item.OnCompleteAlways;
				Instance->OnCompleteNormal = Item.OnCompleteNormal;
				Instance->OnCompletePrematurely = Item.OnCompletePrematurely;

				OutGameplayEffect->AddGEComponents(Instance);
			}
		}
	}
}

void UGYGameplayEffectSubsystem::Add_GEAssetTagsGameplayEffectComponents(TArray<FGY_AssetTagsGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect)
{
	if (OutGameplayEffect)
	{
		for (FGY_AssetTagsGameplayECInfor& Item : InGEComponents)
		{
			TObjectPtr<UGYAssetTagsGameplayEC> Instance = NewObject<UGYAssetTagsGameplayEC>(OutGameplayEffect, NAME_None, GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
			if (Instance)
			{
				Instance->SetAndApplyAssetTagChanges(Item.InheritableAssetTags);

				OutGameplayEffect->AddGEComponents(Instance);
			}
		}
	}
}

void UGYGameplayEffectSubsystem::Add_GEBlockAbilityTagsGameplayEffectComponents(TArray<FGY_BlockAbilityTagsGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect)
{
	if (OutGameplayEffect)
	{
		for (FGY_BlockAbilityTagsGameplayECInfor& Item : InGEComponents)
		{
			TObjectPtr<UGYBlockAbilityTagsGameplayEC> Instance = NewObject<UGYBlockAbilityTagsGameplayEC>(OutGameplayEffect, NAME_None, GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
			if (Instance)
			{
				Instance->SetAndApplyBlockedAbilityTagChanges(Item.InheritableBlockedAbilityTagsContainer);

				OutGameplayEffect->AddGEComponents(Instance);
			}
		}
	}
}

void UGYGameplayEffectSubsystem::Add_GEChanceToApplyGameplayEffectComponents(TArray<FGY_ChanceToApplyGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect)
{
	if (OutGameplayEffect)
	{
		for (FGY_ChanceToApplyGameplayECInfor& Item : InGEComponents)
		{
			TObjectPtr<UGYChanceToApplyGameplayEC> Instance = NewObject<UGYChanceToApplyGameplayEC>(OutGameplayEffect, NAME_None, GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
			if (Instance)
			{
				Instance->SetChanceToApplyToTarget(Item.ChanceToApplyToTarget);

				OutGameplayEffect->AddGEComponents(Instance);
			}
		}
	}
}

void UGYGameplayEffectSubsystem::Add_GECustomCanApplyGameplayEffectComponents(TArray<FGY_CustomCanApplyGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect)
{
	if (OutGameplayEffect)
	{
		for (FGY_CustomCanApplyGameplayECInfor& Item : InGEComponents)
		{
			TObjectPtr<UGYCustomCanApplyGameplayEC> Instance = NewObject<UGYCustomCanApplyGameplayEC>(OutGameplayEffect, NAME_None, GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
			if (Instance)
			{
				Instance->ApplicationRequirements = Item.ApplicationRequirements;

				OutGameplayEffect->AddGEComponents(Instance);
			}
		}
	}
}

void UGYGameplayEffectSubsystem::Add_GEImmunityGameplayEffectComponents(TArray<FGY_ImmunityGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect)
{
	if (OutGameplayEffect)
	{
		for (FGY_ImmunityGameplayECInfor& Item : InGEComponents)
		{
			TObjectPtr<UGYImmunityGameplayEC> Instance = NewObject<UGYImmunityGameplayEC>(OutGameplayEffect, NAME_None, GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
			if (Instance)
			{
				Instance->ImmunityQueries = Item.ImmunityQueries;

				OutGameplayEffect->AddGEComponents(Instance);
			}
		}
	}
}

void UGYGameplayEffectSubsystem::Add_GERemoveOtherGameplayEffectComponents(TArray<FGY_RemoveOtherGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect)
{
	if (OutGameplayEffect)
	{
		for (FGY_RemoveOtherGameplayECInfor& Item : InGEComponents)
		{
			TObjectPtr<UGYRemoveOtherGameplayEC> Instance = NewObject<UGYRemoveOtherGameplayEC>(OutGameplayEffect, NAME_None, GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
			if (Instance)
			{
				Instance->RemoveGameplayEffectQueries = Item.RemoveGameplayEffectQueries;

				OutGameplayEffect->AddGEComponents(Instance);
			}
		}
	}
}

void UGYGameplayEffectSubsystem::Add_GETargetTagRequirementsGameplayEffectComponents(TArray<FGY_TargetTagRequirementsGECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect)
{
	if (OutGameplayEffect)
	{
		for (FGY_TargetTagRequirementsGECInfor& Item : InGEComponents)
		{
			TObjectPtr<UGYTargetTagRequirementsGEC> Instance = NewObject<UGYTargetTagRequirementsGEC>(OutGameplayEffect, NAME_None, GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
			if (Instance)
			{
				Instance->ApplicationTagRequirements = Item.ApplicationTagRequirements;
				Instance->OngoingTagRequirements = Item.OngoingTagRequirements;
				Instance->RemovalTagRequirements = Item.RemovalTagRequirements;

				OutGameplayEffect->AddGEComponents(Instance);
			}
		}
	}
}

void UGYGameplayEffectSubsystem::Add_GETargetTagsGameplayEffectComponents(TArray<FGY_TargetTagsGameplayECInfor>& InGEComponents, UGYGameplayEffect* OutGameplayEffect)
{
	if (OutGameplayEffect)
	{
		for (FGY_TargetTagsGameplayECInfor& Item : InGEComponents)
		{
			TObjectPtr<UGYTargetTagsGameplayEC> Instance = NewObject<UGYTargetTagsGameplayEC>(OutGameplayEffect, NAME_None, GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
			if (Instance)
			{
				Instance->SetAndApplyTargetTagChanges(Item.InheritableGrantedTagsContainer);

				OutGameplayEffect->AddGEComponents(Instance);
			}
		}
	}
}
