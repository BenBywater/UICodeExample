#pragma once

#include "CoreMinimal.h"
#include "GGSceneViewModel.h"
#include "GGMainMenuSceneViewModel.generated.h"

class UGGMainMenuButtonContainerViewModel;

UCLASS(BlueprintType)
class UICODEEXAMPLE_API UGGMainMenuSceneViewModel : public UGGSceneViewModel
{
	GENERATED_BODY()

public:
	void InitializeSceneViewModel(UUISceneDataPayload* scenePayload) override;

	UGGMainMenuButtonContainerViewModel* GetContainerViewModel() const;

private:
	UGGMainMenuButtonContainerViewModel* ContainerViewModel = nullptr;
};