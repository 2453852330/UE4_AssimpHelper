// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ProceduralMeshHelper : ModuleRules
{
	private string ThirdPartyPath
	{
		get { return Path.Combine(ModuleDirectory, "../../ThirdParty"); }
	}

	private string AssimpLibPath
	{
		get { return Path.Combine(ThirdPartyPath, "ASSIMP"); }
	}


	public ProceduralMeshHelper(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[]
			{
				// ... add public include paths required here ...
				Path.Combine(AssimpLibPath, "include")
			}
		);


		PrivateIncludePaths.AddRange(
			new string[]
			{
				// ... add other private include paths required here ...
				
			}
		);
		PublicAdditionalLibraries.AddRange(
			new string[]
			{
				Path.Combine(AssimpLibPath, "lib/assimp-vc142-mtd.lib")
				
			});

		
	

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
				"ProceduralMeshComponent",
			}
		);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
		
		PublicDelayLoadDLLs.AddRange(
			new string[]
			{
				Path.Combine(AssimpLibPath,"assimp-vc142-mtd.dll")
			});
		
		// 
		// RuntimeDependencies.Add( Path.Combine(AssimpLibPath,"assimp-vc142-mtd.dll"));
		
		
		// RuntimeDependencies.Add( "$(BinaryOutputDir)/assimp-vc142-mtd.dll",Path.Combine(AssimpLibPath,"assimp-vc142-mtd.dll"));
		
	}
}