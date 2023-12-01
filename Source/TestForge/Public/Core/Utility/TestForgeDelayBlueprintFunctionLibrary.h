//#pragma once
//
//#include <CoreMinimal.h>
//#include <Engine/LatentActionManager.h>
//#include <Kismet/BlueprintFunctionLibrary.h>
//#include "TestForgeTestDelayBlueprintFunctionLibrary.generated.h"
//
//class ATestForgeTestTriggerBox;
//
///** Utility functions for sequencing actions in automated tests. */
//UCLASS(meta = (RestrictedToClasses = "TestForgeTestActor"))
//class TESTFORGE_API UTestForgeTestDelayBlueprintFunctionLibrary
//    : public UBlueprintFunctionLibrary
//{
//    GENERATED_BODY()
//
//public:
//    /** Triggers the output link after the specified number of frames. */
//    UFUNCTION(BlueprintCallable, Category = "TestAutomation|Delay",
//              meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo"))
//    static void DelayFrames(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo,
//                            int32 NumFrames = 1);
//
//    /** Triggers the output link after the specified trigger box has been triggered. */
//    UFUNCTION(BlueprintCallable, Category = "TestAutomation|Delay",
//              meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo"))
//    static void DelayUntilTriggered(UObject* WorldContextObject,
//                                    struct FLatentActionInfo LatentInfo,
//                                    ATestForgeTestTriggerBox* TestTriggerBox);
//};
//
