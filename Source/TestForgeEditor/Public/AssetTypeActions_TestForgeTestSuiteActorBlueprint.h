#pragma once

#include <AssetTypeCategories.h>
#include <CoreMinimal.h>
#include <AssetTypeActions/AssetTypeActions_Blueprint.h>
#include <Toolkits/IToolkitHost.h>

class UFactory;

/** Asset action for creating new test suite actor blueprints with special initial blueprint graphs. */
class FAssetTypeActions_TestForgeTestSuiteActorBlueprint : public FAssetTypeActions_Blueprint
{
public:
    FAssetTypeActions_TestForgeTestSuiteActorBlueprint(EAssetTypeCategories::Type InAssetTypeCategory);

    // IAssetTypeActions Implementation
    virtual FText GetName() const override;
    virtual UClass* GetSupportedClass() const override;
    virtual uint32 GetCategories() override;
    // End IAssetTypeActions Implementation

    // FAssetTypeActions_Blueprint interface
    virtual UFactory* GetFactoryForBlueprintType(UBlueprint* InBlueprint) const override;

private:
    EAssetTypeCategories::Type AssetTypeCategory;
};

