// Copyright Epic Games, Inc. All Rights Reserved.

using System.Collections.Generic;
using System.IO;
using UnrealBuildTool;
public class UnrealEngineWork : ModuleRules
{
	public UnrealEngineWork(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(
			new string[] {
		 		// "YourProject/Gameplay"  // 也可以用相对路径
		 		Path.Combine(ModuleDirectory, "Collection") // 更推荐的写法，使用 ModuleDirectory
		   }
        );

        PublicIncludePaths.AddRange(
            new string[] {
		 		// "YourProject/Gameplay"  // 也可以用相对路径
		 		Path.Combine(ModuleDirectory, "Settings") // 更推荐的写法，使用 ModuleDirectory
		   }
        );

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
