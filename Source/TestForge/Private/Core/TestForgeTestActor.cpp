// Copyright 2023 Ramon Janousch. All Rights Reserved.

#include "Core/TestForgeTestActor.h"
//#include "RecordedInput/TestForgeTestRecordingComponent.h"
//#include "RecordedInput/TestForgeTestReplayComponent.h"
//#include "TestForgeTestAssertBlueprintFunctionLibrary.h"
#include "Core/TestForgeLogCategory.h"
//#include "TestForgeTestParameterProviderActor.h"
//#include "TestForgeTestReportWriterJUnit.h"
//#include "TestForgeTestResult.h"
//#include "Settings/TestForgeTestAutomationPluginSettings.h"

ATestForgeTestActor::ATestForgeTestActor()
{
    TimeoutInSeconds = 30.0f;

//    RecordingComponent =
//        CreateDefaultSubobject<UTestForgeTestRecordingComponent>(TEXT("RecordingComponent"));
//    ReplayComponent = CreateDefaultSubobject<UTestForgeTestReplayComponent>(TEXT("ReplayComponent"));
}

//void ATestForgeTestActor::ApplyParameterProviders()
//{
//    for (int32 Index = 0; Index < ParameterProviders.Num(); ++Index)
//    {
//        ATestForgeTestParameterProviderActor* Provider = ParameterProviders[Index];
//
//        if (!IsValid(Provider))
//        {
//            UE_LOG(LogTestForgeTest, Error,
//                   TEXT("ATestForgeTestActor::ApplyParameterProviders - %s has invalid parameter "
//                        "provider at index %i, skipping."),
//                   *GetName(), Index);
//
//            continue;
//        }
//
//        TArray<UObject*> AdditionalParameters = Provider->GetParameters();
//        Parameters.Append(AdditionalParameters);
//
//        UE_LOG(LogTestForgeTest, Log,
//               TEXT("ATestForgeTestActor::ApplyParameterProviders - %s appended %i additional parameters "
//                    "provided by %s."),
//               *GetName(), AdditionalParameters.Num(), *Provider->GetName());
//    }
//}

void ATestForgeTestActor::RunTest(UObject* TestParameter)
{
    CurrentParameter = TestParameter;
    bHasResult = false;
    bHadTimeout = false;

    if (!SkipReason.IsEmpty())
    {
        NotifyOnTestSkipped();
        return;
    }

    NotifyOnAssume();

    if (bHasResult)
    {
        // This can happen with failed assumptions, for instance.
        return;
    }

    NotifyOnArrange();
    NotifyOnAct();
}

//void ATestForgeTestActor::FinishAct()
//{
//    if (bHasResult)
//    {
//        UE_LOG(LogTestForgeTest, Warning,
//               TEXT("Test %s already has a result. This can happen after a timeout due to delays, "
//                    "but if not, make sure not to call FinishAct more than once."),
//               *GetName());
//        return;
//    }
//
//    auto* ActiveParam = CurrentParameter;
//
//    NotifyOnAssert(CurrentParameter);
//
//    if (!bHasResult && (ActiveParam == CurrentParameter))
//    {
//        NotifyOnTestSuccessful();
//    }
//}

float ATestForgeTestActor::GetTimeoutInSeconds() const
{
    return TimeoutInSeconds;
}

//void ATestForgeTestActor::Timeout()
//{
//    // Enough waiting. Let's see the results.
//    UE_LOG(LogTestForgeTest, Warning, TEXT("Timed out after %f seconds"), GetTimeoutInSeconds());
//
//    bHadTimeout = true;
//
//    FinishAct();
//}

TArray<TSoftObjectPtr<UObject>> ATestForgeTestActor::GetParameters() const
{
    return Parameters;
}

UObject* ATestForgeTestActor::GetCurrentParameter() const
{
    return CurrentParameter;
}

//TSharedPtr<FTestForgeTestResultData> ATestForgeTestActor::CollectResults() const
//{
//    return MakeShareable(new FTestForgeTestResultData());
//}
//
//FTestForgeTestReportWriterSet ATestForgeTestActor::GetReportWriters() const
//{
//    FTestForgeTestReportWriterSet ReportWriters;
//    ReportWriters.Add(MakeShareable(new FTestForgeTestReportWriterJUnit()));
//    return ReportWriters;
//}
//
//void ATestForgeTestActor::NotifyOnTestSuccessful()
//{
//    if (bHasResult)
//    {
//        return;
//    }
//
//    bHasResult = true;
//
//    OnTestSuccessful.Broadcast(this, CurrentParameter);
//}
//
//void ATestForgeTestActor::NotifyOnTestFailed(const FString& Message)
//{
//    if (bHasResult)
//    {
//        return;
//    }
//
//    bHasResult = true;
//
//    UE_LOG(LogTestForgeTest, Error, TEXT("%s"), *Message);
//
//    OnTestFailed.Broadcast(this, CurrentParameter, Message);
//}

void ATestForgeTestActor::NotifyOnTestSkipped()
{
    if (bHasResult)
    {
        return;
    }

    bHasResult = true;

    OnTestSkipped.Broadcast(this, CurrentParameter, SkipReason);
}

void ATestForgeTestActor::NotifyOnAssume()
{
    ReceiveOnAssume();
}

void ATestForgeTestActor::NotifyOnArrange()
{
    ReceiveOnArrange();
}

void ATestForgeTestActor::NotifyOnAct()
{
    ReceiveOnAct();
}

void ATestForgeTestActor::NotifyOnAssert()
{
    /*UTestForgeTestAssertBlueprintFunctionLibrary::AssertFalse(bHadTimeout,
                                                        TEXT("The test had a timeout."), this);*/
														
    ReceiveOnAssert();
}

//void ATestForgeTestActor::BeginPlay()
//{
//    Super::BeginPlay();
//
//    if (RecordingSettings.bUseRecordedPlayerInput)
//    {
//        if (RecordingSettings.bIsRecording && IsValid(RecordingComponent))
//        {
//            RecordingComponent->StartRecording();
//        }
//        else if (IsValid(ReplayComponent))
//        {
//            ReplayComponent->LoadRecording();
//        }
//    }
//}
//
//#if WITH_EDITOR
//void ATestForgeTestActor::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
//{
//	Super::PostEditChangeChainProperty(PropertyChangedEvent);
//    
//	const FName PropertyName = PropertyChangedEvent.GetPropertyName();
//	const FName PropertyHead = PropertyChangedEvent.PropertyChain.GetHead()->GetValue()->GetFName();
//	const FName PropertyTail = PropertyChangedEvent.PropertyChain.GetTail()->GetValue()->GetFName();
//	if (PropertyHead == GET_MEMBER_NAME_CHECKED(ATestForgeTestActor, TestMetaData))
//	{
//		UTestForgeTestAutomationPluginSettings::SetTestMapMetaData(this, TestMetaData);
//	}
//}
//#endif
//
//bool ATestForgeTestActor::IsRecording() const
//{
//    return RecordingSettings.bIsRecording;
//}
//
//void ATestForgeTestActor::ReceiveOnAct_Implementation()
//{
//    FinishAct();
//}
//
