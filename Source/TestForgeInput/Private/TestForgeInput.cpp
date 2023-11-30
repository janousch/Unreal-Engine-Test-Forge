// Copyright 2023 Ramon Janousch. All Rights Reserved.

#include <AssetToolsModule.h>
#include <CoreMinimal.h>
#include <ISettingsModule.h>
#include <Modules/ModuleManager.h>

#define LOCTEXT_NAMESPACE "AutomatedBlueprintTests"

IMPLEMENT_MODULE(FAutomatedBlueprintTestsInput, AutomatedBlueprintTestsInput)

void FAutomatedBlueprintTestsInput::StartupModule()
{
    
}

void FAutomatedBlueprintTestsInput::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE
