#include "GGMainMenuButtonContainerWidget.h"
#include "UICodeExample/UI/ViewModels/GGMainMenuButtonContainerViewModel.h"
#include "UICodeExample/UI/ViewModels/GGMenuButtonViewModel.h"

void UGGMainMenuButtonContainerWidget::SetDataContext(UGGViewModel* inViewModel)
{
	Super::SetDataContext(inViewModel);

	if (UGGMainMenuButtonContainerViewModel* ContainerViewModel = GetViewModel<UGGMainMenuButtonContainerViewModel>())
	{
		ConstructCollectionWidgets(ContainerViewModel->GetButtonViewModels());
	}
}
