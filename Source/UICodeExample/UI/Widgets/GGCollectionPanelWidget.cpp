#include "GGCollectionPanelWidget.h"

UGGUserWidget* UGGCollectionPanelWidget::GetPooledWidget()
{
	if (widgetPool.Num() > 0)
	{
		widgetPool.Pop();
	}
	return nullptr;
}