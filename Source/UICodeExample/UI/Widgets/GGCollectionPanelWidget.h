#pragma once

#include "CoreMinimal.h"
#include "Components/PanelWidget.h"
#include "UICodeExample/UI/Widgets/GGUserWidget.h"
#include "GGCollectionPanelWidget.generated.h"

class UGGViewModel;

UCLASS(Abstract)
class UICODEEXAMPLE_API UGGCollectionPanelWidget : public UGGUserWidget
{
	GENERATED_BODY()
public:
	template <typename T>
	void ConstructCollectionWidgets(TArray<T*> arrayList);

	virtual void OnChildAddedToPanel(UPanelSlot* childSlot) {};

private:
	UGGUserWidget* GetPooledWidget();
	void InitializeWidget(UGGUserWidget* childWidget, UGGViewModel* childViewModel);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	UPanelWidget* panelWidget = nullptr;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UGGUserWidget> childWidgetClass = nullptr;

	UPROPERTY()
	TArray<UUserWidget*> widgetPool;
};

template <typename T>
void UGGCollectionPanelWidget::ConstructCollectionWidgets(TArray<T*> arrayList)
{
	if (panelWidget == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Panel widget is nullptr. Cannot create child widgets"));
		return;
	}

	if (panelWidget->HasAnyChildren() == false)
	{
		
		for (T* templatedViewModel : arrayList)
		{
			if (UGGViewModel* childViewModel = Cast<UGGViewModel>(templatedViewModel))
			{
				UGGUserWidget* childWidget = UGGCollectionPanelWidget::GetPooledWidget();

				// if we can get a cached widget from the widget pool
				if (childWidget != nullptr)
				{
					InitializeWidget(childWidget, childViewModel);
				}
				else
				{
					childWidget = CreateWidget<UGGUserWidget>(this, childWidgetClass);
					if (childWidget != nullptr)
					{
						InitializeWidget(childWidget, childViewModel);
					}
				}
			}
		}
	}
	else
	{
		
		// Check to see if any widgets need to be removed from panel
		int removalDiff = arrayList.Num() - panelWidget->GetChildrenCount();
		if (removalDiff > 0)
		{
			for (int32 Index = removalDiff; Index < panelWidget->GetChildrenCount(); ++Index)
			{
				panelWidget->RemoveChildAt(Index);
			}
		}


		for (int32 Index = 0; Index < arrayList.Num(); ++Index)
		{
			if (UGGViewModel* childViewModel = Cast<UGGViewModel>(arrayList[Index]))
			{
				// If Widget already exists in the panel
				UGGUserWidget* childWidget = Cast<UGGUserWidget>(panelWidget->GetChildAt(Index));
				if (childWidget != nullptr)
				{
					InitializeWidget(childWidget, childViewModel);
				}
				else
				{
					// if we can get a cached widget from the widget pool
					childWidget = GetPooledWidget();
					if (childWidget != nullptr)
					{
						InitializeWidget(childWidget, childViewModel);
					}
					// else we need to create a brand new object
					else 
					{
						childWidget = CreateWidget<UGGUserWidget>(this, childWidgetClass);
						if (childWidget)
						{
							InitializeWidget(childWidget, childViewModel);
						}
					}
				}
			}
		}
	}
}