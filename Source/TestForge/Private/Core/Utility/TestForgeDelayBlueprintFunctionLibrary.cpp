//#include "TestForgeTestDelayBlueprintFunctionLibrary.h"
//#include "TestForgeDelayFramesAction.h"
//#include "TestForgeDelayUntilTriggeredAction.h"
//#include <Engine/Engine.h>
//#include <Engine/LatentActionManager.h>
//#include <Engine/World.h>
//
//void UTestForgeTestDelayBlueprintFunctionLibrary::DelayFrames(UObject* WorldContextObject,
//                                                        struct FLatentActionInfo LatentInfo,
//                                                        int32 NumFrames)
//{
//    if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject,
//                                                           EGetWorldErrorMode::LogAndReturnNull))
//    {
//        FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
//        if (LatentActionManager.FindExistingAction<FTestForgeDelayFramesAction>(LatentInfo.CallbackTarget,
//                                                                          LatentInfo.UUID)
//            == NULL)
//        {
//            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
//                                             new FTestForgeDelayFramesAction(LatentInfo, NumFrames));
//        }
//    }
//}
//
//void UTestForgeTestDelayBlueprintFunctionLibrary::DelayUntilTriggered(UObject* WorldContextObject,
//                                                                struct FLatentActionInfo LatentInfo,
//                                                                ATestForgeTestTriggerBox* TestTriggerBox)
//{
//    if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject,
//                                                           EGetWorldErrorMode::LogAndReturnNull))
//    {
//        FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
//        if (LatentActionManager.FindExistingAction<FTestForgeDelayUntilTriggeredAction>(
//                LatentInfo.CallbackTarget, LatentInfo.UUID)
//            == NULL)
//        {
//            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
//                                             new FTestForgeDelayUntilTriggeredAction(LatentInfo,
//                                                                               TestTriggerBox));
//        }
//    }
//}
//
