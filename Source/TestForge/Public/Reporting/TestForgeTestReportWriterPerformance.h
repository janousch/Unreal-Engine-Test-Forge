//#pragma once
//
//#include "TestForgeTestReportWriter.h"
//#include "TestForgeTestSuiteResult.h"
//#include <CoreMinimal.h>
//
///** Writes test reports for performance budgets. */
//class TESTFORGE_API FTestForgeTestReportWriterPerformance : public FTestForgeTestReportWriter
//{
//public:
//    virtual FName GetReportType() const override;
//    virtual void WriteReport(const TArray<FTestForgeTestSuiteResult>& TestSuites,
//                             const FString& ReportPath) const override;
//
//private:
//    /** Formats the specified time using a fixed number of fractional digits. */
//    FString FormatTime(float Time) const;
//
//    /** Formats the specified location using a fixed number of fractional digits. */
//    FString FormatLocation(const FVector& Location) const;
//};
//
