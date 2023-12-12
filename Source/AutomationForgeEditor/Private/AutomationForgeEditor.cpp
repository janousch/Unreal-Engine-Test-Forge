// Copyright 2023 Ramon Janousch. All Rights Reserved.

//#include <AssetToolsModule.h>
#include <CoreMinimal.h>
//#include <ISettingsModule.h>
#include "IAutomationForgeEditor.h"
#include <Modules/ModuleManager.h>

//#include "AutomationTestFramework/DaeTestAutomationPluginAutomationTestFrameworkIntegration.h"
//#include "AssetTypeActions_DaeTestActorBlueprint.h"
//#include "AssetTypeActions_DaeTestParameterProviderActorBlueprint.h"
//#include "AssetTypeActions_DaeTestSuiteActorBlueprint.h"
//#include "DaedalicTestAutomationPluginEditorClasses.h"
//#include "IDaedalicTestAutomationPluginEditor.h"
//#include "Settings/DaeTestAutomationPluginSettings.h"
//#include <AssetToolsModule.h>
//#include <IAssetTypeActions.h>
//#include <ISettingsModule.h>
//#include <ISettingsSection.h>

#define LOCTEXT_NAMESPACE "AutomationForge"

class FAutomationForgeEditor : public IAutomationForgeEditor
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    /** Asset catetory for test automation assets. */
    //EAssetTypeCategories::Type TestForgeAssetCategory;

    /** Asset type actions registered by this module. */
    //TArray<TSharedPtr<IAssetTypeActions>> AssetTypeActions;

    /** Integration with the Unreal Automation Test Framework. */
    //FDaeTestAutomationPluginAutomationTestFrameworkIntegration AutomationTestFrameworkIntegration;

    /*void RegisterAssetTypeAction(class IAssetTools& AssetTools,
                                 TSharedRef<IAssetTypeActions> Action);

    void OnTestMapsChanged();*/
};

IMPLEMENT_MODULE(FAutomationForgeEditor, AutomationForgeEditor)

void FAutomationForgeEditor::StartupModule()
{
    // Register asset types.
    //IAssetTools& AssetTools =
    //    FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

    //DaedalicTestAutomationAssetCategory =
    //    AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("DaedalicTestAutomationPlugin")),
    //                                             NSLOCTEXT("DaedalicTestAutomationPlugin",
    //                                                       "DaedalicTestAutomationAssetCategory",
    //                                                       "Test Automation"));

    //TSharedRef<IAssetTypeActions> TestActorBlueprintAction = MakeShareable(
    //    new FAssetTypeActions_DaeTestActorBlueprint(DaedalicTestAutomationAssetCategory));
    //RegisterAssetTypeAction(AssetTools, TestActorBlueprintAction);

    //TSharedRef<IAssetTypeActions> TestSuiteActorBlueprintAction = MakeShareable(
    //    new FAssetTypeActions_DaeTestSuiteActorBlueprint(DaedalicTestAutomationAssetCategory));
    //RegisterAssetTypeAction(AssetTools, TestSuiteActorBlueprintAction);

    //TSharedRef<IAssetTypeActions> TestParameterProviderActorBlueprintAction =
    //    MakeShareable(new FAssetTypeActions_DaeTestParameterProviderActorBlueprint(
    //        DaedalicTestAutomationAssetCategory));
    //RegisterAssetTypeAction(AssetTools, TestParameterProviderActorBlueprintAction);

    //// Register settings.
    //if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    //{
    //    UDaeTestAutomationPluginSettings* TestAutomationPluginSettings =
    //        GetMutableDefault<UDaeTestAutomationPluginSettings>();

    //    ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings(
    //        "Project", "Plugins", "DaedalicTestAutomationPlugin",
    //        NSLOCTEXT("DaedalicTestAutomationPlugin", "DaeTestAutomationPluginSettings.DisplayName",
    //                  "Daedalic Test Automation Plugin"),
    //        NSLOCTEXT("DaedalicTestAutomationPlugin", "DaeTestAutomationPluginSettings.Description",
    //                  "Configure the discovery of automated tests."),
    //        TestAutomationPluginSettings);

    //    TestAutomationPluginSettings->OnTestMapsChanged.AddRaw(
    //        this, &FDaedalicTestAutomationPluginEditor::OnTestMapsChanged);

    //    OnTestMapsChanged();
    //}
}

void FAutomationForgeEditor::ShutdownModule()
{
    // Unregister asset types.
    //if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
    //{
    //    IAssetTools& AssetToolsModule =
    //        FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
    //    for (auto& AssetTypeAction : AssetTypeActions)
    //    {
    //        if (AssetTypeAction.IsValid())
    //        {
    //            AssetToolsModule.UnregisterAssetTypeActions(AssetTypeAction.ToSharedRef());
    //        }
    //    }
    //}

    //AssetTypeActions.Empty();

    //// Unregister settings.
    //if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    //{
    //    SettingsModule->UnregisterSettings("Editor", "Plugins", "DaedalicTestAutomationPlugin");
    //}
}

//void FTestForgeEditor::RegisterAssetTypeAction(
//    class IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
//{
//    AssetTools.RegisterAssetTypeActions(Action);
//    AssetTypeActions.Add(Action);
//}

//void FTestForgeEditor::OnTestMapsChanged()
//{
//    AutomationTestFrameworkIntegration.DiscoverTests();
//}

#undef LOCTEXT_NAMESPACE


