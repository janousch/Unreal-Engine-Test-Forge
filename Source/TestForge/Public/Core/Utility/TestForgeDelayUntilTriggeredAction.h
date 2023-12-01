//#pragma once
//
//#include <CoreMinimal.h>
//#include <LatentActions.h>
//#include <Engine/LatentActionManager.h>
//
//class ATestForgeTestTriggerBox;
//
///** Triggers the output link after the specified trigger box has been triggered. */
//class TESTFORGE_API FTestForgeDelayUntilTriggeredAction : public FPendingLatentAction
//{
//public:
//    ATestForgeTestTriggerBox* TestTriggerBox;
//    FName ExecutionFunction;
//    int32 OutputLink;
//    FWeakObjectPtr CallbackTarget;
//
//    FTestForgeDelayUntilTriggeredAction(const FLatentActionInfo& LatentInfo,
//                                  ATestForgeTestTriggerBox* InTestTriggerBox);
//
//    virtual void UpdateOperation(FLatentResponse& Response) override;
//
//#if WITH_EDITOR
//    virtual FString GetDescription() const override;
//#endif
//};
//
