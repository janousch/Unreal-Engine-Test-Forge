// Copyright 2023 Ramon Janousch. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class AutomationForgeRuntime : ModuleRules
	{
		public AutomationForgeRuntime(ReadOnlyTargetRules Target) : base(Target)
		{
            PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					//"Core",
                    //"CoreUObject",
                    //"Engine",
                    //"InputCore",
                    "Gauntlet",
                    //"UMG",
                    //"SlateCore",
                    //"Slate",
                    //"RenderCore",
                    //"Projects"
                }
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
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
}


