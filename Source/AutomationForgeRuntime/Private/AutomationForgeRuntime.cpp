// Copyright 2023 Ramon Janousch. All Rights Reserved.

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "IAutomationForgeBuildPipeline.h"


class FAutomationForgeBuildPipeline : public IAutomationForgeBuildPipeline
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FAutomationForgeBuildPipeline, AutomationForgeBuildPipeline )



void FAutomationForgeBuildPipeline::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FAutomationForgeBuildPipeline::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}





