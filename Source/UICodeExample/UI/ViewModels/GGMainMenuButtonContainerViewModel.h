#pragma once

#include "CoreMinimal.h"
#include "GGViewModel.h"
#include "UICodeExample/UI/Data/UIMenuButtonData.h"
#include "GGMainMenuButtonContainerViewModel.generated.h"

struct FUIMenuButtonData;
class UGGMenuButtonViewModel;

UCLASS()
class UICODEEXAMPLE_API UGGMainMenuButtonContainerViewModel : public UGGViewModel
{
	GENERATED_BODY()

public:
	void InitializeViewModel(TArray<FUIMenuButtonData> const& buttonData);

	TArray<UGGMenuButtonViewModel*> const& GetButtonViewModels() const;
private:
	UPROPERTY()
	TArray<UGGMenuButtonViewModel*> buttonViewModels;
};
