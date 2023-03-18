#include "GGHUDSceneWidget.h"
#include "UICodeExample/UI/ViewModels/GGHUDSceneViewModel.h"
#include "UICodeExample/UI/ViewModels/GGProgressBarViewModel.h"
#include "GGProgressBarWidget.h"
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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("healthBarWidget is nullptr. Widget is not bound."));
	}

	return -1.f;
}

float UGGHUDSceneWidget::GetAmmo() const
{
	if (ammoCountText)
	{
		return FCString::Atof(*ammoCountText->GetText().ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ammoCountText is nullptr. Widget is not bound."));
	}
	return -1.f;
}