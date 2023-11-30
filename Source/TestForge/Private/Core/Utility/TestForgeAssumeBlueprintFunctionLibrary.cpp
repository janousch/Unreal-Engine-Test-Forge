//#include "TestForgeTestAssumeBlueprintFunctionLibrary.h"
//#include "TestForgeTestActor.h"
//#include "TestForgeTestLogCategory.h"
//
//void UTestForgeTestAssumeBlueprintFunctionLibrary::AssumeTrue(bool bValue, const FString& What,
//                                                        UObject* Context /*= nullptr*/)
//{
//    if (!bValue)
//    {
//        FString Message =
//            FString::Format(TEXT("Assumption failed - {0} - Expected: True, but was: False"),
//                            {What});
//        OnTestSkipped(Context, Message);
//    }
//}
//
//void UTestForgeTestAssumeBlueprintFunctionLibrary::AssumeFalse(bool bValue, const FString& What,
//                                                         UObject* Context /*= nullptr*/)
//{
//    if (bValue)
//    {
//        FString Message =
//            FString::Format(TEXT("Assumption failed - {0} - Expected: False, but was: True"),
//                            {What});
//        OnTestSkipped(Context, Message);
//    }
//}
//
//void UTestForgeTestAssumeBlueprintFunctionLibrary::OnTestSkipped(UObject* Context, const FString& Message)
//{
//    ATestForgeTestActor* TestActor = Cast<ATestForgeTestActor>(Context);
//
//    if (IsValid(TestActor))
//    {
//        TestActor->NotifyOnTestSkipped(Message);
//    }
//    else
//    {
//        UE_LOG(LogTestForgeTest, Log, TEXT("%s"), *Message);
//    }
//}
//
