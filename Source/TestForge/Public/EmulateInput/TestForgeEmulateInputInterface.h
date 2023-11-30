#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TestForgeTestRecordInterface.generated.h"

UINTERFACE(Category = "TestAutomation", BlueprintType, meta = (DisplayName = "TestForge Test Record Interface"))
class UTestForgeTestRecordInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * @brief Every actor that implements this interface will be recorded in automated test scenes.
 */
class TESTFORGE_API ITestForgeTestRecordInterface
{
	GENERATED_BODY()

public:
	/**
	* Holds the array of components that you want to record the transform for the automated test.
	* @param Components - The Components that you want to save with the Actor.
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "TestAutomation")
    void ComponentsToRecord(TArray<USceneComponent*>& Components);
};

