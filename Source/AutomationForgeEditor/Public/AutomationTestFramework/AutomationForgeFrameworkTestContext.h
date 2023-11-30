#pragma once

#include <CoreMinimal.h>

class AAutomationForgeTestSuiteActor;
class UAutomationForgeUnitTest;

/** Context to run a single test for the Unreal Automation Test Framework within. */
class FAutomationForgeTestAutomationPluginAutomationTestFrameworkTestContext
{
public:
    AAutomationForgeTestSuiteActor* CurrentTestSuite;

    // Must be a soft pointer in case the class is referencing other blueprints.
    TSoftClassPtr<UClass> UnitTestClass;
    UAutomationForgeUnitTest* CurrentUnitTest = nullptr;

    TMap<FString, FString> OldConsoleVariables;

    /** Associated automation test; all warnings, errors, etc. are routed to the automation test to track */
    FAutomationTestBase* CurTest;

    FAutomationForgeTestAutomationPluginAutomationTestFrameworkTestContext();
};


