#include "GGTitleMenuSceneWidget.h"
#include "UICodeExample/UI/ViewModels/GGSceneViewModel.h"
#include "UICodeExample/UI/ViewModels/GGProgressBarViewModel.h"

void UGGTitleMenuSceneWidget::SetDataContext(UGGViewModel* inViewModel)
{
	Super::SetDataContext(inViewModel);

	if (IdleAnimation)
	{
		PlayAnimation(IdleAnimation);
	}
}

void UGGTitleMenuSceneWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UWorld* world = GetWorld();
	APlayerController* playerController = world->GetFirstPlayerController();
	if (playerController)
	{
		if (playerController->IsInputKeyDown(EKeys::AnyKey))
		{
			Exit();
		}
	}
}
