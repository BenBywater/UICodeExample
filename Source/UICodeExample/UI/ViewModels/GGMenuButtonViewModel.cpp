#include "GGMenuButtonViewModel.h"
#include "UICodeExample/UI/Data/UIMenuButtonData.h"

void UGGMenuButtonViewModel::InitializeViewModel(FUIMenuButtonData const & data)
{

	nameTextBinding = data.MenuText;
	buttonID = data.stringID;
	
}

void UGGMenuButtonViewModel::OnButtonClicked()
{
	// buttonID
}
