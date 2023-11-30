#pragma once

#include "AutomationForgeTestMapMetaData.h"
#include "AutomationForgeTestMapSettings.h"
#include <CoreMinimal.h>
#include <UObject/Object.h>
#include "AutomationForgeTestAutomationPluginSettings.generated.h"

DECLARE_MULTICAST_DELEGATE(FAutomationForgeTestAutomationPluginSettingsTestMapsChangedSignature);

/** Custom settings for this plugin. */
UCLASS(config = Game, defaultconfig)
class AutomationForgeDALICTESTAUTOMATIONPLUGIN_API UAutomationForgeTestAutomationPluginSettings : public UObject
{
    GENERATED_BODY()

public:
    /** DEPRECATED: Use TestMapFolders instead. */
    UPROPERTY(config)
    FString TestMapPath;

    /** Paths to look for test maps in, relative to the Content root of your project (e.g. Maps/AutomatedTests). */
	UPROPERTY(config, EditAnywhere, Category = "General")
    TArray<FString> TestMapFolders;

    /** Names of additional maps to test. */
	UPROPERTY(config, EditAnywhere, Category = "General")
    TArray<FName> AdditionalTestMaps;

    /** Names of maps to ignore when found in test map folders. */
	UPROPERTY(config, EditAnywhere, Category = "General")
    TArray<FName> IgnoredMaps;

    /** Console variables to set before running batches of tests (e.g. Automation Window, Gauntlet). */
	UPROPERTY(config, EditAnywhere, Category = "General")
    TMap<FString, FString> ConsoleVariables;

    /** Console commands to execute before running batches of tests (e.g. Automation Window, Gauntlet). */
    UPROPERTY(config, EditAnywhere, Category = "General")
    TArray<FString> ConsoleCommands = {"Log LogLinker Off", "Log LogUObjectGlobals Off"};

	/** Additional information about test maps. */
	UPROPERTY(config)
    TMap<FString, FAutomationForgeTestMapMetaData> TestMapsMetaData;
    /** Additional information about unit tests. */
    UPROPERTY(config)
    TMap<FString, FAutomationForgeUnitTestMetaData> UnitTestsMetaData;

	/** Create categories and subcategories for the tests in the session frontend. */
	UPROPERTY(config, EditAnywhere, Category = "Session Frontend")
	bool bUseFolderStructureAsCategories = false;

	/** Global settings for each test. */
	UPROPERTY(config, EditAnywhere, Category = "Global Settings")
	FAutomationForgeTestMapSettings GlobalTestMapSettings;

    UAutomationForgeTestAutomationPluginSettings();
	
	static void SetTestMapMetaData(const AActor* TestActor,
                                   const FAutomationForgeTestMapMetaData& TestMetaData);
    static void SetUnitTestMetaData(const UObject* UnitTest,
                                    const FAutomationForgeUnitTestMetaData& TestMetaData);

    virtual void PostInitProperties() override;

#if WITH_EDITOR
    virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif

    /** Event when the set of test maps has changed. */
    FAutomationForgeTestAutomationPluginSettingsTestMapsChangedSignature OnTestMapsChanged;

    /** Checks whether the specified map contains automated tests to run. */
    bool IsTestMap(const FString& FileName, const FName& MapName) const;
};


