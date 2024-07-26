// Copyright 2024 GY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/ActiveGameplayEffectHandle.h"
#include "../../Engine/Public/Subsystems/SubsystemBlueprintLibrary.h"
#include "GameplayEffect/Subsystem/GYGameplayEffectSubsystem.h"
#include "../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemBlueprintLibrary.h"
#include "../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemComponent.h"
#include "GYGameplayEffectBFL.generated.h"

/**
 * 
 */
UCLASS()
class GYGAMEPLAYEFFECTDATATABLE_API UGYGameplayEffectBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	template<class T>
	static FActiveGameplayEffectHandle GYApplyGameplayEffectWithClass(AActor* Source, AActor* Target, FName Id, TSubclassOf<UGYGameplayEffect> GYGameplayEffectClass, float Level = 0.f)
	{
		UAbilitySystemComponent* SourceAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Source);
		UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);

		if (!SourceAbilitySystemComponent || !TargetAbilitySystemComponent) return false;

		UGYGameplayEffectSubsystem* GYGameplayEffectSubsystem = Cast<UGYGameplayEffectSubsystem>(USubsystemBlueprintLibrary::GetGameInstanceSubsystem(Source, UGYGameplayEffectSubsystem::StaticClass()));
		if (!GYGameplayEffectSubsystem)
		{
			return false;
		}

		if (!GYGameplayEffectClass)
		{
			return false;
		}
		UGYGameplayEffect* GameplayEffect = GYGameplayEffectSubsystem->GetGameplayEffectWithClass<T>(Id, GYGameplayEffectClass);
		if (!GameplayEffect)
		{
			return false;
		}

		FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
		EffectContextHandle.AddSourceObject(Source);
		FGameplayEffectSpec* NewSpec = new FGameplayEffectSpec(GameplayEffect, EffectContextHandle, Level);
		const FGameplayEffectSpecHandle EffectSpecHandle = FGameplayEffectSpecHandle(NewSpec);

		const FActiveGameplayEffectHandle ActiveEffectHandle = TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

		return ActiveEffectHandle;
	}
	
	template<class T>
	static FActiveGameplayEffectHandle GYApplyGameplayEffect(AActor* Source, AActor* Target, FName Id, float Level = 0.f)
	{
		UGYGameplayEffectSubsystem* GYGameplayEffectSubsystem = Cast<UGYGameplayEffectSubsystem>(USubsystemBlueprintLibrary::GetGameInstanceSubsystem(Source, UGYGameplayEffectSubsystem::StaticClass()));
		if (!GYGameplayEffectSubsystem)
		{
			return false;
		}

		if (!GYGameplayEffectSubsystem->GYGameplayEffectClass)
		{
			return false;
		}

		return GYApplyGameplayEffectWithClass<T>(Source, Target, Id, GYGameplayEffectSubsystem->GYGameplayEffectClass, Level);
	}

	UFUNCTION(BlueprintCallable, Category = "GYGameplayEffectBFL")
	static void SetGameplayEffectsDT(UDataTable* NewDataTable, UObject* ContextObject);

	UFUNCTION(BlueprintCallable, Category = "GYGameplayEffectBFL")
	static void SetGameplayEffectClass(TSubclassOf<UGYGameplayEffect> NewGameplayEffectClass, UObject* ContextObject);




	template<class T1, class T2>
	static T1* CastFStruct(T2 InData)
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
};
