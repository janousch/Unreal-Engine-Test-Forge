#pragma once

#include "TestForgeTestPerformanceBudgetViolation.h"
#include "TestForgeTestResultData.h"
#include <CoreMinimal.h>

/** Result data for performance tests. */
class TESTFORGE_API FTestForgeTestPerformanceBudgetResultData
    : public FTestForgeTestResultData
{
public:
    virtual FName GetDataType() const override;

    /** Performance budget violations that occurred during the test. */
    TArray<FTestForgeTestPerformanceBudgetViolation> BudgetViolations;
};

