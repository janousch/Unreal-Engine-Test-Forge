//#include "TestForgeUnitTest.h"
//#include "TestForgeTestAssertBlueprintFunctionLibrary.h"
//#include "TestForgeTestLogCategory.h"
//#include "TestForgeTestReportWriterJUnit.h"
//#include "TestForgeTestResult.h"
//#include "Settings/TestForgeTestAutomationPluginSettings.h"
//
//bool UTestForgeUnitTest::bIsAutomationUnitTesting = false;
//
//bool UTestForgeUnitTest::AreAutomatedUnitTestsRunning()
//{
//    return bIsAutomationUnitTesting;
//}
//
//UTestForgeUnitTest::UTestForgeUnitTest(
//    const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
//    : Super(ObjectInitializer)
//{
//    TimeoutInSeconds = 5.0f;
//}
//
//UWorld* UTestForgeUnitTest::GetWorld() const
//{
//    return TestWorld;
//}
//
//void UTestForgeUnitTest::RunTest(UObject* TestParameter)
//{
//    bIsAutomationUnitTesting = true;
//
//    TestWorld = UWorld::CreateWorld(EWorldType::None, false, TEXT("TestWorld"));
//
//    CurrentParameter = TestParameter;
//    bHasResult = false;
//    bHadTimeout = false;
//
//    if (!SkipReason.IsEmpty())
//    {
//        NotifyOnTestSkipped(SkipReason);
//        return;
//    }
//
//    NotifyOnAssume(CurrentParameter);
//
//    if (bHasResult)
//    {
//        // This can happen with failed assumptions, for instance.
//        return;
//    }
//
//    NotifyOnArrange(CurrentParameter);
//    NotifyOnAct(CurrentParameter);
//}
//
//bool UTestForgeUnitTest::IsRunning() const
//{
//    return !bHasResult;
//}
//
//void UTestForgeUnitTest::FinishAct()
//{
//    if (bHasResult)
//    {
//        UE_LOG(LogTestForgeTest, Warning,
//               TEXT("Test %s already has a result. This can happen after a timeout due to delays, "
//                    "but if not, make sure not to call FinishAct more than once."),
//               *GetName());
//        return;
//    }
//
//    auto* ActiveParam = CurrentParameter;
//
//    NotifyOnAssert(CurrentParameter);
//
//    if (!bHasResult && (ActiveParam == CurrentParameter))
//    {
//        NotifyOnTestSuccessful();
//    }
//
//    TestWorld->DestroyWorld(false);
//    TestWorld = nullptr;
//
//    bIsAutomationUnitTesting = false;
//}
//
//const FTestForgeTestSuiteResult& UTestForgeUnitTest::GetResult() const
//{
//    return Result;
//}
//
//float UTestForgeUnitTest::GetTimeoutInSeconds() const
//{
//    return TimeoutInSeconds;
//}
//
//void UTestForgeUnitTest::Timeout()
//{
//    // Enough waiting. Let's see the results.
//    UE_LOG(LogTestForgeTest, Warning, TEXT("Timed out after %f seconds"), GetTimeoutInSeconds());
//
//    bHadTimeout = true;
//
//    FinishAct();
//}
//
//TArray<TSoftObjectPtr<UObject>> UTestForgeUnitTest::GetParameters() const
//{
//    return Parameters;
//}
//
//UObject* UTestForgeUnitTest::GetCurrentParameter() const
//{
//    return CurrentParameter;
//}
//
//TSharedPtr<FTestForgeTestResultData> UTestForgeUnitTest::CollectResults() const
//{
//    return MakeShareable(new FTestForgeTestResultData());
//}
//
//FTestForgeTestReportWriterSet UTestForgeUnitTest::GetReportWriters() const
//{
//    FTestForgeTestReportWriterSet ReportWriters;
//    ReportWriters.Add(MakeShareable(new FTestForgeTestReportWriterJUnit()));
//    return ReportWriters;
//}
//
//void UTestForgeUnitTest::NotifyOnTestSuccessful()
//{
//    if (bHasResult)
//    {
//        return;
//    }
//
//    bHasResult = true;
//
//    OnTestSuccessful.Broadcast(this, CurrentParameter);
//}
//
//void UTestForgeUnitTest::NotifyOnTestFailed(const FString& Message)
//{
//    if (bHasResult)
//    {
//        return;
//    }
//
//    bHasResult = true;
//
//    UE_LOG(LogTestForgeTest, Error, TEXT("%s"), *Message);
//
//    OnTestFailed.Broadcast(this, CurrentParameter, Message);
//}
//
//void UTestForgeUnitTest::NotifyOnTestSkipped(const FString& InSkipReason)
//{
//    if (bHasResult)
//    {
//        return;
//    }
//
//    bHasResult = true;
//
//    OnTestSkipped.Broadcast(this, CurrentParameter, InSkipReason);
//}
//
//void UTestForgeUnitTest::NotifyOnAssume(UObject* Parameter)
//{
//    ReceiveOnAssume(Parameter);
//}
//
//void UTestForgeUnitTest::NotifyOnArrange(UObject* Parameter)
//{
//    ReceiveOnArrange(Parameter);
//}
//
//void UTestForgeUnitTest::NotifyOnAct(UObject* Parameter)
//{
//    ReceiveOnAct(Parameter);
//}
//
//void UTestForgeUnitTest::NotifyOnAssert(UObject* Parameter)
//{
//    UTestForgeTestAssertBlueprintFunctionLibrary::AssertFalse(bHadTimeout,
//                                                        TEXT("The test had a timeout."), this);
//														
//    ReceiveOnAssert(Parameter);
//}
//
//#if WITH_EDITOR
//void UTestForgeUnitTest::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
//{
//    UObject::PostEditChangeProperty(PropertyChangedEvent);
//
//    // Should this be called on Modify, to make sure the blueprint path is correct?
//    UpdateMetaData();
//}
//
//void UTestForgeUnitTest::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
//{
//	Super::PostEditChangeChainProperty(PropertyChangedEvent);
//
//    // Should this be called on Modify, to make sure the blueprint path is correct?
//    UpdateMetaData();
//    
//	/*const FName PropertyName = PropertyChangedEvent.GetPropertyName();
//	const FName PropertyHead = PropertyChangedEvent.PropertyChain.GetHead()->GetValue()->GetFName();
//	const FName PropertyTail = PropertyChangedEvent.PropertyChain.GetTail()->GetValue()->GetFName();
//    if (PropertyHead == GET_MEMBER_NAME_CHECKED(UTestForgeUnitTest, UnitTestMetaData))
//	{
//        UpdateMetaData();
//	}*/
//}
//#endif
//
//UWorld* UTestForgeUnitTest::GetTestWorld() const
//{
//    return TestWorld;
//}
//
//void UTestForgeUnitTest::UpdateMetaData()
//{
//    FString BlueprintClassPath = GetPathName();
//    BlueprintClassPath = BlueprintClassPath.Replace(TEXT("Default__"), TEXT(""));
//    UnitTestMetaData.UnitTestBlueprintClass = LoadObject<UClass>(nullptr, *BlueprintClassPath);
//    UTestForgeTestAutomationPluginSettings::SetUnitTestMetaData(this, UnitTestMetaData);
//}
//
//void UTestForgeUnitTest::ReceiveOnAct_Implementation(UObject* Parameter)
//{
//    FinishAct();
//}
//
