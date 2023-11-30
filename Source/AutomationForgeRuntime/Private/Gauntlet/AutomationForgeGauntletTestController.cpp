//#include "AutomationForgeGauntletTestController.h"
//#include "AutomationForgeGauntletStates.h"
//#include "AutomationForgeTestLogCategory.h"
//#include "AutomationForgeTestReportWriter.h"
//#include "AutomationForgeTestReportWriterSet.h"
//#include "AutomationForgeTestSuiteActor.h"
//#include "Settings/AutomationForgeTestAutomationPluginSettings.h"
//#include <AssetRegistryModule.h>
//#include <EngineUtils.h>
//#include <Engine/AssetManager.h>
//#include <Kismet/GameplayStatics.h>
//
//void UAutomationForgeGauntletTestController::OnInit()
//{
//    Super::OnInit();
//
//    // Get tests path.
//    const UAutomationForgeTestAutomationPluginSettings* TestAutomationPluginSettings =
//        GetDefault<UAutomationForgeTestAutomationPluginSettings>();
//
//    // Execute console commands.
//    for (auto& ConsoleCommand : TestAutomationPluginSettings->ConsoleCommands)
//    {
//        GEngine->Exec(GetWorld(), *ConsoleCommand);
//        UE_LOG(LogAutomationForgeTest, Log, TEXT("UAutomationForgeGauntletTestController: Executed console command %s"),
//               *ConsoleCommand);
//    }
//
//    for (const FString& TestMapFolder : TestAutomationPluginSettings->TestMapFolders)
//    {
//        UE_LOG(LogAutomationForgeTest, Display, TEXT("Discovering tests from: %s"), *TestMapFolder);
//    }
//
//    // Build list of tests (based on FAutomationEditorCommonUtils::CollectTestsByClass).
//    FAssetRegistryModule& AssetRegistryModule =
//        FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
//    TArray<FAssetData> AssetDataArray;
//
//    AssetRegistryModule.Get().SearchAllAssets(true);
//    AssetRegistryModule.Get().GetAssetsByClass(UWorld::StaticClass()->GetFName(), AssetDataArray);
//
//    for (auto ObjIter = AssetDataArray.CreateConstIterator(); ObjIter; ++ObjIter)
//    {
//        const FAssetData& AssetData = *ObjIter;
//
//        FString FileName = FPackageName::LongPackageNameToFilename(AssetData.ObjectPath.ToString());
//        FName MapName = AssetData.AssetName;
//
//        const bool bIsTestMap = TestAutomationPluginSettings->IsTestMap(FileName, MapName);
//
//        if (bIsTestMap)
//        {
//            MapNames.Add(MapName);
//
//            UE_LOG(LogAutomationForgeTest, Display, TEXT("Discovered test: %s"), *MapName.ToString());
//        }
//    }
//
//    // Set console variables.
//    for (auto& ConsoleVariable : TestAutomationPluginSettings->ConsoleVariables)
//    {
//        IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(*ConsoleVariable.Key);
//
//        if (CVar)
//        {
//            CVar->Set(*ConsoleVariable.Value);
//
//            UE_LOG(LogAutomationForgeTest, Log, TEXT("Setting console variable %s = %s"),
//                   *ConsoleVariable.Key,
//                   *ConsoleVariable.Value);
//        }
//    }
//
//    GetGauntlet()->BroadcastStateChange(FAutomationForgeGauntletStates::Initialized);
//}
//
//void UAutomationForgeGauntletTestController::OnPostMapChange(UWorld* World)
//{
//    Super::OnPostMapChange(World);
//
//    UE_LOG(LogAutomationForgeTest, Log, TEXT("UAutomationForgeGauntletTestController::OnPostMapChange - World: %s"),
//           *World->GetName());
//
//    if (GetCurrentState() != FAutomationForgeGauntletStates::LoadingNextMap)
//    {
//        return;
//    }
//
//    GetGauntlet()->BroadcastStateChange(FAutomationForgeGauntletStates::DiscoveringTests);
//}
//
//void UAutomationForgeGauntletTestController::OnTick(float TimeDelta)
//{
//    if (GetCurrentState() == FAutomationForgeGauntletStates::Initialized)
//    {
//        // If this isn't a test map (e.g. immediately after startup), load first test map now.
//        if (!MapNames.Contains(FName(*GetCurrentMap())))
//        {
//            UE_LOG(LogAutomationForgeTest, Log,
//                   TEXT("FAutomationForgeGauntletStates::Initialized - World is not a test world, "
//                        "loading first test world."));
//
//            MapIndex = -1;
//            LoadNextTestMap();
//            return;
//        }
//        else
//        {
//            GetGauntlet()->BroadcastStateChange(FAutomationForgeGauntletStates::DiscoveringTests);
//        }
//    }
//    else if (GetCurrentState() == FAutomationForgeGauntletStates::LoadingNextMap)
//    {
//        UE_LOG(LogGauntlet, Display,
//               TEXT("FAutomationForgeGauntletStates::LoadingNextMap - Loading map: %s (%d/%d)"),
//               *MapNames[MapIndex].ToString(), (MapIndex + 1), MapNames.Num());
//
//        UGameplayStatics::OpenLevel(this, MapNames[MapIndex]);
//    }
//    else if (GetCurrentState() == FAutomationForgeGauntletStates::DiscoveringTests)
//    {
//        // Find test suite.
//        AAutomationForgeTestSuiteActor* TestSuite = nullptr;
//
//        for (TActorIterator<AAutomationForgeTestSuiteActor> ActorIt(GetWorld()); ActorIt; ++ActorIt)
//        {
//            TestSuite = *ActorIt;
//        }
//
//        if (!IsValid(TestSuite))
//        {
//            UE_LOG(LogAutomationForgeTest, Error,
//                   TEXT("FAutomationForgeGauntletStates::DiscoveringTests - No "
//                        "AutomationForgeGauntletTestSuiteActor "
//                        "found."));
//            LoadNextTestMap();
//            return;
//        }
//
//        // Start first test.
//        GetGauntlet()->BroadcastStateChange(FAutomationForgeGauntletStates::Running);
//
//        TestSuite->OnTestSuiteSuccessful.AddDynamic(
//            this, &UAutomationForgeGauntletTestController::OnTestSuiteFinished);
//        TestSuite->OnTestSuiteFailed.AddDynamic(this,
//                                                &UAutomationForgeGauntletTestController::OnTestSuiteFinished);
//
//        TestSuite->RunAllTests();
//    }
//}
//
//void UAutomationForgeGauntletTestController::LoadNextTestMap()
//{
//    ++MapIndex;
//
//	// Gather command line options.
//	const FString SingleTestName = ParseCommandLineOption(TEXT("TestName"));
//	const FString TestTagsString = ParseCommandLineOption(TEXT("TestTags"));
//	const FString TestPriorityString = ParseCommandLineOption(TEXT("TestPriority"));
//
//    // Check if we just want to run a single test.
//    if (!SingleTestName.IsEmpty())
//    {
//        // Increment MapIndex until we found the map.
//        while (MapNames.IsValidIndex(MapIndex) && MapNames[MapIndex].ToString() != SingleTestName)
//        {
//            ++MapIndex;
//        }
//    }
//	else if (!TestTagsString.IsEmpty())
//	{
//		// Check if we just want to run tests with a given tag.
//		TArray<FString> RequiredTestTags;
//		const TCHAR* TagSeparator = TEXT(";");
//		TestTagsString.ParseIntoArray(RequiredTestTags, TagSeparator);
//		if (RequiredTestTags.Num() > 0)
//		{
//			bool bHasFoundTagInTest = false;
//            while (!bHasFoundTagInTest)
//            {
//                // Found no test map with the required tag.
//				if (!MapNames.IsValidIndex(MapIndex))
//				{
//					break;
//				}
//
//                const FString TestName = FPaths::GetBaseFilename(MapNames[MapIndex].ToString());
//                bHasFoundTagInTest = DoesMapHasTag(TestName, RequiredTestTags);
//
//				if (!bHasFoundTagInTest)
//				{
//					++MapIndex;
//				}
//            }
//		}
//	}
//	if (!TestPriorityString.IsEmpty())
//    {
//        const UAutomationForgeTestAutomationPluginSettings* TestAutomationPluginSettings =
//            GetDefault<UAutomationForgeTestAutomationPluginSettings>();
//        const TMap<FString, FAutomationForgeTestMapMetaData>& TestMapsMetaData =
//            TestAutomationPluginSettings->TestMapsMetaData;
//
//        const EAutomationForgeTestPriority RequiredPriority = ConvertStringToPriority(TestPriorityString);
//		bool bHasTestRequiredPriority = false;
//		while (!bHasTestRequiredPriority)
//		{
//			// Found no test map with the required tag.
//			if (!MapNames.IsValidIndex(MapIndex))
//			{
//				break;
//			}
//
//			EAutomationForgeTestPriority TestPriority = EAutomationForgeTestPriority::DTP_Default;
//			// Check if the test has a non default priority.
//            const FString TestName = FPaths::GetBaseFilename(MapNames[MapIndex].ToString());
//			if (TestMapsMetaData.Contains(TestName))
//			{
//				// Check if the test has one of the required tags.
//				TestPriority = TestMapsMetaData[TestName].Priority;
//			}
//			if (TestPriority >= RequiredPriority)
//			{
//				bHasTestRequiredPriority = true;
//			}
//
//			if (!bHasTestRequiredPriority)
//			{
//				++MapIndex;
//			}
//		}
//	}
//
//    if (MapNames.IsValidIndex(MapIndex))
//    {
//        // Load next test map in next tick. This is to avoid invocation list changes during OnPostMapChange.
//        GetGauntlet()->BroadcastStateChange(FAutomationForgeGauntletStates::LoadingNextMap);
//    }
//    else
//    {
//        // All tests finished.
//        UE_LOG(LogAutomationForgeTest, Display,
//               TEXT("UAutomationForgeGauntletTestController::LoadNextTestMap - All tests finished."));
//
//        // Finish Gauntlet.
//        GetGauntlet()->BroadcastStateChange(FAutomationForgeGauntletStates::Finished);
//
//        for (const FAutomationForgeTestSuiteResult& Result : Results)
//        {
//            if (Result.NumFailedTests() > 0)
//            {
//                EndTest(1);
//                return;
//            }
//        }
//
//        EndTest(0);
//    }
//}
//
//bool UAutomationForgeGauntletTestController::DoesMapHasTag(const FString& TestName,
//                                               const TArray<FString>& RequiredTags) const
//{
//    const UAutomationForgeTestAutomationPluginSettings* TestAutomationPluginSettings =
//        GetDefault<UAutomationForgeTestAutomationPluginSettings>();
//    const TMap<FString, FAutomationForgeTestMapMetaData>& TestMapsMetaData =
//        TestAutomationPluginSettings->TestMapsMetaData;
//    // Check if the test has tags.
//    if (TestMapsMetaData.Contains(TestName))
//    {
//        // Check if the test has one of the required tags.
//        const TArray<FString> Tags = TestMapsMetaData[TestName].Tags;
//        for (auto& Tag : Tags)
//        {
//            if (RequiredTags.Contains(Tag))
//            {
//                return true;
//            }
//        }
//    }
//
//    return false;
//}
//
//EAutomationForgeTestPriority UAutomationForgeGauntletTestController::ConvertStringToPriority(
//    const FString& TestPriorityString)
//{
//    if (TestPriorityString.Contains("Critical", ESearchCase::IgnoreCase)
//        || TestPriorityString.Equals("3"))
//    {
//        return EAutomationForgeTestPriority::DTP_CriticalPriority;
//    }
//    if (TestPriorityString.Contains("High", ESearchCase::IgnoreCase)
//        || TestPriorityString.Equals("2"))
//    {
//        return EAutomationForgeTestPriority::DTP_HighPriority;
//    }
//    if (TestPriorityString.Contains("Medium", ESearchCase::IgnoreCase)
//        || TestPriorityString.Equals("1"))
//    {
//        return EAutomationForgeTestPriority::DTP_MediumPriority;
//    }
//    if (TestPriorityString.Contains("Low", ESearchCase::IgnoreCase)
//        || TestPriorityString.Equals("0"))
//    {
//        return EAutomationForgeTestPriority::DTP_LowPriority;
//    }
//
//    return EAutomationForgeTestPriority::DTP_Default;
//}
//
//void UAutomationForgeGauntletTestController::OnTestSuiteFinished(AAutomationForgeTestSuiteActor* TestSuite)
//{
//    // Store result.
//    Results.Add(TestSuite->GetResult());
//
//    // Update test reports on disk.
//    const FString ReportPath = ParseCommandLineOption(TEXT("ReportPath"));
//
//    const FAutomationForgeTestReportWriterSet ReportWriters = TestSuite->GetReportWriters();
//
//    for (const TSharedPtr<FAutomationForgeTestReportWriter>& ReportWriter : ReportWriters.GetReportWriters())
//    {
//        ReportWriter->WriteReport(Results, ReportPath);
//    }
//
//    // Proceed with next test.
//    LoadNextTestMap();
//}
//
//FString UAutomationForgeGauntletTestController::ParseCommandLineOption(const FString& Key) const
//{
//    FString Value;
//    FParse::Value(FCommandLine::Get(), *Key, Value);
//    return Value.Mid(1);
//}
//
//
