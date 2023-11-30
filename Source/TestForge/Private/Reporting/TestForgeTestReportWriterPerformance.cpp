//#include "TestForgeTestReportWriterPerformance.h"
//#include "TestForgeTestPerformanceBudgetResultData.h"
//#include "TestForgeTestPerformanceBudgetViolation.h"
//#include "TestForgeTestLogCategory.h"
//#include <HAL/PlatformFilemanager.h>
//#include <Interfaces/IPluginManager.h>
//#include <Kismet/KismetTextLibrary.h>
//
//FName FTestForgeTestReportWriterPerformance::GetReportType() const
//{
//    return TEXT("FTestForgeTestReportWriterPerformance");
//}
//
//void FTestForgeTestReportWriterPerformance::WriteReport(const TArray<FTestForgeTestSuiteResult>& TestSuites,
//                                                  const FString& ReportPath) const
//{
//    // Ensure report path exists.
//    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
//
//    if (!PlatformFile.DirectoryExists(*ReportPath))
//    {
//        UE_LOG(LogTestForgeTest, Display, TEXT("Creating directory: %s"), *ReportPath);
//
//        PlatformFile.CreateDirectoryTree(*ReportPath);
//    }
//
//    // Prepare report.
//    FString ContentDir =
//        IPluginManager::Get().FindPlugin(TEXT("TestForgedalicTestAutomationPlugin"))->GetContentDir();
//    FString ReportTemplatePath = FPaths::Combine(ContentDir, TEXT("ReportTemplates"),
//                                                 TEXT("PerformanceReport.template.html"));
//    FString MapTemplatePath = FPaths::Combine(ContentDir, TEXT("ReportTemplates"),
//                                              TEXT("PerformanceReportMap.template.html"));
//    FString BudgetViolationTemplatePath =
//        FPaths::Combine(ContentDir, TEXT("ReportTemplates"),
//                        TEXT("PerformanceReportBudgetViolation.template.html"));
//
//    // Write performance budget violations.
//    FString MapString;
//
//    for (const FTestForgeTestSuiteResult& TestSuiteResult : TestSuites)
//    {
//        for (const FTestForgeTestResult& TestResult : TestSuiteResult.TestResults)
//        {
//            if (TestResult.Data != nullptr
//                && TestResult.Data->GetDataType() == TEXT("FTestForgeTestPerformanceBudgetResultData"))
//            {
//                TSharedPtr<FTestForgeTestPerformanceBudgetResultData> Data =
//                    StaticCastSharedPtr<FTestForgeTestPerformanceBudgetResultData>(TestResult.Data);
//
//                FString BudgetViolationsString;
//
//                for (const FTestForgeTestPerformanceBudgetViolation& BudgetViolation :
//                     Data->BudgetViolations)
//                {
//                    // Copy screenshot.
//                    FString OldScreenshotPath = BudgetViolation.ScreenshotPath;
//                    FString ScreenshotFilename = FPaths::GetCleanFilename(OldScreenshotPath);
//                    FString NewScreenshotPath = FPaths::Combine(ReportPath, ScreenshotFilename);
//
//                    UE_LOG(LogTestForgeTest, Display, TEXT("Copying %s to %s."), *OldScreenshotPath,
//                           *NewScreenshotPath);
//
//                    PlatformFile.CopyFile(*NewScreenshotPath, *OldScreenshotPath);
//
//                    // Write budget violation.
//                    TMap<FString, FString> BudgetViolationTemplateReplacements;
//
//                    BudgetViolationTemplateReplacements.Add(TEXT("{LOCATION}"),
//                                                            FormatLocation(
//                                                                BudgetViolation.CurrentLocation));
//                    BudgetViolationTemplateReplacements.Add(
//                        TEXT("{PREVIOUS}"), BudgetViolation.PreviousTargetPointName);
//                    BudgetViolationTemplateReplacements.Add(TEXT("{NEXT}"),
//                                                            BudgetViolation.NextTargetPointName);
//                    BudgetViolationTemplateReplacements.Add(TEXT("{FPS}"),
//                                                            FormatTime(BudgetViolation.FPS));
//                    BudgetViolationTemplateReplacements.Add(TEXT("{GAME_TIME}"),
//                                                            FormatTime(
//                                                                BudgetViolation.GameThreadTime));
//                    BudgetViolationTemplateReplacements.Add(TEXT("{RENDER_TIME}"),
//                                                            FormatTime(
//                                                                BudgetViolation.RenderThreadTime));
//                    BudgetViolationTemplateReplacements.Add(TEXT("{GPU_TIME}"),
//                                                            FormatTime(BudgetViolation.GPUTime));
//                    BudgetViolationTemplateReplacements.Add(TEXT("{SCREENSHOT_PATH}"),
//                                                            ScreenshotFilename);
//
//                    BudgetViolationsString +=
//                        ApplyTemplateFile(BudgetViolationTemplatePath,
//                                          BudgetViolationTemplateReplacements);
//                }
//
//                // Write map.
//                TMap<FString, FString> MapTemplateReplacements;
//
//                MapTemplateReplacements.Add(TEXT("{MAP_NAME}"), TestSuiteResult.MapName);
//                MapTemplateReplacements.Add(TEXT("{MAP_DURATION}"),
//                                            FormatTime(TestResult.TimeSeconds));
//                MapTemplateReplacements.Add(TEXT("{BUDGET_VIOLATIONS}"), BudgetViolationsString);
//
//                MapString += ApplyTemplateFile(MapTemplatePath, MapTemplateReplacements);
//            }
//        }
//    }
//
//    // Write report.
//    TMap<FString, FString> ReportTemplateReplacements;
//
//    ReportTemplateReplacements.Add(TEXT("{START_TIME}"), GetTimestamp(TestSuites));
//    ReportTemplateReplacements.Add(TEXT("{TOTAL_DURATION}"),
//                                   FormatTime(GetTotalTimeSeconds(TestSuites)));
//    ReportTemplateReplacements.Add(TEXT("{MAP_RESULTS}"), MapString);
//
//    FString ReportHtmlString = ApplyTemplateFile(ReportTemplatePath, ReportTemplateReplacements);
//
//    UE_LOG(LogTestForgeTest, Verbose, TEXT("Test report:\r\n%s"), *ReportHtmlString);
//    UE_LOG(LogTestForgeTest, Display, TEXT("Writing test report to: %s"), *ReportHtmlString);
//
//    FString HtmlReportPath = FPaths::Combine(ReportPath, TEXT("performance-report.html"));
//
//    FFileHelper::SaveStringToFile(ReportHtmlString, *HtmlReportPath);
//
//    // Copy style file.
//    const FString& StyleFileName = TEXT("bootstrap.min.css");
//
//    FString PluginStyleFilePath =
//        FPaths::Combine(ContentDir, TEXT("ReportTemplates"), StyleFileName);
//    FString ReportStyleFilePath = FPaths::Combine(ReportPath, StyleFileName);
//
//    UE_LOG(LogTestForgeTest, Display, TEXT("Copying %s to %s."), *PluginStyleFilePath,
//           *ReportStyleFilePath);
//
//    PlatformFile.CopyFile(*ReportStyleFilePath, *PluginStyleFilePath);
//}
//
//FString FTestForgeTestReportWriterPerformance::FormatTime(float Time) const
//{
//    return UKismetTextLibrary::Conv_FloatToText(Time, ERoundingMode::HalfToEven, false, false, 1,
//                                                324, 2, 2)
//        .ToString();
//}
//
//FString FTestForgeTestReportWriterPerformance::FormatLocation(const FVector& Location) const
//{
//    return FString::Printf(TEXT("X=%d Y=%d Z=%d"), FMath::FloorToInt(Location.X),
//                           FMath::FloorToInt(Location.Y), FMath::FloorToInt(Location.Z));
//}
//
