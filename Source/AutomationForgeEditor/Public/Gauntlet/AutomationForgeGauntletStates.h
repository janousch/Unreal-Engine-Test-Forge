#pragma once

#include <GauntletModule.h>

struct AutomationForgeDALICTESTAUTOMATIONPLUGIN_API FAutomationForgeGauntletStates : FGauntletStates
{
    static FName LoadingNextMap;
    static FName DiscoveringTests;
    static FName Running;
    static FName Finished;
};


