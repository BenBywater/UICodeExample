#include "GGCollectionPanelWidget.h"

UGGUserWidget* UGGCollectionPanelWidget::GetPooledWidget()
{
	if (widgetPool.Num() > 0)
	{
		widgetPool.Pop();
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

	if (childWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("childWidget is nullptr. Cannot set Data Context"));
		return;
	}

	childWidget->SetDataContext(childViewModel);
	OnChildAddedToPanel(panelWidget->AddChild(childWidget));
}
