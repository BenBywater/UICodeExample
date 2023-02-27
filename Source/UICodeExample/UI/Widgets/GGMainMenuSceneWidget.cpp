#include "GGMainMenuSceneWidget.h"
#include "UICodeExample/UI/ViewModels/GGMainMenuSceneViewModel.h"
#include "UICodeExample/UI/ViewModels/GGMainMenuButtonContainerViewModel.h"
#include "GGMainMenuButtonContainerWidget.h"

void UGGMainMenuSceneWidget::SetDataContext(UGGViewModel* inViewModel)
{
	Super::SetDataContext(inViewModel);
	if (UGGMainMenuSceneViewModel* sceneViewModel = GetViewModel<UGGMainMenuSceneViewModel>())
	{
		MainMenuButtonContainerWidget->SetDataContext(sceneViewModel->GetContainerViewModel());
	}
}
