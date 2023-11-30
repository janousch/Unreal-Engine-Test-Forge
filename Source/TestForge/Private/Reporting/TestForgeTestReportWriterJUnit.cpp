//#include "TestForgeTestReportWriterJUnit.h"
//#include "TestForgeTestLogCategory.h"
//
//FName FTestForgeTestReportWriterJUnit::GetReportType() const
//{
//    return TEXT("FTestForgeTestReportWriterJUnit");
//}
//
//void FTestForgeTestReportWriterJUnit::WriteReport(const TArray<FTestForgeTestSuiteResult>& TestSuites,
//                                            const FString& ReportPath) const
//{
//    // Build report path.
//    FString JUnitReportPath;
//
//    // Backwards compatibility:
//    FParse::Value(FCommandLine::Get(), TEXT("JUnitReportPath"), JUnitReportPath);
//    JUnitReportPath = JUnitReportPath.Mid(1);
//
//    if (JUnitReportPath.IsEmpty())
//    {
//        if (ReportPath.IsEmpty())
//        {
//            return;
//        }
//
//        JUnitReportPath = FPaths::Combine(ReportPath, TEXT("junit-report.xml"));
//    }
//
//    // Ensure report path exists.
//    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
//    FString ReportDirectory = FPaths::GetPath(JUnitReportPath);
//
//    if (!PlatformFile.DirectoryExists(*ReportDirectory))
//    {
//        UE_LOG(LogTestForgeTest, Display, TEXT("Creating directory: %s"), *ReportDirectory);
//
//        PlatformFile.CreateDirectoryTree(*ReportDirectory);
//    }
//
//    // Write a JUnit XML report based on FXmlFile::WriteNodeHierarchy.
//    // Unfortunately, FXmlNode::Tag is private, so we have to do the hard work here ourselves...
//    FString XmlString;
//
//    XmlString += TEXT("<?xml version=\"1.0\" encoding=\"UTF-8\"?>") LINE_TERMINATOR;
//    XmlString += TEXT("<testsuite");
//    XmlString += TEXT(" name=\"JUnit Test Report\"");
//    XmlString += FString::Printf(TEXT(" tests=\"%d\""), NumTotalTests(TestSuites));
//    XmlString += FString::Printf(TEXT(" skipped=\"%d\""), NumSkippedTests(TestSuites));
//    XmlString += FString::Printf(TEXT(" failures=\"%d\""), NumFailedTests(TestSuites));
//    XmlString += FString::Printf(TEXT(" errors=\"0\""));
//    XmlString += FString::Printf(TEXT(" time=\"%f\""), GetTotalTimeSeconds(TestSuites));
//    XmlString += FString::Printf(TEXT(" timestamp=\"%s\""), *GetTimestamp(TestSuites));
//    XmlString += TEXT(">") LINE_TERMINATOR;
//
//    for (const FTestForgeTestSuiteResult& TestSuiteResult : TestSuites)
//    {
//        const FString& TestClassName = FString::Printf(TEXT("%s.%s"), *TestSuiteResult.MapName,
//                                                       *TestSuiteResult.TestSuiteName);
//
//        for (const FTestForgeTestResult& TestResult : TestSuiteResult.TestResults)
//        {
//            XmlString += TEXT("    <testcase");
//            XmlString += FString::Printf(TEXT(" name=\"%s\""), *TestResult.TestName);
//            XmlString += FString::Printf(TEXT(" classname=\"%s\""), *TestClassName);
//            XmlString += FString::Printf(TEXT(" time=\"%f\""), TestResult.TimeSeconds);
//            XmlString += TEXT(">") LINE_TERMINATOR;
//
//            if (TestResult.HasFailed())
//            {
//                XmlString +=
//                    FString::Printf(TEXT("        <failure type=\"Assertion failed\">%s</failure>"),
//                                    *TestResult.FailureMessage)
//                    + LINE_TERMINATOR;
//            }
//            else if (TestResult.WasSkipped())
//            {
//                XmlString +=
//                    FString::Printf(TEXT("        <skipped>%s</skipped>"), *TestResult.SkipReason)
//                    + LINE_TERMINATOR;
//            }
//
//            XmlString += TEXT("    </testcase>") LINE_TERMINATOR;
//        }
//    }
//
//    XmlString += TEXT("</testsuite>") LINE_TERMINATOR;
//
//    UE_LOG(LogTestForgeTest, Verbose, TEXT("Test report:\r\n%s"), *XmlString);
//    UE_LOG(LogTestForgeTest, Display, TEXT("Writing test report to: %s"), *JUnitReportPath);
//
//    FFileHelper::SaveStringToFile(XmlString, *JUnitReportPath);
//}
//
