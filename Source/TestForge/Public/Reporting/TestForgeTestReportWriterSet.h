//#pragma once
//
//#include <CoreMinimal.h>
//
//class FTestForgeTestReportWriter;
//
///** Writes multiple different test reports, e.g. for publishing with CI/CD pipelines. */
//class TESTFORGE_API FTestForgeTestReportWriterSet
//{
//public:
//    /** Adds the specified report writer to this set. */
//    void Add(TSharedPtr<FTestForgeTestReportWriter> ReportWriter);
//
//    /** Adds the specified report writers to this set. */
//    void Add(const FTestForgeTestReportWriterSet& Other);
//
//    /** Gets the report writers of this set. */
//    TArray<TSharedPtr<FTestForgeTestReportWriter>> GetReportWriters() const;
//
//private:
//    TArray<TSharedPtr<FTestForgeTestReportWriter>> ReportWriters;
//};
//
