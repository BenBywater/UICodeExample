#include "GGMainMenuSceneWidget.h"
#include "UICodeExample/UI/ViewModels/GGMainMenuSceneViewModel.h"
#include "UICodeExample/UI/ViewModels/GGMainMenuButtonContainerViewModel.h"
#include "GGMainMenuButtonContainerWidget.h"
#include "UICodeExample/UI/ViewModels/GGMenuButtonViewModel.h"

void UGGMainMenuSceneWidget::SetDataContext(UGGViewModel* inViewModel)
{
	Super::SetDataContext(inViewModel);
	if (UGGMainMenuSceneViewModel* sceneViewModel = GetViewModel<UGGMainMenuSceneViewModel>())
	{
		if (MainMenuButtonContainerWidget)
		{
			MainMenuButtonContainerWidget->SetDataContext(sceneViewModel->GetContainerViewModel());
		}
	}
}

void UGGMainMenuSceneWidget::UpdateButtonContainerWidget(TArray<UGGMenuButtonViewModel*> viewModels)
{
	if (MainMenuButtonContainerWidget)
	{
		MainMenuButtonContainerWidget->ConstructCollectionWidgets(viewModels);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MainMenuButtonContainerWidget is nullptr. Cannot Update ButtonContainerWidget with new view models."));
	}
}

int32 UGGMainMenuSceneWidget::GetMenuButtonCount() const
{
	if (MainMenuButtonContainerWidget)
	{
		return MainMenuButtonContainerWidget->GetChildrenCount();
	}

	UE_LOG(LogTemp, Warning, TEXT("MainMenuButtonContainerWidget is nullptr. Cannot return child count of container widget."));
	return 0;
}
