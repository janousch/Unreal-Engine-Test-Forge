//#pragma once
//
//#include "AutomationTestFramework/AutomationForgeTestAutomationPluginAutomationTestFrameworkTestContext.h"
//#include "Settings/AutomationForgeTestMapMetaData.h"
//#include "Settings/AutomationForgeTestMapSettings.h"
//#include <CoreMinimal.h>
//#include <Misc/AutomationTest.h>
//
///** Single test to be registered with the Unreal Automation Test Framework. Implementation based on IMPLEMENT_SIMPLE_AUTOMATION_TEST_PRIVATE macro. */
//class FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest : FAutomationTestBase
//{
//public:
//	FAutomationForgeTestAutomationPluginAutomationTestFrameworkTest(const FString& InMapName, const FAutomationForgeTestMapMetaData& InMapMetaData);
//
//    /**
//	 * If true no logging will be included in test events.
//	 *
//	 * @return true to suppress logs
//	 */
//    virtual bool SuppressLogs() override;
//    /**
//	 * If returns true then logging with a level of Error will not be recorded in test results.
//	 *
//	 * @return false to make errors errors
//	 */
//    virtual bool SuppressLogErrors() override;
//    /**
//	 * If returns true then logging with a level of Warning will not be recorded in test results.
//	 *
//	 * @return true to make warnings errors
//	 */
//    virtual bool SuppressLogWarnings() override;
//    /**
//	 * If returns true then logging with a level of Warning will be treated as an error.
//	 *
//	 * @return true to make warnings errors
//	 */
//    virtual bool ElevateLogWarningsToErrors() override;
//
//    virtual uint32 GetTestFlags() const override;
//    virtual uint32 GetRequiredDeviceNum() const override;
//    virtual FString GetTestSourceFileName() const override;
//    virtual int32 GetTestSourceFileLine() const override;
//
//    FString GetMapName() const;
//
//protected:
//    virtual void GetTests(TArray<FString>& OutBeautifiedNames,
//                          TArray<FString>& OutTestCommands) const override;
//    virtual bool RunTest(const FString& Parameters) override;
//    virtual FString GetBeautifiedTestName() const override;
//
//private:
//    /** Level name of this test. */
//    FString MapName;
//    /** Meta data for this test (tags, priority, expected errors and warnings). */
//	FAutomationForgeTestMapMetaData MapMetaData;
//    /** Global test map settings (suppress warnings or errors). */
//	FAutomationForgeTestMapSettings TestMapSettings;
//    FAutomationForgeTestAutomationPluginAutomationTestFrameworkTestContext Context;
//};
//
//
