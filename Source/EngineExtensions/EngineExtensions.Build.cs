// Copyright 2021 Russ 'trdwll' Treadwell <trdwll.com> - MIT Licensed

using UnrealBuildTool;

public class EngineExtensions : ModuleRules
{
	public EngineExtensions(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"RHI",
			"RenderCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"CoreUObject",
			"Engine",
			"Slate",
			"SlateCore",
		});
	}
}
