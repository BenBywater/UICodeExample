#include "GGHUDSceneWidget.h"
#include "UICodeExample/UI/ViewModels/GGHUDSceneViewModel.h"
#include "GGProgressBarWidget.h"
#include "../ViewModels/GGProgressBarViewModel.h"

void UGGHUDSceneWidget::SetDataContext(UGGViewModel* inViewModel)
{
	Super::SetDataContext(inViewModel);

	if (UGGHUDSceneViewModel* hudSceneViewModel = GetViewModel<UGGHUDSceneViewModel>())
	{
		if (healthBarWidget)
		{
			healthBarWidget->SetDataContext(hudSceneViewModel->GetHealthBarViewModel());
		}
	}

}
