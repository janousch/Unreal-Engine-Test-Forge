//#include "Settings/TestForgeTestAutomationPluginSettings.h"
//#include "TestForgeTestLogCategory.h"
//#if WITH_EDITOR
//#include <Widgets/Notifications/SNotificationList.h>
//#include <Framework/Notifications/NotificationManager.h>
//#include <EditorStyle.h>
//#endif
//
//UTestForgeTestAutomationPluginSettings::UTestForgeTestAutomationPluginSettings()
//{
//}
//
//void UTestForgeTestAutomationPluginSettings::SetTestMapMetaData(const AActor* TestActor, const FTestForgeTestMapMetaData& TestMetaData)
//{
//	UTestForgeTestAutomationPluginSettings* Settings = GetMutableDefault<UTestForgeTestAutomationPluginSettings>();
//	const FString TestName = TestActor->GetWorld()->GetName();
//	if (Settings->TestMapsMetaData.Contains(TestName))
//	{
//		Settings->TestMapsMetaData[TestName] = TestMetaData;
//	}
//	else
//	{
//		Settings->TestMapsMetaData.Add(TestName, TestMetaData);
//	}
//	Settings->UpdateDefaultConfigFile();
//}
//
//void UTestForgeTestAutomationPluginSettings::SetUnitTestMetaData(const UObject* UnitTest,
//    const FTestForgeUnitTestMetaData& TestMetaData)
//{
//    UTestForgeTestAutomationPluginSettings* Settings =
//        GetMutableDefault<UTestForgeTestAutomationPluginSettings>();
//    const FString PathName = UnitTest->GetPackage()->GetPathName();
//    const FString TestName = FPaths::GetBaseFilename(PathName);
//    if (Settings->UnitTestsMetaData.Contains(TestName))
//    {
//        Settings->UnitTestsMetaData[TestName] = TestMetaData;
//    }
//    else
//    {
//        Settings->UnitTestsMetaData.Add(TestName, TestMetaData);
//    }
//    Settings->UpdateDefaultConfigFile();
//}
//
//void UTestForgeTestAutomationPluginSettings::PostInitProperties()
//{
//    Super::PostInitProperties();
//
//    // Backwards compatibility.
//    if (!TestMapPath.IsEmpty())
//    {
//        TestMapFolders.AddUnique(TestMapPath);
//        TestMapPath = TEXT("");
//
//        UE_LOG(LogTestForgeTest, Warning,
//               TEXT("Found deprecated configuration value TestMapPath in TestForgedalic Test Automation "
//                    "Plugin settings. We have automatically upgraded your settings to use "
//                    "TestMapFolders instead. Please review and save your changes before upgrading "
//                    "to future versions of the plugin."));
//    }
//}
//
//#if WITH_EDITOR
//void UTestForgeTestAutomationPluginSettings::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
//{
//	UObject::PostEditChangeChainProperty(PropertyChangedEvent);
//
//	const FName PropertyName = PropertyChangedEvent.GetPropertyName();
//	const FName PropertyHead = PropertyChangedEvent.PropertyChain.GetHead()->GetValue()->GetFName();
//	const FName PropertyTail = PropertyChangedEvent.PropertyChain.GetTail()->GetValue()->GetFName();
//	if (PropertyName == GET_MEMBER_NAME_CHECKED(UTestForgeTestAutomationPluginSettings, TestMapFolders) ||
//		PropertyName == GET_MEMBER_NAME_CHECKED(UTestForgeTestAutomationPluginSettings, AdditionalTestMaps) ||
//		PropertyName == GET_MEMBER_NAME_CHECKED(UTestForgeTestAutomationPluginSettings, IgnoredMaps))
//	{
//		OnTestMapsChanged.Broadcast();
//	}
//	else if (PropertyHead == GET_MEMBER_NAME_CHECKED(UTestForgeTestAutomationPluginSettings, GlobalTestMapSettings))
//    {
//        // Notify the user to restart the editor.
//        FNotificationInfo NotificationInfo(FText::FromString(
//            TEXT("Unreal Editor must be restarted for the plugin changes to take effect.")));
//        NotificationInfo.ExpireDuration = 2.f;
//        TSharedPtr<SNotificationItem> Notification =
//            FSlateNotificationManager::Get().AddNotification(NotificationInfo);
//        Notification->ExpireAndFadeout();
//
//        if (PropertyTail == GET_MEMBER_NAME_CHECKED(FTestForgeTestMapSettings, bSuppressLogs))
//        {
//            if (GlobalTestMapSettings.bSuppressLogs)
//            {
//                GlobalTestMapSettings.bSuppressLogErrors = true;
//                GlobalTestMapSettings.bSuppressLogWarnings = true;
//                GlobalTestMapSettings.bElevateLogWarningsToErrors = false;
//            }
//        }
//	}
//}
//#endif
//
//bool UTestForgeTestAutomationPluginSettings::IsTestMap(const FString& FileName,
//                                                 const FName& MapName) const
//{
//    bool bIsTestMap = false;
//
//    for (const FString& TestMapFolder : TestMapFolders)
//    {
//        const FString PatternToCheck = FString::Printf(TEXT("/%s/"), *TestMapFolder);
//        bIsTestMap = bIsTestMap || FileName.Contains(*PatternToCheck);
//    }
//
//    bIsTestMap = bIsTestMap || AdditionalTestMaps.Contains(MapName);
//    bIsTestMap = bIsTestMap && !IgnoredMaps.Contains(MapName);
//
//    return bIsTestMap;
//}
//
