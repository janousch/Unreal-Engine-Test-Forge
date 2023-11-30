#pragma once

#include "TestForgeTestRecordedInputBaseComponent.h"
#include <CoreMinimal.h>
#include <Serialization/BufferArchive.h>
#include "TestForgeTestReplayComponent.generated.h"

/** Object responsible to record player and level data. The data can then be used to drive the owning test actor of this recording. */
UCLASS()
class TESTFORGE_API UTestForgeTestReplayComponent : public UTestForgeEmulateInputBaseComponent
{
    GENERATED_BODY()

public:
    /** Load the player recording of the owning test actor. */
    void LoadRecording();

    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                               FActorComponentTickFunction* ThisTickFunction) override;

private:
    UPROPERTY()
    bool bIsPlayingRecording = false;

    // Keep track of the next action input.
    UPROPERTY()
    int32 RecordedActionInputsIndex = 0;
    // Keep track of the next axis input.
    UPROPERTY()
    int32 RecordedAxisInputsIndex = 0;
    // Keep track of the next actor recording.
    UPROPERTY()
    int32 RecordedActorsIndex = 0;

    /** Read and uncompress the recorded data. */
    bool LoadBinaryArchive();
    bool UnpackBinaryArchive(FMemoryReader FromBinary);

    /** Update the transforms of the recorded scene components. */
    void UpdateTransforms();
    /** Play the next action input. */
    void ProcessNextActionInput();
    /** Play the next axis input. */
    void ProcessNextAxisInput();
};

