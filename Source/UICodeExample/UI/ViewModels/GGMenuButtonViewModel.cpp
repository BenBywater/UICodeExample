#include "GGMenuButtonViewModel.h"
#include "UICodeExample/UI/Data/UIMenuButtonData.h"
#include "UICodeExample/PlayerController/GGPlayerController.h"

void UGGMenuButtonViewModel::InitializeViewModel(FUIMenuButtonData const & data)
{

	nameTextBinding = data.MenuText;
	buttonID = data.stringID;
	
}

void UGGMenuButtonViewModel::OnButtonClicked()
{
	UWorld* world = GetWorld();
	AGGPlayerController* playerController = Cast<AGGPlayerController>(world->GetFirstPlayerController());

	if (playerController)
	{
		playerController->OnMainMenuCommand(buttonID);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller nullptr"));
	}
}
