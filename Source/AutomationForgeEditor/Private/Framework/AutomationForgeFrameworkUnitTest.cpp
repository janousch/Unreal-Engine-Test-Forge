//#include "AutomationTestFramework/AutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest.h"
//#include "AutomationTestFramework/AutomationForgeTestAutomationPluginAutomationTestFrameworkCommands.h"
//#include "AutomationForgeTestEditorLogCategory.h"
//#include "AutomationForgeUnitTest.h"
//#include "Settings/AutomationForgeTestAutomationPluginSettings.h"
//#include <Misc/Paths.h>
//#include <Tests/AutomationEditorCommon.h>
//
//FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::
//    FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest(
//	const FString& InUnitTestName, const FAutomationForgeUnitTestMetaData& InTestMetaData)
//    : FAutomationTestBase(InUnitTestName, false)
//    , UnitTestName(InUnitTestName)
//    , TestMetaData(InTestMetaData)
//{
//    // Test is automatically registered in FAutomationTestBase base class constructor.
//
//    const UAutomationForgeTestAutomationPluginSettings* TestAutomationPluginSettings =
//        GetMutableDefault<UAutomationForgeTestAutomationPluginSettings>();
//    UnitTestSettings = TestAutomationPluginSettings->GlobalTestMapSettings;
//
//    for (const auto& ExpectedError : TestMetaData.ExpectedErrors)
//    {
//        AddExpectedError(ExpectedError.ExpectedErrorPattern,
//                         EAutomationExpectedErrorFlags::Contains, ExpectedError.Occurrences);
//    }
//    
//    if (TestMetaData.UnitTestBlueprintClass.ToSoftObjectPath().IsValid())
//    {
//        Context.UnitTestClass = TestMetaData.UnitTestBlueprintClass;
//    }
//}
//
//bool FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::SuppressLogErrors()
//{
//    return UnitTestSettings.bSuppressLogErrors;
//}
//
//bool FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::SuppressLogWarnings()
//{
//    return UnitTestSettings.bSuppressLogWarnings;
//}
//
//bool FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::SuppressLogs()
//{
//    return UnitTestSettings.bSuppressLogs;
//}
//
//bool FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::ElevateLogWarningsToErrors()
//{
//    return UnitTestSettings.bElevateLogWarningsToErrors;
//}
//
//uint32 FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::GetTestFlags() const
//{
//    return TestMetaData.AutomationTestFlags;
//}
//
//uint32 FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::GetRequiredDeviceNum() const
//{
//    return TestMetaData.RequiredDeviceNum;
//}
//
//FString FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::GetTestSourceFileName() const
//{
//    return GetUnitTestName();
//}
//
//int32 FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::GetTestSourceFileLine() const
//{
//    return 0;
//}
//
//FString FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::GetUnitTestName() const
//{
//    return UnitTestName;
//}
//
//void FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::GetTests(
//    TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
//{
//    OutBeautifiedNames.Add(GetBeautifiedTestName());
//    OutTestCommands.Add(FString());
//}
//
//bool FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::RunTest(const FString& Parameters)
//{
//    UE_LOG(LogAutomationForgeTestEditor, Display, TEXT("Running test for: %s"), *UnitTestName);
//    
//    const FString AssetPathString = Context.UnitTestClass.ToSoftObjectPath().GetAssetPathString();
//    if (AssetPathString.IsEmpty())
//    {
//        UE_LOG(LogAutomationForgeTestEditor, Warning, TEXT("Missing UnitTestClass for: %s"), *UnitTestName);
//
//        return false;
//    }
//    const UClass* UnitTestClass = LoadObject<UClass>(nullptr, *AssetPathString);
//    if (!IsValid(UnitTestClass))
//    {
//        return false;
//    }
//    Context.CurTest = this;
//    Context.CurrentUnitTest = NewObject<UAutomationForgeUnitTest>(GetTransientPackage(), UnitTestClass);
//
//    ADD_LATENT_AUTOMATION_COMMAND(FAutomationForgeTestAutomationPluginApplyConsoleVariables(Context));
//    Context.CurrentUnitTest->RunTest(nullptr);
//    ADD_LATENT_AUTOMATION_COMMAND(FAutomationForgeTestAutomationPluginWaitForEndOfUnitTest(Context));
//	ADD_LATENT_AUTOMATION_COMMAND(FAutomationForgeTestAutomationPluginRevertConsoleVariables(Context));
//	ADD_LATENT_AUTOMATION_COMMAND(FAutomationForgeTestAutomationPluginCleanUp(Context));
//
//    return true;
//}
//
//FString FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest::GetBeautifiedTestName() const
//{
//    FString BeautifiedTestName = FPaths::GetBaseFilename(UnitTestName);
//
//	const UAutomationForgeTestAutomationPluginSettings* TestAutomationPluginSettings = GetMutableDefault<UAutomationForgeTestAutomationPluginSettings>();
//	// Use the folder path of the test to create categories.
//	if (TestAutomationPluginSettings->bUseFolderStructureAsCategories)
//	{
//        FString TestPath = FPaths::GetPath(UnitTestName);
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
