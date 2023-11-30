//#include "TestForgeTestResult.h"
//
//FTestForgeTestResult::FTestForgeTestResult()
//    : FTestForgeTestResult(FString(), 0.0f)
//{
//}
//
//FTestForgeTestResult::FTestForgeTestResult(FString InTestName, float InTimeSeconds)
//    : TestName(InTestName)
//    , TimeSeconds(InTimeSeconds)
//{
//}
//
//bool FTestForgeTestResult::WasSuccessful() const
//{
//    return !HasFailed() && !WasSkipped();
//}
//
//bool FTestForgeTestResult::HasFailed() const
//{
//    return !FailureMessage.IsEmpty();
//}
//
//bool FTestForgeTestResult::WasSkipped() const
//{
//    return !SkipReason.IsEmpty();
//}
//
