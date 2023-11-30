//#include "RecordedInput/TestForgeTestRecordedInputBaseComponent.h"
//#include "RecordedInput/TestForgeTestRecordInterface.h"
//#include "TestForgeTestInputBlueprintFunctionLibrary.h"
//#include <EngineUtils.h>
//#include <Serialization/ArchiveLoadCompressedProxy.h>
//#include <SaveGameSystem.h>
//#include <GameFramework/PlayerInput.h>
//
//UTestForgeTestRecordedInputBaseComponent::UTestForgeTestRecordedInputBaseComponent()
//{
//    PrimaryComponentTick.bCanEverTick = true;
//    PrimaryComponentTick.bTickEvenWhenPaused = true;
//    PrimaryComponentTick.bStartWithTickEnabled = true;
//}
//
//bool UTestForgeTestRecordedInputBaseComponent::HasRecordInterface(const AActor* Actor)
//{
//    return Actor->GetClass()->ImplementsInterface(UTestForgeTestRecordInterface::StaticClass());
//}
//
//TArray<uint8> UTestForgeTestRecordedInputBaseComponent::BytesFromString(const FString& String)
//{
//    const uint32 Size = String.Len();
//
//    TArray<uint8> Bytes;
//    Bytes.AddUninitialized(Size);
//    StringToBytes(String, Bytes.GetData(), Size);
//
//    return Bytes;
//}
//
//FString UTestForgeTestRecordedInputBaseComponent::StringFromBytes(const TArray<uint8>& Bytes)
//{
//
//    const uint32 Size = Bytes.Num();
//    FString String = BytesToString(Bytes.GetData(), Size);
//
//    return String;
//}
//
//void UTestForgeTestRecordedInputBaseComponent::Initialize()
//{
//    // Set the FullSavePath to "Game\Saved\Automation\RecordedTestData\".
//
//    const FString FolderForRecordings =
//        FPaths::Combine(FPaths::AutomationDir(), TEXT("RecordedTestData"));
//    const FString OwnerName = GetOwner()->GetName();
//    const FString Suffix = TEXT("_Recording");
//    FullSavePath = FPaths::Combine(FolderForRecordings, GetWorld()->GetName(), OwnerName + Suffix);
//}
//
