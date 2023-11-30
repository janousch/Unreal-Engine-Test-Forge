//#include "TestForgeTestSuiteActor.h"
//#include "TestForgeTestActor.h"
//#include "TestForgeTestLogCategory.h"
//#include "TestForgeTestReportWriter.h"
//#include <Engine/World.h>
//
//ATestForgeTestSuiteActor::ATestForgeTestSuiteActor(
//    const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
//{
//    bRunInPIE = true;
//    TestIndex = -1;
//
//    PrimaryActorTick.bCanEverTick = true;
//
//    // We need to be able to time out even while gameplay is paused.
//    PrimaryActorTick.bTickEvenWhenPaused = true;
//}
//
//void ATestForgeTestSuiteActor::BeginPlay()
//{
//    Super::BeginPlay();
//
//    // Setup result data.
//    Result.MapName = GetWorld()->GetMapName();
//    Result.TestSuiteName = GetName();
//    Result.Timestamp = FDateTime::UtcNow();
//}
//
//void ATestForgeTestSuiteActor::Tick(float DeltaSeconds)
//{
//    Super::Tick(DeltaSeconds);
//
//    if (!IsRunning())
//    {
//        // Check if we should run all tests immediately.
//        // Happening in first Tick to make sure all actors have begun play.
//        if (bRunInPIE && GetWorld()->IsPlayInEditor() && TestIndex < 0)
//        {
//            RunAllTests();
//        }
//
//        return;
//    }
//
//    TestTimeSeconds += DeltaSeconds;
//
//    ATestForgeTestActor* CurrentTest = GetCurrentTest();
//
//    if (TestTimeSeconds >= CurrentTest->GetTimeoutInSeconds())
//    {
//        CurrentTest->Timeout();
//    }
//}
//
//void ATestForgeTestSuiteActor::RunAllTests()
//{
//    UE_LOG(LogTestForgeTest, Display, TEXT("ATestForgeTestSuiteActor::RunAllTests - Test Suite: %s"),
//           *GetName());
//
//    NotifyOnBeforeAll();
//
//    TestIndex = -1;
//    TestParameterIndex = -1;
//
//    RunNextTest();
//}
//
//bool ATestForgeTestSuiteActor::IsRunning() const
//{
//    return IsValid(GetCurrentTest());
//}
//
//ATestForgeTestActor* ATestForgeTestSuiteActor::GetCurrentTest() const
//{
//    return Tests.IsValidIndex(TestIndex) ? Tests[TestIndex] : nullptr;
//}
//
//UObject* ATestForgeTestSuiteActor::GetCurrentTestParameter() const
//{
//    const ATestForgeTestActor* Test = GetCurrentTest();
//    if (!IsValid(Test))
//    {
//        return nullptr;
//    }
//
//    TArray<TSoftObjectPtr<UObject>> TestParameters = Test->GetParameters();
//    if (!TestParameters.IsValidIndex(TestParameterIndex))
//    {
//        return nullptr;
//    }
//    
//    UObject* Parameter = TestParameters[TestParameterIndex].LoadSynchronous();
//    if (!IsValid(Parameter))
//    {
//        return nullptr;
//    }
//
//    // If this is a reference to a Blueprint class, a default object of that Blueprint is returned.
//    const bool bIsABlueprint = Parameter->IsA(UBlueprint::StaticClass());
//    if (bIsABlueprint && Parameter->IsAsset())
//    {
//        const FString ClassSuffix = TEXT("_C");
//        const FString Name = Parameter->GetPathName() + ClassSuffix;
//        const UClass* ParameterObjectClass = LoadClass<UObject>(nullptr, *Name);
//        if (IsValid(ParameterObjectClass))
//        {
//            return ParameterObjectClass->GetDefaultObject();
//        }
//    }
//
//    return Parameter;
//}
//
//FString ATestForgeTestSuiteActor::GetCurrentTestName() const
//{
//    ATestForgeTestActor* Test = GetCurrentTest();
//
//    if (!IsValid(Test))
//    {
//        return FString();
//    }
//
//    FString TestName = Test->GetName();
//
//    UObject* Parameter = GetCurrentTestParameter();
//
//    if (IsValid(Parameter))
//    {
//        TestName += TEXT(" - ") + Parameter->GetName();
//    }
//
//    return TestName;
//}
//
//const FTestForgeTestSuiteResult& ATestForgeTestSuiteActor::GetResult() const
//{
//    return Result;
//}
//
//FTestForgeTestReportWriterSet ATestForgeTestSuiteActor::GetReportWriters() const
//{
//    FTestForgeTestReportWriterSet ReportWriters;
//
//    for (ATestForgeTestActor* Test : Tests)
//    {
//        ReportWriters.Add(Test->GetReportWriters());
//    }
//
//    return ReportWriters;
//}
//
//void ATestForgeTestSuiteActor::NotifyOnBeforeAll()
//{
//    ReceiveOnBeforeAll();
//}
//
//void ATestForgeTestSuiteActor::NotifyOnAfterAll()
//{
//    ReceiveOnAfterAll();
//}
//
//void ATestForgeTestSuiteActor::NotifyOnBeforeEach()
//{
//    ReceiveOnBeforeEach();
//}
//
//void ATestForgeTestSuiteActor::NotifyOnAfterEach()
//{
//    ReceiveOnAfterEach();
//}
//
//void ATestForgeTestSuiteActor::RunNextTest()
//{
//    ATestForgeTestActor* CurrentTest = GetCurrentTest();
//
//    // Unregister events.
//    if (IsValid(CurrentTest))
//    {
//        CurrentTest->OnTestSuccessful.RemoveDynamic(this, &ATestForgeTestSuiteActor::OnTestSuccessful);
//        CurrentTest->OnTestFailed.RemoveDynamic(this, &ATestForgeTestSuiteActor::OnTestFailed);
//        CurrentTest->OnTestSkipped.RemoveDynamic(this, &ATestForgeTestSuiteActor::OnTestSkipped);
//    }
//
//    // Prepare test run with next parameter.
//    ++TestParameterIndex;
//
//    UObject* CurrentTestParameter = GetCurrentTestParameter();
//
//    if (!IsValid(CurrentTestParameter))
//    {
//        // Prepare next test.
//        ++TestIndex;
//        TestParameterIndex = 0;
//
//        // Apply parameter providers.
//        ATestForgeTestActor* NextTest = GetCurrentTest();
//
//        if (IsValid(NextTest))
//        {
//            NextTest->ApplyParameterProviders();
//        }
//    }
//
//    TestTimeSeconds = 0.0f;
//
//    if (!Tests.IsValidIndex(TestIndex))
//    {
//        // All tests finished.
//        UE_LOG(LogTestForgeTest, Display, TEXT("ATestForgeTestSuiteActor::RunNextTest - All tests finished."));
//
//        NotifyOnAfterAll();
//
//        // Check if any test failed.
//        for (const FTestForgeTestResult& TestResult : Result.TestResults)
//        {
//            if (!TestResult.FailureMessage.IsEmpty())
//            {
//                OnTestSuiteFailed.Broadcast(this);
//                return;
//            }
//        }
//
//        OnTestSuiteSuccessful.Broadcast(this);
//        return;
//    }
//
//    ATestForgeTestActor* Test = GetCurrentTest();
//
//    if (IsValid(Test))
//    {
//        FString TestName = GetCurrentTestName();
//        UE_LOG(LogTestForgeTest, Display, TEXT("ATestForgeTestSuiteActor::RunNextTest - Test: %s"), *TestName);
//
//        // Register events.
//        Test->OnTestSuccessful.AddDynamic(this, &ATestForgeTestSuiteActor::OnTestSuccessful);
//        Test->OnTestFailed.AddDynamic(this, &ATestForgeTestSuiteActor::OnTestFailed);
//        Test->OnTestSkipped.AddDynamic(this, &ATestForgeTestSuiteActor::OnTestSkipped);
//
//        // Run test.
//        NotifyOnBeforeEach();
//
//        UObject* TestParameter = GetCurrentTestParameter();
//        Test->RunTest(TestParameter);
//    }
//    else
//    {
//        UE_LOG(LogTestForgeTest, Error,
//               TEXT("ATestForgeTestSuiteActor::RunNextTest - %s has invalid test at index %i, skipping."),
//               *GetName(), TestIndex);
//
//        RunNextTest();
//    }
//}
//
//void ATestForgeTestSuiteActor::OnTestSuccessful(ATestForgeTestActor* Test, UObject* Parameter)
//{
//    if (Test != GetCurrentTest())
//    {
//        // Prevent tests from reporting multiple results.
//        return;
//    }
//
//    FString CurrentTestName = GetCurrentTestName();
//
//    UE_LOG(LogTestForgeTest, Display, TEXT("ATestForgeTestSuiteActor::OnTestSuccessful - Test: %s"),
//           *CurrentTestName);
//
//    // Store result.
//    FTestForgeTestResult TestResult(CurrentTestName, TestTimeSeconds);
//    TestResult.Data = Test->CollectResults();
//
//    Result.TestResults.Add(TestResult);
//
//    // Run next test.
//    NotifyOnAfterEach();
//
//    RunNextTest();
//}
//
//void ATestForgeTestSuiteActor::OnTestFailed(ATestForgeTestActor* Test, UObject* Parameter,
//                                      const FString& FailureMessage)
//{
//    if (Test != GetCurrentTest())
//    {
//        // Prevent tests from reporting multiple results.
//        return;
//    }
//
//    const FString CurrentTestName = GetCurrentTestName();
//
//    UE_LOG(LogTestForgeTest, Error,
//           TEXT("ATestForgeTestSuiteActor::OnTestFailed - Test: %s, FailureMessage: %s"),
//           *CurrentTestName, *FailureMessage);
//
//    // Store result.
//    FTestForgeTestResult TestResult(CurrentTestName, TestTimeSeconds);
//    TestResult.FailureMessage = FailureMessage;
//    TestResult.Data = Test->CollectResults();
//
//    Result.TestResults.Add(TestResult);
//
//    // Run next test.
//    NotifyOnAfterEach();
//
//    RunNextTest();
//}
//
//void ATestForgeTestSuiteActor::OnTestSkipped(ATestForgeTestActor* Test, UObject* Parameter,
//                                       const FString& SkipReason)
//{
//    if (Test != GetCurrentTest())
//    {
//        // Prevent tests from reporting multiple results.
//        return;
//    }
//
//    FString CurrentTestName = GetCurrentTestName();
//
//    UE_LOG(LogTestForgeTest, Display,
//           TEXT("ATestForgeTestSuiteActor::OnTestSkipped - Test: %s, SkipReason: %s"), *CurrentTestName,
//           *SkipReason);
//
//    // Store result.
//    FTestForgeTestResult TestResult(CurrentTestName, TestTimeSeconds);
//    TestResult.SkipReason = SkipReason;
//    TestResult.Data = Test->CollectResults();
//
//    Result.TestResults.Add(TestResult);
//
//    // Run next test.
//    RunNextTest();
//}
//
