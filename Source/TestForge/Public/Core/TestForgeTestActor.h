// Copyright 2023 Ramon Janousch. All Rights Reserved.

#pragma once

//#include "TestForgeTestReportWriterSet.h"
//#include "Settings/TestForgeTestMapMetaData.h"
#include <CoreMinimal.h>
#include <GameFramework/Actor.h>
#include "TestForgeTestActor.generated.h"

////class UTestForgeTestReplayComponent;
////class UTestForgeCaptureComponent;
////class ATestForgeTestParameterProviderActor;
////class FTestForgeTestResultData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestForgeTestActorSuccessfulSignature,
                                             ATestForgeTestActor*, Test, UObject*, Parameter);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestForgeTestActorFailedSignature,
                                               ATestForgeTestActor*, Test, UObject*, Parameter,
                                               const FString&, FailureMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestForgeTestActorSkippedSignature,
                                               ATestForgeTestActor*, Test, UObject*, Parameter,
                                               const FString&, SkipReason);

//USTRUCT()
//struct FTestForgeTestRecordingSettings
//{
//    GENERATED_BODY()
//
//    /** Should this test be driven by recorded player input? */
//    UPROPERTY(EditInstanceOnly)
//    bool bUseRecordedPlayerInput = false;
//    /** If set to true the test actor will record all player input. */
//    UPROPERTY(EditInstanceOnly, Meta = (EditCondition = "bUseRecordedPlayerInput"))
//    bool bIsRecording = false;
//};

/** Single automated test to be run as part of a test suite. */
UCLASS()
class TESTFORGE_API ATestForgeTestActor : public AActor
{
    GENERATED_BODY()

public:
    ATestForgeTestActor();

//    /** Applies additional providers for appending parameters for this test. */
//    void ApplyParameterProviders();

    /** Starts executing this test. */
    void RunTest(UObject* TestParameter);

//    /** Finishes execution of this test, automatically following up with the Assert step. */
//    UFUNCTION(BlueprintPure = false)
//    void FinishAct();

    /** Gets how long this test is allowed to run before it fails automatically, in seconds. */
    float GetTimeoutInSeconds() const;

//    /** Flag the test that it had a timeout. The test ran longer than TimeoutInSeconds. */
//    void Timeout();

    /** Gets the parameters to run this test with, one per run.  */
    TArray<TSoftObjectPtr<UObject>> GetParameters() const;

    /** Gets the parameter for the current test run. */
    UFUNCTION(BlueprintPure = true)
    UObject* GetCurrentParameter() const;

//    /** Collects additional result data for this test after it has finished. */
//    virtual TSharedPtr<FTestForgeTestResultData> CollectResults() const;
//
//    /** Returns writers for writing reports for tests of this type, e.g. for publishing with CI/CD pipelines. */
//    virtual FTestForgeTestReportWriterSet GetReportWriters() const;
//
//    /** Event when this test has finished successfully. */
//    virtual void NotifyOnTestSuccessful();
//
//    /** Event when this test has failed. */
//    virtual void NotifyOnTestFailed(const FString& Message);

    /** Event when this test has been skipped. */
    virtual void NotifyOnTestSkipped();

    /** Event when this test should verify its preconditions. */
    virtual void NotifyOnAssume();

    /** Event when this test should set up. */
    virtual void NotifyOnArrange();

    /** Event when this test should execute. */
    virtual void NotifyOnAct();

    /** Event when this test should check the results. */
    virtual void NotifyOnAssert();

    /** Event when this test should verify its preconditions. This is NOT a latent event. */
    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Assume"))
    void ReceiveOnAssume();

    /** Event when this test should set up. This is NOT a latent event. */
    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Arrange"))
    void ReceiveOnArrange();

    /** Event when this test should execute. This is a latent event: You need to call FinishAct when you're finished. */
    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Act"))
    void ReceiveOnAct();

    /** Event when this test should check the results. This is NOT a latent event. */
    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Assert"))
    void ReceiveOnAssert();

//    /** Event when this test has finished successfully. */
//    FTestForgeTestActorTestSuccessfulSignature OnTestSuccessful;
//
//    /** Event when this test has failed. */
//    FTestForgeTestActorTestFailedSignature OnTestFailed;

    /** Event when this test has been skipped. */
    FTestForgeTestActorSkippedSignature OnTestSkipped;

//protected:
//    virtual void BeginPlay() override;
//
//#if WITH_EDITOR
//	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
//#endif
//
//    UFUNCTION(BlueprintPure = true)
//    bool IsRecording() const;

    /** How long this test is allowed to run before it fails automatically, in seconds. */
    UPROPERTY(EditAnywhere)
    float TimeoutInSeconds;

private:
    /** Reason for skipping this test. Test will be skipped if this is not empty. Useful for temporarily disabling unstable tests. */
    UPROPERTY(EditAnywhere)
    FString SkipReason;

    /** Parameterizes this test, running it multiple times, once per specified parameter.  */
    UPROPERTY(EditAnywhere)
    TArray<TSoftObjectPtr<UObject>> Parameters;

//    /** Additional providers for appending parameters for this test. Applied exactly once before the first test run. */
//    UPROPERTY(EditAnywhere)
//    TArray<ATestForgeTestParameterProviderActor*> ParameterProviders;
//
//	/** Optional meta data for a test. */
//	UPROPERTY(EditInstanceOnly)
//    FTestForgeTestMapMetaData TestMetaData;
//
//    /** Enable the option to record player input and to replay that input in the test. */
//    UPROPERTY(EditInstanceOnly)
//    FTestForgeTestRecordingSettings RecordingSettings;

    /** Parameter for the current test run. */
    UPROPERTY()
    UObject* CurrentParameter = nullptr;

    /** Whether this test had a timeout or finished in time. */
    UPROPERTY()
    bool bHadTimeout = false;

    /** Whether this test has finished executing (either with success or failure). */
    UPROPERTY()
    bool bHasResult = false;

//    /** Component responsible for recording player input. */
//    UPROPERTY()
//    UTestForgeCaptureComponent* RecordingComponent = nullptr;
//    /** Component responsible for replaying recorded player input. */
//    UPROPERTY()
//    UTestForgeTestReplayComponent* ReplayComponent = nullptr;
};

