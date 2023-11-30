#pragma once

#include "TestForgeTestReportWriter.h"
#include "TestForgeTestSuiteResult.h"
#include <CoreMinimal.h>

/** Writes test reports based on the Apache Ant JUnit report format (based on org.junit.platform.reporting.legacy.xml.XmlReportWriter.writeTestsuite). */
class TESTFORGE_API FTestForgeTestReportWriterJUnit : public FTestForgeTestReportWriter
{
public:
    virtual FName GetReportType() const override;
    virtual void WriteReport(const TArray<FTestForgeTestSuiteResult>& TestSuites,
                             const FString& ReportPath) const override;
};

