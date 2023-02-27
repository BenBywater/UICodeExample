#include "GGMainMenuSceneViewModel.h"
#include "GGMainMenuButtonContainerViewModel.h"
#include "UICodeExample/UI/Data/UIMainMenuScenePayload.h"


void UGGMainMenuSceneViewModel::InitializeSceneViewModel(UUISceneDataPayload* scenePayload)
{
	ContainerViewModel = NewObject<UGGMainMenuButtonContainerViewModel>(this);

	if (UUIMainMenuScenePayload* mainMenuScenePayload = Cast<UUIMainMenuScenePayload>(scenePayload))
	{
		ContainerViewModel->InitializeViewModel(mainMenuScenePayload->menuButtonData);
	}
	// Log Error
}

UGGMainMenuButtonContainerViewModel* UGGMainMenuSceneViewModel::GetContainerViewModel() const
{
	return ContainerViewModel;
}
