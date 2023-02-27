#include "GGSceneWidget.h"
#include "Animation/WidgetAnimation.h"

bool UGGSceneWidget::Initialize()
{
	bool parentInit = Super::Initialize();

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();

	if (playerController != nullptr)
	{
		if (DefaultInputMode == SceneInputModeEnum::UIOnly)
		{
			FInputModeUIOnly inputMode;
			inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
			playerController->SetInputMode(FInputModeUIOnly());
			playerController->SetShowMouseCursor(true);
		}
		else if (DefaultInputMode == SceneInputModeEnum::GameAndUI)
		{
			playerController->SetInputMode(FInputModeGameAndUI());
			playerController->SetShowMouseCursor(true);
		}
		else if (DefaultInputMode == SceneInputModeEnum::GameOnly)
		{
			playerController->SetInputMode(FInputModeGameOnly());
			playerController->SetShowMouseCursor(false);
		}
	}

	return parentInit;
}


void UGGSceneWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	Super::OnAnimationFinished_Implementation(Animation);
	
	if (EnterSceneAnimation == Animation)
	{
		EnterAnimationFinishedDelegate.Broadcast(this);
	}
	else if (ExitSceneAnimation == Animation)
	{
		CloseAnimationFinishedDelegate.Broadcast(this);
	}
}

void UGGSceneWidget::EnterScene()
{
	if (EnterSceneAnimation != nullptr)
	{
		PlayAnimation(EnterSceneAnimation);

		if (DefaultFocusWidget != nullptr)
		{
			DefaultFocusWidget->SetKeyboardFocus();
		}
	}
	else
	{
		EnterAnimationFinishedDelegate.Broadcast(this);
	}
}

void UGGSceneWidget::ExitScene()
{
	if (ExitSceneAnimation != nullptr)
	{
		PlayAnimation(ExitSceneAnimation);
	}
	else
	{
		CloseAnimationFinishedDelegate.Broadcast(this);
	}
}