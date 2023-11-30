//#include "AutomationTestFramework/AutomationForgeTestAutomationPluginAutomationTestFrameworkIntegration.h"
//#include "AutomationForgeTestEditorLogCategory.h"
//#include "AutomationForgeUnitTest.h"
//#include "Settings/AutomationForgeTestAutomationPluginSettings.h"
//#include <FileHelpers.h>
//#include <Misc/PackageName.h>
//#include <Misc/Paths.h>
//
//void FAutomationForgeTestAutomationPluginAutomationTestFrameworkIntegration::DiscoverTests()
//{
//    const UAutomationForgeTestAutomationPluginSettings* TestAutomationPluginSettings =
//        GetDefault<UAutomationForgeTestAutomationPluginSettings>();
//
//    for (const FString& TestMapFolder : TestAutomationPluginSettings->TestMapFolders)
//    {
//        UE_LOG(LogAutomationForgeTestEditor, Log, TEXT("Discovering tests from: %s"), *TestMapFolder);
//    }
//
//    // Unregister existing tests.
//    Tests.Empty();
//
//    // Register new tests (based on FLoadAllMapsInEditorTest).
//    TArray<FString> PackageFiles;
//    FEditorFileUtils::FindAllPackageFiles(PackageFiles);
//
//    // Iterate over all files, adding the ones with the map extension.
//    for (const FString& PackageFile : PackageFiles)
//    {
//        // Check for level tests.
//        const bool bIsMap = FPaths::GetExtension(PackageFile, true)
//                            == FPackageName::GetMapPackageExtension();
//        FName BaseFileName = FName(*FPaths::GetBaseFilename(PackageFile));
//
//        if (bIsMap && TestAutomationPluginSettings->IsTestMap(PackageFile, BaseFileName))
//        {
//            const FAutomationForgeTestMapMetaData& MapMetaData =
//                TestAutomationPluginSettings->TestMapsMetaData.FindRef(BaseFileName.ToString());
//            TSharedPtr<FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest> NewTest = MakeShareable(
//                new FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest(PackageFile, MapMetaData));
//            Tests.Add(NewTest);
//
//            UE_LOG(LogAutomationForgeTestEditor, Log, TEXT("Discovered test: %s"), *NewTest->GetMapName());
//        }
//
//        // Check for unit tests.
//        // Make sure we are dealing with a Blueprint (Asset) file
//        if (PackageFile.Contains("UnitTest"))
//        {
//            // Check if it's a subclass of UAutomationForgeUnitTest
//            //if (BlueprintClass->IsChildOf(UAutomationForgeUnitTest::StaticClass()))
//            {
//                const FAutomationForgeUnitTestMetaData& TestMetaData =
//                    TestAutomationPluginSettings->UnitTestsMetaData.FindRef(BaseFileName.ToString());
//                TSharedPtr<FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest> NewTest =
//                    MakeShareable(
//                        new FAutomationForgeTestAutomationPluginAutomationTestFrameworkUnitTest(PackageFile,
//                                                                                    TestMetaData));
//                UnitTests.Add(NewTest);
//
//                UE_LOG(LogAutomationForgeTestEditor, Log, TEXT("Discovered test: %s"),
//                       *NewTest->GetUnitTestName());
//            }
//        }
//    }
//}
//
//
