#include "GGMainMenuButtonContainerWidget.h"
#include "Components/VerticalBoxSlot.h"
#include "UICodeExample/UI/ViewModels/GGMainMenuButtonContainerViewModel.h"
#include "UICodeExample/UI/ViewModels/GGMenuButtonViewModel.h"
#include <Components/PanelSlot.h>

void UGGMainMenuButtonContainerWidget::SetDataContext(UGGViewModel* inViewModel)
{
	Super::SetDataContext(inViewModel);

	if (UGGMainMenuButtonContainerViewModel* ContainerViewModel = GetViewModel<UGGMainMenuButtonContainerViewModel>())
	{
		ConstructCollectionWidgets(ContainerViewModel->GetButtonViewModels());
	}
}

void UGGMainMenuButtonContainerWidget::OnChildAddedToPanel(UPanelSlot* childSlot)
{
	Super::OnChildAddedToPanel(childSlot);

	if (UVerticalBoxSlot* vBoxSlot = Cast<UVerticalBoxSlot>(childSlot))
	{
		vBoxSlot->SetPadding(childWidgetPadding);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not convert widget slot to vertical box slot"));
	}
}
