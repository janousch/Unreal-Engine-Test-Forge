//#include "TestForgeDelayUntilTriggeredAction.h"
//#include "TestForgeTestTriggerBox.h"
//
//FTestForgeDelayUntilTriggeredAction::FTestForgeDelayUntilTriggeredAction(const FLatentActionInfo& LatentInfo,
//                                                             ATestForgeTestTriggerBox* InTestTriggerBox)
//    : TestTriggerBox(InTestTriggerBox)
//    , ExecutionFunction(LatentInfo.ExecutionFunction)
//    , OutputLink(LatentInfo.Linkage)
//    , CallbackTarget(LatentInfo.CallbackTarget)
//{
//}
//
//void FTestForgeDelayUntilTriggeredAction::UpdateOperation(FLatentResponse& Response)
//
//{
//    bool bWasTriggered = !IsValid(TestTriggerBox) || TestTriggerBox->WasTriggered();
//    Response.FinishAndTriggerIf(bWasTriggered, ExecutionFunction, OutputLink, CallbackTarget);
//}
//
//#if WITH_EDITOR
//FString FTestForgeDelayUntilTriggeredAction::GetDescription() const
//{
//    FString TriggerBoxName = IsValid(TestTriggerBox) ? TestTriggerBox->GetName() : TEXT("nullptr");
//    return FString::Printf(TEXT("Delay (until {0} was triggered)"), *TriggerBoxName);
//}
//#endif
//
