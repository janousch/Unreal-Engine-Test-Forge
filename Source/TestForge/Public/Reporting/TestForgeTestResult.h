#pragma once

#include <CoreMinimal.h>
#include <TestForgeTestResultData.h>

/** Result set of a single test. */
class TESTFORGE_API FTestForgeTestResult
{
public:
    /** Name of the test. */
    FString TestName;

    /** (Optional) Why the test failed. */
    FString FailureMessage;

    /** (Optional) Why the test was skipped. */
    FString SkipReason;

    /** Time the test ran, in seconds. */
    float TimeSeconds;

    /** Additional result data of the test. */
    TSharedPtr<FTestForgeTestResultData> Data;

    FTestForgeTestResult();
    FTestForgeTestResult(FString InTestName, float InTimeSeconds);

    /** Whether the test finished without failure, or not. */
    bool WasSuccessful() const;

    /** Whether the test has failed. */
    bool HasFailed() const;

    /** Whether this test has been skipped instead of being run. */
    bool WasSkipped() const;
};

