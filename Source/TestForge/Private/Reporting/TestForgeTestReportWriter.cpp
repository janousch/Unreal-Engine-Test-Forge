//#include "TestForgeTestReportWriter.h"
//
//int32 FTestForgeTestReportWriter::NumTotalTests(const TArray<FTestForgeTestSuiteResult>& TestSuites) const
//{
//    int32 TotalTests = 0;
//
//    for (const FTestForgeTestSuiteResult& TestSuite : TestSuites)
//    {
//        TotalTests += TestSuite.NumTotalTests();
//    }
//
//    return TotalTests;
//}
//
//int32 FTestForgeTestReportWriter::NumFailedTests(const TArray<FTestForgeTestSuiteResult>& TestSuites) const
//{
//    int32 FailedTests = 0;
//
//    for (const FTestForgeTestSuiteResult& TestSuite : TestSuites)
//    {
//        FailedTests += TestSuite.NumFailedTests();
//    }
//
//    return FailedTests;
//}
//
//int32 FTestForgeTestReportWriter::NumSkippedTests(const TArray<FTestForgeTestSuiteResult>& TestSuites) const
//{
//    int32 SkippedTests = 0;
//
//    for (const FTestForgeTestSuiteResult& TestSuite : TestSuites)
//    {
//        SkippedTests += TestSuite.NumSkippedTests();
//    }
//
//    return SkippedTests;
//}
//
//float FTestForgeTestReportWriter::GetTotalTimeSeconds(const TArray<FTestForgeTestSuiteResult>& TestSuites) const
//{
//    float TimeSeconds = 0;
//
//    for (const FTestForgeTestSuiteResult& TestSuite : TestSuites)
//    {
//        TimeSeconds += TestSuite.GetTotalTimeSeconds();
//    }
//
//    return TimeSeconds;
//}
//
//FString FTestForgeTestReportWriter::GetTimestamp(const TArray<FTestForgeTestSuiteResult>& TestSuites) const
//{
//    FDateTime Timestamp = TestSuites.Num() > 0 ? TestSuites[0].Timestamp : FDateTime::UtcNow();
//    return Timestamp.ToIso8601();
//}
//
//FString FTestForgeTestReportWriter::ApplyTemplateFile(const FString& TemplateFilePath,
//                                                const TMap<FString, FString>& Replacements) const
//{
//    FString ResultString;
//    FFileHelper::LoadFileToString(ResultString, *TemplateFilePath);
//
//    for (auto& Replacement : Replacements)
//    {
//        ResultString = ResultString.Replace(*Replacement.Key, *Replacement.Value);
//    }
//
//    return ResultString;
//}
//
