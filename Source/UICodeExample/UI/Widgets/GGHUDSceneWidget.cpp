#include "GGHUDSceneWidget.h"
#include "UICodeExample/UI/ViewModels/GGHUDSceneViewModel.h"
#include "GGProgressBarWidget.h"
#include "../ViewModels/GGProgressBarViewModel.h"
#include <Components/TextBlock.h>

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

float UGGHUDSceneWidget::GetHealth() const
{
	if (healthBarWidget)
	{
		return healthBarWidget->GetProgressValue();
	}

	return -1.f;
}

float UGGHUDSceneWidget::GetAmmo() const
{
	if (ammoCountText)
	{
		return FCString::Atof(*ammoCountText->GetText().ToString());
	}
	return -1.f;
}