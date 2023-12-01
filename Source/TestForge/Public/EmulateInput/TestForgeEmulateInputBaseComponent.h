//#pragma once
//
//#include <CoreMinimal.h>
//#include <Components/ActorComponent.h>
//#include <Serialization/BufferArchive.h>
//#include "TestForgeEmulateInputBaseComponent.generated.h"
//
//static const FString Underscore(TEXT("_"));
//static constexpr int PlayerIndex = 0;
//
///**
// * @brief Container for one player action input.
// */
//USTRUCT()
//struct FTestForgeTestActorRecordedActionInput
//{
//    GENERATED_BODY()
//
//    FTestForgeTestActorRecordedActionInput() = default;
//    FTestForgeTestActorRecordedActionInput(const TArray<uint8>& ActionName, const EInputEvent InputEvent,
//                                     const float UnpausedTimeSeconds)
//        : ActionName(ActionName)
//        , InputEvent(InputEvent)
//        , UnpausedTimeSeconds(UnpausedTimeSeconds)
//    {
//    }
//
//    friend FArchive& operator<<(FArchive& Ar, FTestForgeTestActorRecordedActionInput& RecordedActionInput)
//    {
//        Ar << RecordedActionInput.ActionName;
//        Ar << RecordedActionInput.InputEvent;
//        Ar << RecordedActionInput.UnpausedTimeSeconds;
//        return Ar;
//    }
//    
//    TArray<uint8> ActionName;
//    TEnumAsByte<EInputEvent> InputEvent;
//    /** Time in seconds since world was brought up for play, IS NOT stopped when game pauses, IS dilated/clamped. */
//    float UnpausedTimeSeconds = 0.f;
//};
//
///**
// * @brief Container for one player axis input.
// */
//USTRUCT()
//struct FTestForgeTestActorRecordedAxisInput
//{
//    GENERATED_BODY()
//
//    FTestForgeTestActorRecordedAxisInput() = default;
//    FTestForgeTestActorRecordedAxisInput(const TArray<uint8>& AxisName, const float AxisValue,
//                                   const float UnpausedTimeSeconds)
//        : AxisName(AxisName)
//        , AxisValue(AxisValue)
//        , UnpausedTimeSeconds(UnpausedTimeSeconds)
//    {
//    }
//
//    friend FArchive& operator<<(FArchive& Ar, FTestForgeTestActorRecordedAxisInput& RecordedAxisInput)
//    {
//        Ar << RecordedAxisInput.AxisName;
//        Ar << RecordedAxisInput.AxisValue;
//        Ar << RecordedAxisInput.UnpausedTimeSeconds;
//        return Ar;
//    }
//    
//    TArray<uint8> AxisName;
//    float AxisValue;
//    /** Time in seconds since world was brought up for play, IS NOT stopped when game pauses, IS dilated/clamped. */
//    float UnpausedTimeSeconds = 0.f;
//};
//
///**
// * @brief Container for one scene component transform.
// */
//USTRUCT()
//struct FTestForgeTestRecordedSceneComponent
//{
//    GENERATED_USTRUCT_BODY()
//
//public:
//    FTestForgeTestRecordedSceneComponent() = default;
//    FTestForgeTestRecordedSceneComponent(const TArray<uint8>& Name, const FVector& Location,
//                                   const FQuat& Quat)
//        : Name(Name)
//        , Location(Location)
//        , Rotation(Quat.Euler())
//    {
//    }
//
//    const TArray<uint8>& GetName() const
//    {
//        return Name;
//    }
//    FVector GetLocation() const
//    {
//        return Location;
//    }
//    FQuat GetQuat() const
//    {
//        return FRotator::MakeFromEuler(Rotation).Quaternion();
//    }
//
//    friend FArchive& operator<<(FArchive& Ar,
//                                FTestForgeTestRecordedSceneComponent& SceneComponentTransform)
//    {
//        Ar << SceneComponentTransform.Name;
//        Ar << SceneComponentTransform.Location;
//        Ar << SceneComponentTransform.Rotation;
//        return Ar;
//    }
//
//private:
//    TArray<uint8> Name;
//    FVector_NetQuantize Location;
//    FVector_NetQuantize Rotation;
//};
//
///**
// * @brief Container for an actor and its component at a specific time.
// */
//USTRUCT()
//struct FTestForgeTestRecordedActor
//{
//    GENERATED_USTRUCT_BODY()
//
//    FTestForgeTestRecordedActor() = default;
//    FTestForgeTestRecordedActor(const TArray<uint8>& Name,
//                          const TArray<FTestForgeTestRecordedSceneComponent>& ComponentsSaveData,
//                          const float UnpausedTimeSeconds)
//        : Name(Name)
//        , ComponentsSaveData(ComponentsSaveData)
//        , UnpausedTimeSeconds(UnpausedTimeSeconds)
//    {
//    }
//
//    TArray<uint8> Name;
//    TArray<FTestForgeTestRecordedSceneComponent> ComponentsSaveData;
//    /** Time in seconds since world was brought up for play, IS NOT stopped when game pauses, IS dilated/clamped. */
//    float UnpausedTimeSeconds = 0.f;
//
//    friend FArchive& operator<<(FArchive& Ar, FTestForgeTestRecordedActor& ActorData)
//    {
//        Ar << ActorData.Name;
//        Ar << ActorData.ComponentsSaveData;
//        Ar << ActorData.UnpausedTimeSeconds;
//        return Ar;
//    }
//
//    FORCEINLINE bool operator==(const FTestForgeTestRecordedActor& A) const
//    {
//        return A.Name == Name;
//    }
//};
//
///**
// * @brief Archive container struct for the recording.
// */
//USTRUCT()
//struct FTestForgeTestRecordedSaveData
//{
//    GENERATED_USTRUCT_BODY()
//        
//    TArray<FTestForgeTestActorRecordedActionInput> ActionInputs;
//    TArray<FTestForgeTestActorRecordedAxisInput> AxisInputs;
//    TArray<FTestForgeTestRecordedActor> RecordedActors;
//
//    friend FArchive& operator<<(FArchive& Ar, FTestForgeTestRecordedSaveData& RecordedInputData)
//    {
//        Ar << RecordedInputData.ActionInputs;
//        Ar << RecordedInputData.AxisInputs;
//        Ar << RecordedInputData.RecordedActors;
//        return Ar;
//    }
//};
//
///** Base class for recording and replaying recorded player input. */
//UCLASS(Abstract)
//class TESTFORGE_API UTestForgeEmulateInputBaseComponent : public UActorComponent
//{
//    GENERATED_BODY()
//
//public:
//    UTestForgeEmulateInputBaseComponent();
//
//protected:
//    UPROPERTY()
//    TArray<FTestForgeTestActorRecordedActionInput> RecordedActionInputs;
//    UPROPERTY()
//    TArray<FTestForgeTestActorRecordedAxisInput> RecordedAxisInputs;
//    UPROPERTY()
//    TArray<FTestForgeTestRecordedActor> RecordedActors;
//
//    /** Full file path for the saved recording. */
//    UPROPERTY()
//    FString FullSavePath;
//
//    void Initialize();
//
//    /** Does the actor implements the record interface? */
//    static bool HasRecordInterface(const AActor* Actor);
//
//    static TArray<uint8> BytesFromString(const FString& String);
//    static FString StringFromBytes(const TArray<uint8>& Bytes);
//
//    FORCEINLINE bool IsPlacedActor(const AActor* Actor) const
//    {
//        return Actor->IsNetStartupActor();
//    }
//
//    FORCEINLINE FString GetFullActorName(const AActor* Actor) const
//    {
//        const FString ActorName = Actor->GetName();
//
//        //This is only valid for placed Actors. Runtime Actors are always in the persistent.
//        if (IsPlacedActor(Actor))
//        {
//            const FString LevelName = Actor->GetLevel()->GetOuter()->GetName();
//            const bool bAlreadyHas = ActorName.Contains(LevelName);
//
//            if (bAlreadyHas)
//            {
//                return ActorName;
//            }
//            else
//            {
//                return LevelName + Underscore + ActorName;
//            }
//        }
//
//        return ActorName;
//    }
//
//    template<typename TArrayType>
//    FORCEINLINE static bool IsArrayEmpty(const TArrayType& InArray)
//    {
//        return InArray.Num() <= 0;
//    }
//};
//
