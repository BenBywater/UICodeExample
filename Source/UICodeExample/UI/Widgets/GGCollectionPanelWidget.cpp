#include "GGCollectionPanelWidget.h"

int32 UGGCollectionPanelWidget::GetChildrenCount() const
{
	if (panelWidget)
	{
		return panelWidget->GetChildrenCount();;
	}

	UE_LOG(LogTemp, Warning, TEXT("panelWidget is nullptr. Cannot return child count of panel widget."));
	return 0;
}

UGGUserWidget* UGGCollectionPanelWidget::GetPooledWidget()
{
	if (widgetPool.Num() > 0)
	{
		return widgetPool.Pop();
	}
	return nullptr;
}

void UGGCollectionPanelWidget::InitializeWidget(UGGUserWidget* childWidget, UGGViewModel* childViewModel)
{
	if (panelWidget == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Panel widget is nullptr. Cannot create child widgets"));
		return;
	}

	if (childWidget == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("childWidget is nullptr. Cannot set Data Context"));
		return;
	}

	childWidget->SetDataContext(childViewModel);
	OnChildAddedToPanel(panelWidget->AddChild(childWidget));
}
