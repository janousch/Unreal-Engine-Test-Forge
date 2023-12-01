//#pragma once
//
//#include "TestForgeTestRecordedInputBaseComponent.h"
//#include <CoreMinimal.h>
//#include <Serialization/BufferArchive.h>
//#include "TestForgeCaptureComponent.generated.h"
//
///** Object responsible to record player and level data. The data can then be used to drive the owning test actor of this recording. */
//UCLASS()
//class TESTFORGE_API UTestForgeCaptureComponent : public UTestForgeEmulateInputBaseComponent
//{
//    GENERATED_BODY()
//
//public:
//    /** Start recording the player input for the owning test actor. */
//    void StartRecording();
//
//    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
//                               FActorComponentTickFunction* ThisTickFunction) override;
//    virtual void BeginDestroy() override;
//
//private:
//    void BindPlayerInput();
//
//    UFUNCTION()
//    void OnActionInput(const FName& ActionName, const EInputEvent InputEvent);
//    UFUNCTION()
//    void OnAxisInput(const FName& AxisName, float AxisValue);
//
//    void RecordTransforms();
//
//    /** Save the recorded data. */
//    void Save();
//    bool SaveBinaryArchive(FBufferArchive& BinaryData);
//
//    UPROPERTY()
//    bool bIsRecording = false;
//};
//
