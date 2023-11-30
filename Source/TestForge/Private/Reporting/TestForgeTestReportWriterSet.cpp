//#include "TestForgeTestReportWriterSet.h"
//#include "TestForgeTestReportWriter.h"
//
//void FTestForgeTestReportWriterSet::Add(TSharedPtr<FTestForgeTestReportWriter> ReportWriter)
//{
//    for (TSharedPtr<FTestForgeTestReportWriter> ExistingReportWriter : ReportWriters)
//    {
//        if (ExistingReportWriter->GetReportType() == ReportWriter->GetReportType())
//        {
//            return;
//        }
//    }
//
//    ReportWriters.Add(ReportWriter);
//}
//
//void FTestForgeTestReportWriterSet::Add(const FTestForgeTestReportWriterSet& Other)
//{
//    for (TSharedPtr<FTestForgeTestReportWriter> ReportWriter : Other.GetReportWriters())
//    {
//        Add(ReportWriter);
//    }
//}
//
//TArray<TSharedPtr<FTestForgeTestReportWriter>> FTestForgeTestReportWriterSet::GetReportWriters() const
//{
//    return ReportWriters;
//}
//
