//#include "TestForgeTestSuiteResult.h"
//
//int32 FTestForgeTestSuiteResult::NumTotalTests() const
//{
//    return TestResults.Num();
//}
//
//int32 FTestForgeTestSuiteResult::NumSuccessfulTests() const
//{
//    return NumTotalTests() - NumFailedTests() - NumSkippedTests();
//}
//
//int32 FTestForgeTestSuiteResult::NumFailedTests() const
//{
//    int32 FailedTests = 0;
//
//    for (const FTestForgeTestResult& TestResult : TestResults)
//    {
//        if (TestResult.HasFailed())
//        {
//            ++FailedTests;
//        }
//    }
//
//    return FailedTests;
//}
//
//int32 FTestForgeTestSuiteResult::NumSkippedTests() const
//{
//    int32 SkippedTests = 0;
//
//    for (const FTestForgeTestResult& TestResult : TestResults)
//    {
//        if (TestResult.WasSkipped())
//        {
//            ++SkippedTests;
//        }
//    }
//
//    return SkippedTests;
//}
//
//float FTestForgeTestSuiteResult::GetTotalTimeSeconds() const
//{
//    float TimeSeconds = 0.0f;
//
//    for (const FTestForgeTestResult& TestResult : TestResults)
//    {
//        TimeSeconds += TestResult.TimeSeconds;
//    }
//
//    return TimeSeconds;
//}
//
