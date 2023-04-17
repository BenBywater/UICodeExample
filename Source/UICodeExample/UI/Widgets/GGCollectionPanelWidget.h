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
	void ConstructCollectionWidgets(TArray<T*> const& arrayList);

	virtual void OnChildAddedToPanel(UPanelSlot* childSlot) {};

	int32 GetChildrenCount() const;

private:
	UGGUserWidget* GetPooledWidget();
	void InitializeWidget(UGGUserWidget* childWidget, UGGViewModel* childViewModel);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	UPanelWidget* panelWidget = nullptr;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UGGUserWidget> childWidgetClass = nullptr;

	UPROPERTY()
	TArray<UGGUserWidget*> widgetPool;
};

template <typename T>
void UGGCollectionPanelWidget::ConstructCollectionWidgets(TArray<T*> const & arrayList)
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
		int removalDiff = panelWidget->GetChildrenCount() - arrayList.Num();
		if (removalDiff > 0)
		{
			for (int32 Index = 0; Index < removalDiff; ++Index)
			{
				widgetPool.Add(Cast<UGGUserWidget>(panelWidget->GetChildAt(Index)));
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