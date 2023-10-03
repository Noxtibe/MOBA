// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MOBA_Character : ModuleRules
{
	public MOBA_Character(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
