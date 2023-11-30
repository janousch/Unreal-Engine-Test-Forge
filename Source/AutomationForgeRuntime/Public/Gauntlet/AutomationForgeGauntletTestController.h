#pragma once

#include "AutomationForgeTestSuiteResult.h"
#include "Settings/AutomationForgeTestMapMetaData.h"
#include <CoreMinimal.h>
#include <GauntletTestController.h>
#include "AutomationForgeGauntletTestController.generated.h"

class AAutomationForgeTestSuiteActor;

/** Controller for automated tests run by Gauntlet. */
UCLASS()
class AutomationForgeDALICTESTAUTOMATIONPLUGIN_API UAutomationForgeGauntletTestController : public UGauntletTestController
{
    GENERATED_BODY()

public:
    virtual void OnInit() override;
    virtual void OnPostMapChange(UWorld* World) override;
    virtual void OnTick(float TimeDelta) override;

private:
    TArray<FName> MapNames;
    int32 MapIndex;
    TArray<FAutomationForgeTestSuiteResult> Results;

    void LoadNextTestMap();
    /** Does the test has one of the required tags? */
    bool DoesMapHasTag(const FString& TestName, const TArray<FString>& RequiredTags) const;
    static EAutomationForgeTestPriority ConvertStringToPriority(const FString& TestPriorityString);

    UFUNCTION()
    void OnTestSuiteFinished(AAutomationForgeTestSuiteActor* TestSuite);

    FString ParseCommandLineOption(const FString& Key) const;
};


