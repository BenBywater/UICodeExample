#include "GGPlaceholderSceneWidget.h"
#include "GGButton.h"

bool UGGPlaceholderSceneWidget::Initialize()
{
	Super::Initialize();

	if (button)
	{
		button->OnClickedDelegate.AddDynamic(this, &ThisClass::OnButtonClicked);
	}

	return true;
}

void UGGPlaceholderSceneWidget::OnButtonClicked()
{
	ExitScene();
}