#include "GGPlaceholderSceneWidget.h"
#include "Components/Button.h"

bool UGGPlaceholderSceneWidget::Initialize()
{
	Super::Initialize();

	if (button)
	{
		button->OnClicked.AddDynamic(this, &ThisClass::OnButtonClicked);
	}

	return true;
}

void UGGPlaceholderSceneWidget::OnButtonClicked()
{
	ExitScene();
}
