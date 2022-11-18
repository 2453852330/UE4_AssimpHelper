// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProceduralMeshHelper.h"

#include "Misc/MessageDialog.h"

#define LOCTEXT_NAMESPACE "FProceduralMeshHelperModule"

void FProceduralMeshHelperModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// FMessageDialog::Open(EAppMsgType::Ok,FText::FromString("Custom Plugins Start"));
}

void FProceduralMeshHelperModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FProceduralMeshHelperModule, ProceduralMeshHelper)