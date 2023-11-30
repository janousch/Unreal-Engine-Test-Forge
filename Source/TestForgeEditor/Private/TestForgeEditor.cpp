// Copyright 2023 Ramon Janousch. All Rights Reserved.

#include <AssetToolsModule.h>
#include <CoreMinimal.h>
#include <ISettingsModule.h>
#include <Modules/ModuleManager.h>

#define LOCTEXT_NAMESPACE "TestForge"

IMPLEMENT_MODULE(FTestForgeEditor, TestForgeEditor)

void FTestForgeEditor::StartupModule()
{
    
}

void FTestForgeEditor::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE

