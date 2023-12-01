//#pragma once
//
//#include <CoreMinimal.h>
//#include <LatentActions.h>
//#include <Engine/LatentActionManager.h>
//
///** Triggers the output link after the specified number of frames. */
//class TESTFORGE_API FTestForgeDelayFramesAction : public FPendingLatentAction
//{
//public:
//    int32 FramesRemaining;
//    FName ExecutionFunction;
//    int32 OutputLink;
//    FWeakObjectPtr CallbackTarget;
//
//    FTestForgeDelayFramesAction(const FLatentActionInfo& LatentInfo, int32 NumFrames);
//
//    virtual void UpdateOperation(FLatentResponse& Response) override;
//
//#if WITH_EDITOR
//    virtual FString GetDescription() const override;
//#endif
//};
//
