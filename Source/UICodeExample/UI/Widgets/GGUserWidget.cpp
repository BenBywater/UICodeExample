#include "GGUserWidget.h"

void UGGUserWidget::SetDataContext(UGGViewModel* inViewModel)
{
	if (viewModel != inViewModel)
	{
		viewModel = inViewModel;
		OnDataContextChanged(viewModel);
	}
}
