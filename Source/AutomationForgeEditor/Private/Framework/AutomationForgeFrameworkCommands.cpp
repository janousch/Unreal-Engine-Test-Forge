//#include "AutomationTestFramework/AutomationForgeTestAutomationPluginAutomationTestFrameworkCommands.h"
//#include "AutomationForgeTestEditorLogCategory.h"
//#include "AutomationForgeTestSuiteActor.h"
//#include "AutomationForgeUnitTest.h"
//#include "Settings/AutomationForgeTestAutomationPluginSettings.h"
//#include <Editor.h>
//#include <EngineUtils.h>
//#include <Editor/UnrealEdEngine.h>
//
//bool FAutomationForgeTestAutomationPluginWaitForEndOfTestSuite::Update()
//{
//    if (!GEditor)
//    {
//        return false;
//    }
//
//    if (!GEditor->PlayWorld)
//    {
//        return false;
//    }
//
//    if (!IsValid(Context.CurrentTestSuite))
//    {
//        for (TActorIterator<AAutomationForgeTestSuiteActor> Iter(GEditor->PlayWorld); Iter; ++Iter)
//        {
//            Context.CurrentTestSuite = *Iter;
//        }
//    }
//
//    if (!IsValid(Context.CurrentTestSuite))
//    {
//        return true;
//    }
//
//    if (Context.CurrentTestSuite->IsRunning())
//    {
//        return false;
//    }
//    
//    // Test suite has finished!
//
//    const FAutomationForgeTestSuiteResult& Results = Context.CurrentTestSuite->GetResult();
//    for (auto& Result : Results.TestResults)
//    {
//        if (Result.HasFailed())
//        {
//            Context.CurTest->AddError(Result.FailureMessage);
//        }
//    }
//
//    return true;
//}
//
//bool FAutomationForgeTestAutomationPluginWaitForEndOfUnitTest::Update()
//{
//    if (!GEditor)
//    {
//        return false;
//    }
//
//    if (!IsValid(Context.CurrentUnitTest))
//    {
//        return true;
//    }
//
//    if (Context.CurrentUnitTest->IsRunning())
//    {
//        return false;
//    }
//
//    // Unit test has finished!
//
//    const FAutomationForgeTestSuiteResult& Results = Context.CurrentUnitTest->GetResult();
//    for (auto& Result : Results.TestResults)
//    {
//        if (Result.HasFailed())
//        {
//            Context.CurTest->AddError(Result.FailureMessage);
//        }
//    }
//
//    return true;
//}
//
//bool FAutomationForgeTestAutomationPluginApplyConsoleVariables::Update()
//{
//    Context.OldConsoleVariables.Empty();
//
//    const UAutomationForgeTestAutomationPluginSettings* Settings =
//        GetDefault<UAutomationForgeTestAutomationPluginSettings>();
//
//    for (auto& ConsoleVariable : Settings->ConsoleVariables)
//    {
//        IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(*ConsoleVariable.Key);
//
//        if (CVar)
//        {
//            FString OldValue = CVar->GetString();
//            CVar->Set(*ConsoleVariable.Value);
//
//            Context.OldConsoleVariables.Add(ConsoleVariable.Key, OldValue);
//
//            UE_LOG(LogAutomationForgeTestEditor, Log, TEXT("Setting console variable %s = %s"),
//                   *ConsoleVariable.Key, *ConsoleVariable.Value);
//        }
//    }
//
//    return true;
//}
//
//bool FAutomationForgeTestAutomationPluginRevertConsoleVariables::Update()
//{
//    for (auto& ConsoleVariable : Context.OldConsoleVariables)
//    {
//        IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(*ConsoleVariable.Key);
//
//        if (CVar)
//        {
//            CVar->Set(*ConsoleVariable.Value);
//
//            UE_LOG(LogAutomationForgeTestEditor, Log, TEXT("Restoring console variable %s = %s"),
//                   *ConsoleVariable.Key, *ConsoleVariable.Value);
//        }
//    }
//
//    return true;
//}
//
//bool FAutomationForgeTestAutomationPluginCleanUp::Update()
//{
//	Context.CurrentTestSuite = nullptr;
//	Context.OldConsoleVariables.Empty();
//
//	return true;
//}
//
//
