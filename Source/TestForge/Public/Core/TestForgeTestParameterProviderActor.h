#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Actor.h>
#include "TestForgeTestParameterProviderActor.generated.h"

/** Provides a set of parameters for tests, which are run once per parameter. */
UCLASS()
class TESTFORGE_API ATestForgeTestParameterProviderActor : public AActor
{
    GENERATED_BODY()

public:
    /** Gets the parameters to run the test with, one per run. */
    UFUNCTION(BlueprintNativeEvent)
    TArray<UObject*> GetParameters();
};

