//#pragma once
//
//#include <CoreMinimal.h>
//#include "TestForgeTestMapMetaData.generated.h"
//
///** Priority of a test. */
//UENUM()
//enum class ETestForgeTestPriority : uint8
//{
//	// The highest priority possible. Showstopper/blocker.
//	DTP_CriticalPriority = 3 UMETA(DisplayName = "Critical"),
//	// High priority. Major feature functionality etc.
//	DTP_HighPriority = 2 UMETA(DisplayName = "High"),
//	// Medium Priority. Minor feature functionality, major generic content issues.
//	DTP_MediumPriority = 1 UMETA(DisplayName = "Medium"),
//	// Low Priority. Minor content bugs. String errors. Etc.
//	DTP_LowPriority = 0 UMETA(DisplayName = "Low"),
//
//	// Default priority is medium.
//	DTP_Default = DTP_MediumPriority UMETA(Hidden)
//};
//
///**
// * Adds a regex pattern to an internal list that a test will expect to encounter in error or warning logs during its execution.
// * If an expected pattern is not encountered, it will cause this test to fail.
// */
//USTRUCT()
//struct FTestForgeTestExpectedError
//{
//	GENERATED_BODY()
//
//	/** The expected message string. Supports basic regex patterns. */
//	UPROPERTY(EditAnywhere)
//	FString ExpectedErrorPattern;
//
//	/** How many times to expect this error string to be seen. If > 0, the error must be seen the exact number of times. */
//	UPROPERTY(EditAnywhere)
//	int32 Occurrences = 1;
//};
//
///**
// * @brief Metadata for a test level.
// * We store this data in a config file so that we can read necessary data about the test without opening the map.
// */
//USTRUCT()
//struct FTestForgeTestMapMetaData
//{
//	GENERATED_BODY()
//
//	/** When running tests from the console, you can select specific tags, only tests that have one or more of the required tags
//	 * will be run. */
//	UPROPERTY(EditAnywhere)
//	TArray<FString> Tags;
//
//	/** When running tests from the console, you can select a priority, only tests with the given priority or higher will be run. */
//	UPROPERTY(EditAnywhere)
//	ETestForgeTestPriority Priority = ETestForgeTestPriority::DTP_Default;
//
//	/** Errors to be expected while processing this test. */
//	UPROPERTY(EditAnywhere)
//	TArray<FTestForgeTestExpectedError> ExpectedErrors;
//};
//
///** Flags for specifying automation test requirements/behavior */
//UENUM(meta = (BitFlags, UseEnumValuesAsMaskValuesInEditor = "true"))
//enum class ETestForgeAutomationTestFlags
//{
//    //~ Application context required for the test
//    // Test is suitable for running within the editor
//    ATF_EditorContext = 0x00000001,
//    // Test is suitable for running within the client
//    ATF_ClientContext = 0x00000002,
//    // Test is suitable for running within the server
//    ATF_ServerContext = 0x00000004,
//    // Test is suitable for running within a commandlet
//    ATF_CommandletContext = 0x00000008,
//    ATF_ApplicationContextMask = ATF_EditorContext | ATF_ClientContext | ATF_ServerContext
//                                 | ATF_CommandletContext,
//
//    //~ Features required for the test - not specifying means it is valid for any feature combination
//    // Test requires a non-null RHI to run correctly
//    ATF_NonNullRHI = 0x00000100,
//    // Test requires a user instigated session
//    ATF_RequiresUser = 0x00000200,
//    ATF_FeatureMask = ATF_NonNullRHI | ATF_RequiresUser,
//
//    //~ One-off flag to allow for fast disabling of tests without commenting code out
//    // Temp disabled and never returns for a filter
//    ATF_Disabled = 0x00010000,
//
//    //~ Priority of the test
//    // The highest priority possible. Showstopper/blocker.
//    ATF_CriticalPriority = 0x00100000,
//    // High priority. Major feature functionality etc.
//    ATF_HighPriority = 0x00200000,
//    // Mask for High on SetMinimumPriority
//    ATF_HighPriorityAndAbove = ATF_CriticalPriority | ATF_HighPriority,
//    // Medium Priority. Minor feature functionality, major generic content issues.
//    ATF_MediumPriority = 0x00400000,
//    // Mask for Medium on SetMinimumPriority
//    ATF_MediumPriorityAndAbove = ATF_CriticalPriority | ATF_HighPriority | ATF_MediumPriority,
//    // Low Priority. Minor content bugs. String errors. Etc.
//    ATF_LowPriority = 0x00800000,
//    ATF_PriorityMask = ATF_CriticalPriority | ATF_HighPriority | ATF_MediumPriority
//                       | ATF_LowPriority,
//
//    //~ Speed of the test
//    //Super Fast Filter
//    //ATF_SmokeFilter = 0x01000000, Does not work, because this will run the test at engine start where GEngine is null and we need that to create a TestWorld.
//    //Engine Level Test
//    ATF_EngineFilter = 0x02000000,
//    //Product Level Test
//    ATF_ProductFilter = 0x04000000,
//    //Performance Test
//    ATF_PerfFilter = 0x08000000,
//    //Stress Test
//    ATF_StressFilter = 0x10000000,
//    //Negative Test. For tests whose correct expected outcome is failure.
//    //ATF_NegativeFilter = 0x20000000, Does not work.
//    ATF_FilterMask = ATF_EngineFilter | ATF_ProductFilter | ATF_PerfFilter
//                     | ATF_StressFilter,
//
//    ATF_Default = ATF_EditorContext | ATF_ProductFilter
//};
//
///**
// * @brief Metadata for unit tests.
// * We store this data in a config file so that we can read necessary data about the test without creating an object of that unit test.
// */
//USTRUCT()
//struct FTestForgeUnitTestMetaData
//{
//    GENERATED_BODY()
//
//    /** When running tests from the console, you can select specific tags, only tests that have one or more of the required tags
//	 * will be run. */
//    UPROPERTY(EditAnywhere)
//    TArray<FString> Tags;
//
//    /** When running tests from the console, you can select a priority, only tests with the given priority or higher will be run. */
//    UPROPERTY(EditAnywhere)
//    ETestForgeTestPriority Priority = ETestForgeTestPriority::DTP_Default;
//
//    /** Errors to be expected while processing this test. */
//    UPROPERTY(EditAnywhere)
//    TArray<FTestForgeTestExpectedError> ExpectedErrors;
//
//    /** Flags for specifying automation test requirements/behavior */
//    UPROPERTY(EditAnywhere, meta = (Bitmask, BitmaskEnum = "ETestForgeAutomationTestFlags"))
//    int32 AutomationTestFlags = static_cast<int32>(ETestForgeAutomationTestFlags::ATF_Default);
//
//    /** Number of required participants */
//    UPROPERTY(EditAnywhere)
//    int32 RequiredDeviceNum = 1;
//
//	/** The blueprint class of this unit test. */
//    UPROPERTY(VisibleAnywhere)
//    TSoftClassPtr<UClass> UnitTestBlueprintClass = nullptr;
//};
//
