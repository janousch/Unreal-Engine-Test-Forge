#pragma once

#include "TestForgeTestReportWriterSet.h"
#include "Settings/TestForgeTestMapMetaData.h"
#include "TestForgeTestSuiteResult.h"
#include <CoreMinimal.h>
#include <UObject/Object.h>
#include "TestForgeUnitTest.generated.h"

class FTestForgeTestResultData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestForgeUnitTestSuccessfulSignature, UTestForgeUnitTest*,
                                             Test, UObject*, Parameter);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestForgeUnitTestFailedSignature, UTestForgeUnitTest*,
                                               Test, UObject*, Parameter, const FString&,
                                               FailureMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestForgeUnitTestSkippedSignature, UTestForgeUnitTest*,
                                               Test, UObject*, Parameter, const FString&,
                                               SkipReason);

/** Single automated test to be run as part of a test suite. */
UCLASS(Blueprintable)
class TESTFORGE_API UTestForgeUnitTest
    : public UObject
{
    GENERATED_BODY()

public:
    /**
	 * Lets you know if any automated unit tests are running, or are about to run and the automation system is spinning up tests.
	 */
    UFUNCTION(BlueprintPure, Category = "Automation|UnitTest")
    static bool AreAutomatedUnitTestsRunning();

    UTestForgeUnitTest(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
    
    //~ UObject overrides
    virtual UWorld* GetWorld() const override;
    //~ UObject overrides

    /** Starts executing this test. */
    void RunTest(UObject* TestParameter);

    bool IsRunning() const;

    /** Finishes execution of this test, automatically following up with the Assert step. */
    UFUNCTION(BlueprintPure = false)
    void FinishAct();
    
    /** Results of the whole test suite. */
    const FTestForgeTestSuiteResult& GetResult() const;

    /** Gets how long this test is allowed to run before it fails automatically, in seconds. */
    float GetTimeoutInSeconds() const;

    /** Flag the test that it had a timeout. The test ran longer than TimeoutInSeconds. */
    void Timeout();

    /** Gets the parameters to run this test with, one per run.  */
    TArray<TSoftObjectPtr<UObject>> GetParameters() const;

    /** Gets the parameter for the current test run. */
    UFUNCTION(BlueprintPure = true)
    UObject* GetCurrentParameter() const;

    /** Collects additional result data for this test after it has finished. */
    virtual TSharedPtr<FTestForgeTestResultData> CollectResults() const;

    /** Returns writers for writing reports for tests of this type, e.g. for publishing with CI/CD pipelines. */
    virtual FTestForgeTestReportWriterSet GetReportWriters() const;

    /** Event when this test has finished successfully. */
    virtual void NotifyOnTestSuccessful();

    /** Event when this test has failed. */
    virtual void NotifyOnTestFailed(const FString& Message);

    /** Event when this test has been skipped. */
    virtual void NotifyOnTestSkipped(const FString& InSkipReason);

    /** Event when this test should verify its preconditions. */
    virtual void NotifyOnAssume(UObject* Parameter);

    /** Event when this test should set up. */
    virtual void NotifyOnArrange(UObject* Parameter);

    /** Event when this test should execute. */
    virtual void NotifyOnAct(UObject* Parameter);

    /** Event when this test should check the results. */
    virtual void NotifyOnAssert(UObject* Parameter);

    /** Event when this test should verify its preconditions. This is NOT a latent event. */
    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Assume"))
    void ReceiveOnAssume(UObject* Parameter);

    /** Event when this test should set up. This is NOT a latent event. */
    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Arrange"))
    void ReceiveOnArrange(UObject* Parameter);

    /** Event when this test should execute. This is a latent event: You need to call FinishAct when you're finished. */
    UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "Act"))
    void ReceiveOnAct(UObject* Parameter);

    /** Event when this test should check the results. This is NOT a latent event. */
    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Assert"))
    void ReceiveOnAssert(UObject* Parameter);

    /** Event when this test has finished successfully. */
    FTestForgeUnitTestSuccessfulSignature OnTestSuccessful;

    /** Event when this test has failed. */
    FTestForgeUnitTestFailedSignature OnTestFailed;

    /** Event when this test has been skipped. */
    FTestForgeUnitTestSkippedSignature OnTestSkipped;

protected:
#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif

    /** How long this test is allowed to run before it fails automatically, in seconds. */
    UPROPERTY(EditAnywhere)
    float TimeoutInSeconds;

    UFUNCTION(BlueprintPure = true)
    UWorld* GetTestWorld() const;

private:
    /** Whether or not a unit test is currently being run. */
    static bool bIsAutomationUnitTesting;

    /** Reason for skipping this test. Test will be skipped if this is not empty. Useful for temporarily disabling unstable tests. */
    UPROPERTY(EditAnywhere)
    FString SkipReason;

    /** Parameterizes this test, running it multiple times, once per specified parameter.  */
    UPROPERTY(EditAnywhere)
    TArray<TSoftObjectPtr<UObject>> Parameters;

	/** Optional meta data for a test. */
	UPROPERTY(EditDefaultsOnly)
    FTestForgeUnitTestMetaData UnitTestMetaData;

    /** Parameter for the current test run. */
    UPROPERTY()
    UObject* CurrentParameter;

    /** Whether this test had a timeout or finished in time. */
    UPROPERTY()
    bool bHadTimeout = false;

    /** Whether this test has finished executing (either with success or failure). */
    UPROPERTY()
    bool bHasResult = false;
    
    FTestForgeTestSuiteResult Result;

    UPROPERTY()
    UWorld* TestWorld = nullptr;

    void UpdateMetaData();
};

