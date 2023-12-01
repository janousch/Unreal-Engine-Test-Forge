//#pragma once
//
//#include <CoreMinimal.h>
//#include "TestForgeTestMapSettings.generated.h"
//
///**
// * @brief Global settings for all test maps.
// */
//USTRUCT()
//struct FTestForgeTestMapSettings
//{
//	GENERATED_BODY()
//
//	/** If true no logging will be included in test events. */
//	UPROPERTY(EditAnywhere, Category = "Log")
//	bool bSuppressLogs = false;
//	/** If true then logging with a level of Error will not be recorded in test results. */
//	UPROPERTY(EditAnywhere, Category = "Log", Meta = (EditCondition = "!bSuppressLogs"))
//	bool bSuppressLogErrors = false;
//	/** If true then logging with a level of Warning will not be recorded in test results. */
//	UPROPERTY(EditAnywhere, Category = "Log", Meta = (EditCondition = "!bSuppressLogs"))
//	bool bSuppressLogWarnings = false;
//	/** If true then logging with a level of Warning will be treated as an error. */
//	UPROPERTY(EditAnywhere, Category = "Log", Meta = (EditCondition = "!bSuppressLogs"))
//	bool bElevateLogWarningsToErrors = true;
//};
//
