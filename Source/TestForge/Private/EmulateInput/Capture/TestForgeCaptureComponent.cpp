//#include "RecordedInput/TestForgeTestRecordingComponent.h"
//#include "RecordedInput/TestForgeTestRecordInterface.h"
//#include "TestForgeTestInputBlueprintFunctionLibrary.h"
//#include "TestForgeTestLogCategory.h"
//#include <EngineUtils.h>
//#include <Serialization/ArchiveLoadCompressedProxy.h>
//#include <PlatformFeatures.h>
//#include <SaveGameSystem.h>
//#include <Serialization/ArchiveSaveCompressedProxy.h>
//#include <GameFramework/PlayerInput.h>
//#include <Kismet/GameplayStatics.h>
//
//void UTestForgeTestRecordingComponent::StartRecording()
//{
//    Initialize();
//    BindPlayerInput();
//    bIsRecording = true;
//}
//
//void UTestForgeTestRecordingComponent::TickComponent(float DeltaTime, ELevelTick Tick,
//    FActorComponentTickFunction* ThisTickFunction)
//{
//    Super::TickComponent(DeltaTime, Tick, ThisTickFunction);
//
//    if (bIsRecording)
//    {
//        RecordTransforms();
//    }
//}
//
//void UTestForgeTestRecordingComponent::RecordTransforms()
//{
//    const float UnpausedTimeSeconds = GetWorld()->GetUnpausedTimeSeconds();
//    // Iterate over all actors and check if the actor implements the record interface.
//    for (FActorIterator It(GetWorld()); It; ++It)
//    {
//        AActor* Actor = *It;
//        if (IsValid(Actor) && HasRecordInterface(Actor))
//        {
//            // Save the current transform of each scene component.
//
//            TArray<USceneComponent*> SceneComponents;
//            ITestForgeTestRecordInterface::Execute_ComponentsToRecord(Actor, SceneComponents);
//            TArray<FTestForgeTestRecordedSceneComponent> RecordedSceneComponents;
//            for (const auto& SceneComponent : SceneComponents)
//            {
//                if (!SceneComponent->IsRegistered())
//                {
//                    continue;
//                }
//
//                const TArray<uint8> ComponentNameAsBytes =
//                    BytesFromString(SceneComponent->GetName());
//                const FTransform& Transform = SceneComponent->GetComponentTransform();
//                FTestForgeTestRecordedSceneComponent RecordedSceneComponent(ComponentNameAsBytes,
//                                                                      Transform.GetLocation(),
//                                                                      Transform.GetRotation());
//                RecordedSceneComponents.Add(RecordedSceneComponent);
//            }
//            if (RecordedSceneComponents.Num() > 0)
//            {
//                TArray<uint8> NameAsBytes = BytesFromString(GetFullActorName(Actor));
//                FTestForgeTestRecordedActor RecordedActor(NameAsBytes, RecordedSceneComponents,
//                                                    UnpausedTimeSeconds);
//                RecordedActors.Add(RecordedActor);
//            }
//        }
//    }
//}
//
//void UTestForgeTestRecordingComponent::BindPlayerInput()
//{
//    // Get input component from actor
//    const APlayerController* PlayerController =
//        UGameplayStatics::GetPlayerController(GetWorld(), PlayerIndex);
//    if (!IsValid(PlayerController))
//    {
//        UE_LOG(LogTestForgeTest, Warning, TEXT("UTestForgeTestRecordingComponent: Found no PlayerController!"));
//
//        return;
//    }
//    UInputComponent* InputComponent = PlayerController->InputComponent;
//    if (!IsValid(InputComponent) || !IsValid(PlayerController->PlayerInput))
//    {
//        UE_LOG(LogTestForgeTest, Warning,
//               TEXT("UTestForgeTestRecordingComponent: Found no InputComponent/PlayerInput!"));
//
//        return;
//    }
//
//    for (const auto& ActionMapping : PlayerController->PlayerInput->ActionMappings)
//    {
//        const FInputChord InputChord(ActionMapping.Key, ActionMapping.bShift, ActionMapping.bCtrl,
//                                     ActionMapping.bAlt, ActionMapping.bCmd);
//        for (int32 i = 0; i < EInputEvent::IE_MAX; i++)
//        {
//            const EInputEvent InputEvent = static_cast<EInputEvent>(i);
//
//            FInputKeyBinding InputKeyBinding(InputChord, InputEvent);
//            InputKeyBinding.bConsumeInput = false;
//            InputKeyBinding.bExecuteWhenPaused = true;
//            InputKeyBinding.KeyDelegate.GetDelegateForManualSet().BindLambda([=]() {
//                OnActionInput(ActionMapping.ActionName, InputEvent);
//            });
//            InputComponent->KeyBindings.Add(InputKeyBinding);
//        }
//    }
//    for (const auto& AxisMapping : PlayerController->PlayerInput->AxisMappings)
//    {
//        FInputAxisBinding InputAxisBinding(AxisMapping.AxisName);
//        InputAxisBinding.AxisDelegate.GetDelegateForManualSet().BindLambda([=](float AxisValue) {
//            OnAxisInput(AxisMapping.AxisName, AxisValue);
//        });
//        InputComponent->AxisBindings.Add(InputAxisBinding);
//    }
//}
//
//void UTestForgeTestRecordingComponent::OnActionInput(const FName& ActionName, const EInputEvent InputEvent)
//{
//    const TArray<uint8> ActionNameAsBytes = BytesFromString(ActionName.ToString());
//    for (int32 i = RecordedActionInputs.Num() - 1; i >= 0; i--)
//    {
//        FTestForgeTestActorRecordedActionInput& ActionInput = RecordedActionInputs[i];
//        if (ActionInput.ActionName == ActionNameAsBytes)
//        {
//            if (ActionInput.InputEvent != InputEvent)
//            {
//                const float TimeSeconds = GetWorld()->GetUnpausedTimeSeconds();
//                RecordedActionInputs.Add(
//                    FTestForgeTestActorRecordedActionInput(ActionNameAsBytes, InputEvent, TimeSeconds));
//
//                /*UE_LOG(LogTestForgeTest, Log, TEXT("ActionName: %s | InputEvent: %d"),
//                       *ActionName.ToString(), int32(InputEvent));*/
//            }
//
//            return;
//        }
//    }
//
//    // This is the first time that this action gets triggered.
//    const float TimeSeconds = GetWorld()->GetUnpausedTimeSeconds();
//    RecordedActionInputs.Add(
//        FTestForgeTestActorRecordedActionInput(ActionNameAsBytes, InputEvent, TimeSeconds));
//}
//
//void UTestForgeTestRecordingComponent::OnAxisInput(const FName& AxisName, float AxisValue)
//{
//    const TArray<uint8> AxisNameAsBytes = BytesFromString(AxisName.ToString());
//    for (int32 i = RecordedAxisInputs.Num() - 1; i >= 0; i--)
//    {
//        FTestForgeTestActorRecordedAxisInput& AxisInput = RecordedAxisInputs[i];
//        if (AxisInput.AxisName == AxisNameAsBytes)
//        {
//            if (!FMath::IsNearlyEqual(AxisInput.AxisValue, AxisValue, 0.1f))
//            {
//                const float TimeSeconds = GetWorld()->GetUnpausedTimeSeconds();
//                RecordedAxisInputs.Add(
//                    FTestForgeTestActorRecordedAxisInput(AxisNameAsBytes, AxisValue, TimeSeconds));
//
//                /*UE_LOG(LogTestForgeTest, Log, TEXT("AxisName: %s | AxisValue: %f"), *AxisName.ToString(),
//                       AxisValue);*/
//            }
//
//            return;
//        }
//    }
//
//    // This is the first time that this action gets triggered.
//    const float TimeSeconds = GetWorld()->GetUnpausedTimeSeconds();
//    RecordedAxisInputs.Add(FTestForgeTestActorRecordedAxisInput(AxisNameAsBytes, AxisValue, TimeSeconds));
//}
//
//void UTestForgeTestRecordingComponent::BeginDestroy()
//{
//    if (bIsRecording)
//    {
//        Save();
//    }
//
//    UObject::BeginDestroy();
//}
//
//void UTestForgeTestRecordingComponent::Save()
//{
//    // Only save if this object was created by an TestForgeTestActor.
//    if (FullSavePath.IsEmpty())
//    {
//        return;
//    }
//
//    FBufferArchive BufferArchive;
//    FTestForgeTestRecordedSaveData RecordedSaveData;
//    {
//        RecordedSaveData.ActionInputs = RecordedActionInputs;
//        RecordedSaveData.AxisInputs = RecordedAxisInputs;
//        RecordedSaveData.RecordedActors = RecordedActors;
//    }
//    BufferArchive << RecordedSaveData;
//
//    //Save and log
//    if (SaveBinaryArchive(BufferArchive))
//    {
//        UE_LOG(LogTestForgeTest, Log, TEXT("Recorded data have been saved!"));
//    }
//    else
//    {
//        UE_LOG(LogTestForgeTest, Error, TEXT("Failed to save recorded data!"));
//    }
//}
//
//bool UTestForgeTestRecordingComponent::SaveBinaryArchive(FBufferArchive& BinaryData)
//{
//    //Compress and save
//
//    TArray<uint8> CompressedData;
//
//    FArchiveSaveCompressedProxy Compressor = FArchiveSaveCompressedProxy(CompressedData, NAME_Zlib);
//
//    if (Compressor.GetError())
//    {
//        UE_LOG(LogTestForgeTest, Error, TEXT("Cannot save, compressor error: %s"), *FullSavePath);
//
//        return false;
//    }
//
//    Compressor << BinaryData;
//    Compressor.Flush();
//
//    ISaveGameSystem* SaveSystem = IPlatformFeaturesModule::Get().GetSaveGameSystem();
//    bool bSuccess = SaveSystem->SaveGame(false, *FullSavePath, PlayerIndex, CompressedData);
//
//    Compressor.FlushCache();
//    CompressedData.Empty();
//    Compressor.Close();
//
//    BinaryData.FlushCache();
//    BinaryData.Empty();
//    BinaryData.Close();
//
//    return bSuccess;
//}
//
