// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
public class GYGameplayEffectDataTable : ModuleRules
{
	public GYGameplayEffectDataTable(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				Path.Combine(ModuleDirectory, "Public"),
                Path.Combine(ModuleDirectory, "Public/GameplayEffect"),
				Path.Combine(ModuleDirectory, "Public/GameplayEffect/DataAsset"),
                Path.Combine(ModuleDirectory, "Public/GameplayEffect/GameplayEffectComponent"),
                Path.Combine(ModuleDirectory, "Public/GameplayEffect/BlueprintFunctionLibrary"),
                Path.Combine(ModuleDirectory, "Public/GameplayEffect/Settings")
            }
            );
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				//Path.Combine(ModuleDirectory, "Private"),
    //            Path.Combine(ModuleDirectory, "Private/GameplayEffect"),
    //            Path.Combine(ModuleDirectory, "Private/GameplayEffect/DataAsset"),
    //            Path.Combine(ModuleDirectory, "Private/GameplayEffect/GameplayEffectComponent")
            }
            );
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...
				"GameplayAbilities",
				"GameplayTasks",
                "GameplayTags",
                "DeveloperSettings",
            }
            );
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
