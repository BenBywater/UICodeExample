#include "GGMainMenuButtonContainerViewModel.h"
#include "UICodeExample/UI/Data/UIMenuButtonData.h"
#include "GGMenuButtonViewModel.h"

void UGGMainMenuButtonContainerViewModel::InitializeViewModel(TArray<FUIMenuButtonData> const& buttonData)
{
	for (FUIMenuButtonData const & data : buttonData)
	{
		if (UGGMenuButtonViewModel* viewModel = NewObject<UGGMenuButtonViewModel>(this))
		{
			viewModel->InitializeViewModel(data);
			buttonViewModels.Add(viewModel);
		}
	}
}

TArray<UGGMenuButtonViewModel*> const& UGGMainMenuButtonContainerViewModel::GetButtonViewModels() const
{
	return buttonViewModels;
}