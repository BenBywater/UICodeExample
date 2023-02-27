#include "GGMenuButtonWidget.h"
#include "Components/Button.h"
#include "UICodeExample/UI/ViewModels/GGMenuButtonViewModel.h"


bool UGGMenuButtonWidget::Initialize()
{
	Super::Initialize();

	if (button)
	{
		button->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonClicked);
	}

	return true;
}


void UGGMenuButtonWidget::OnButtonClicked()
{
	if (UGGMenuButtonViewModel* thisViewModel = GetViewModel<UGGMenuButtonViewModel>())
	{
		thisViewModel->OnButtonClicked();
	}
}