// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include <AssetToolsModule.h>
#include <CoreMinimal.h>
#include <IAssetTypeActions.h>
#include <ISettingsModule.h>
#include <ISettingsSection.h>
#include <Modules/ModuleManager.h>

#define LOCTEXT_NAMESPACE "AutomatedBlueprintTests"

IMPLEMENT_MODULE(FAutomatedBlueprintTestsEditor, AutomatedBlueprintTestsEditor)

void FDaedalicTestAutomationPluginEditor::StartupModule()
{
    
}

void FDaedalicTestAutomationPluginEditor::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE
