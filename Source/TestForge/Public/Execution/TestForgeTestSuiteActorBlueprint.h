#pragma once

#include <CoreMinimal.h>
#include <Engine/Blueprint.h>
#include "TestForgeTestSuiteActorBlueprint.generated.h"

/** Suite of automated tests to be run one after another. */
UCLASS(BlueprintType)
class TESTFORGE_API UTestForgeTestSuiteActorBlueprint : public UBlueprint
{
    GENERATED_BODY()

public:
#if WITH_EDITOR
    // UBlueprint interface
    virtual bool SupportedByDefaultBlueprintFactory() const override
    {
        return false;
    }
    // End of UBlueprint interface
#endif
};

