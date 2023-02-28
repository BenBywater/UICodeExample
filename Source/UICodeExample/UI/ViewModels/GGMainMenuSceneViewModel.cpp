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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could cast payload to MainMenuScenePayload"));
	}
}

UGGMainMenuButtonContainerViewModel* UGGMainMenuSceneViewModel::GetContainerViewModel() const
{
	return ContainerViewModel;
}
