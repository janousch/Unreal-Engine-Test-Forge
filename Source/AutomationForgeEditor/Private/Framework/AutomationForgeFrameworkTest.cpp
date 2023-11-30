//#include "AutomationTestFramework/AutomationForgeTestAutomationPluginAutomationTestFrameworkTest.h"
//#include "AutomationTestFramework/AutomationForgeTestAutomationPluginAutomationTestFrameworkCommands.h"
//#include "AutomationForgeTestEditorLogCategory.h"
//#include "Settings/AutomationForgeTestAutomationPluginSettings.h"
//#include <Misc/Paths.h>
//#include <Tests/AutomationEditorCommon.h>
//
//FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest(
//	const FString& InMapName, const FAutomationForgeTestMapMetaData& InMapMetaData)
//	: FAutomationTestBase(InMapName, false), MapName(InMapName), MapMetaData(InMapMetaData)
//{
//    // Test is automatically registered in FAutomationTestBase base class constructor.
//
//    const UAutomationForgeTestAutomationPluginSettings* TestAutomationPluginSettings =
//        GetMutableDefault<UAutomationForgeTestAutomationPluginSettings>();
//    TestMapSettings = TestAutomationPluginSettings->GlobalTestMapSettings;
//
//    for (const auto& ExpectedError : MapMetaData.ExpectedErrors)
//    {
//        AddExpectedError(ExpectedError.ExpectedErrorPattern,
//                         EAutomationExpectedErrorFlags::Contains, ExpectedError.Occurrences);
//    }
//}
//
//bool FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::SuppressLogErrors()
//{
//	return TestMapSettings.bSuppressLogErrors;
//}
//
//bool FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::SuppressLogWarnings()
//{
//	return TestMapSettings.bSuppressLogWarnings;
//}
//
//bool FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::SuppressLogs()
//{
//	return TestMapSettings.bSuppressLogs;
//}
//
//bool FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::ElevateLogWarningsToErrors()
//{
//	return TestMapSettings.bElevateLogWarningsToErrors;
//}
//
//uint32 FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::GetTestFlags() const
//{
//    return EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter;
//}
//
//uint32 FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::GetRequiredDeviceNum() const
//{
//    return 1;
//}
//
//FString FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::GetTestSourceFileName() const
//{
//    return GetMapName();
//}
//
//int32 FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::GetTestSourceFileLine() const
//{
//    return 0;
//}
//
//FString FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::GetMapName() const
//{
//    return MapName;
//}
//
//void FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::GetTests(
//    TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
//{
//    OutBeautifiedNames.Add(GetBeautifiedTestName());
//    OutTestCommands.Add(FString());
//}
//
//bool FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::RunTest(const FString& Parameters)
//{
//    UE_LOG(LogAutomationForgeTestEditor, Display, TEXT("Running test for map: %s"), *MapName);
//
//    Context.CurrentTestSuite = nullptr;
//    Context.CurTest = this;
//
//    ADD_LATENT_AUTOMATION_COMMAND(FAutomationForgeTestAutomationPluginApplyConsoleVariables(Context));
//    ADD_LATENT_AUTOMATION_COMMAND(FEditorLoadMap(MapName));
//    ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(false));
//    ADD_LATENT_AUTOMATION_COMMAND(FAutomationForgeTestAutomationPluginWaitForEndOfTestSuite(Context));
//    ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand());
//	ADD_LATENT_AUTOMATION_COMMAND(FAutomationForgeTestAutomationPluginRevertConsoleVariables(Context));
//	ADD_LATENT_AUTOMATION_COMMAND(FAutomationForgeTestAutomationPluginCleanUp(Context));
//
//    return true;
//}
//
//FString FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest::GetBeautifiedTestName() const
//{
//	FString BeautifiedTestName = FPaths::GetBaseFilename(MapName);
//
//	const UAutomationForgeTestAutomationPluginSettings* TestAutomationPluginSettings = GetMutableDefault<UAutomationForgeTestAutomationPluginSettings>();
//	// Use the folder path of the test to create categories.
//	if (TestAutomationPluginSettings->bUseFolderStructureAsCategories)
//	{
//		FString TestPath = FPaths::GetPath(MapName);
//		// Remains false if the test is one of the AdditionalTestMaps.
//        bool bHasFoundTestInTestMapFolders = false;
//		for (auto& TestFolderName : TestAutomationPluginSettings->TestMapFolders)
//		{
//            bHasFoundTestInTestMapFolders = TestPath.Contains(TestFolderName);
//            if (bHasFoundTestInTestMapFolders)
//			{
//				FString RelativePath;
//				TestPath.Split(*TestFolderName, &RelativePath, &TestPath);
//				break;
//			}
//		}
//        if (bHasFoundTestInTestMapFolders)
//        {
//            TestPath = TestPath.Replace(TEXT("/"), TEXT("."));
//            BeautifiedTestName = TEXT("JanouschTestAutomationPlugin") + TestPath + TEXT(".")
//                                 + BeautifiedTestName;
//
//            return BeautifiedTestName;
//        }
//	}
//
//	return TEXT("JanouschTestAutomationPlugin.") + BeautifiedTestName;
//}
//
//
