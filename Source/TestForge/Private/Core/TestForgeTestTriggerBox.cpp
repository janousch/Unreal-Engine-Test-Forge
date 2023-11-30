//#include "TestForgeTestTriggerBox.h"
//#include "TestForgeTestLogCategory.h"
//
//void ATestForgeTestTriggerBox::BeginPlay()
//{
//    Super::BeginPlay();
//
//    bWasTriggered = false;
//
//    OnActorBeginOverlap.AddDynamic(this, &ATestForgeTestTriggerBox::OnActorBeginOverlapBroadcast);
//}
//
//bool ATestForgeTestTriggerBox::WasTriggered() const
//{
//    return bWasTriggered;
//}
//
//void ATestForgeTestTriggerBox::ResetTriggerState()
//{
//    bWasTriggered = false;
//}
//
//void ATestForgeTestTriggerBox::OnActorBeginOverlapBroadcast(AActor* OverlappedActor, AActor* OtherActor)
//{
//    bWasTriggered = true;
//
//    UE_LOG(LogTestForgeTest, Log, TEXT("%s was triggered by %s."), *GetName(), *OtherActor->GetName());
//}
//
