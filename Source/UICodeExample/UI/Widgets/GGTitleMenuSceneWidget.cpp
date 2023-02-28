#include "GGTitleMenuSceneWidget.h"
#include "UICodeExample/PlayerController/GGPlayerController.h"
#include "UICodeExample/UI/ViewModels/GGSceneViewModel.h"

void UGGTitleMenuSceneWidget::SetDataContext(UGGViewModel* inViewModel)
{
	Super::SetDataContext(inViewModel);

	if (IdleAnimation)
	{
		PlayAnimation(IdleAnimation);
	}
}

FReply UGGTitleMenuSceneWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	Super::NativeOnKeyDown(InGeometry, InKeyEvent);

	ExitScene();

	UWorld* world = GetWorld();
	AGGPlayerController* playerController = Cast<AGGPlayerController>(world->GetFirstPlayerController());
	if (playerController)
	{
		playerController->OpenMainMenu();
	}
	return FReply::Handled();
}

void UGGTitleMenuSceneWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	Super::OnAnimationFinished_Implementation(Animation);

	if (IdleAnimation == Animation)
	{
		PlayAnimation(IdleAnimation);
	}
}
