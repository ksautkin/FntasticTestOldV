// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FntasticTestOldV : ModuleRules
{
	public FntasticTestOldV(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
