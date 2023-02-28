#include "SceneManagerWidget.h"
#include <Components/CanvasPanel.h>
#include <Components/CanvasPanelSlot.h>
#include "UICodeExample/UI/Widgets/GGSceneWidget.h"

void UGGSceneManagerWidget::PushScene(UGGSceneWidget* newScene)
{
	if (newScene != nullptr && SceneLayer != nullptr)
	{
		newScene->CloseAnimationFinishedDelegate.AddUObject(this, &ThisClass::OnCloseAnimationFinished);
		UCanvasPanelSlot* sceneSlot = SceneLayer->AddChildToCanvas(newScene);
		sceneSlot->SetAnchors(FAnchors(0, 0, 1, 1));
		sceneSlot->SetOffsets(FMargin(0, 0, 0, 0));
		newScene->EnterScene();
	}
	else
	{
		// Log Error
	}
	
}

void UGGSceneManagerWidget::PopScene()
{
	if (SceneLayer->GetChildrenCount() > 0)
	{
		if (UGGSceneWidget* scene = Cast<UGGSceneWidget>(SceneLayer->GetChildAt(0)))
		{
			scene->ExitScene();
		}
		else
		{
			// Log Error
		}
	}
}

void UGGSceneManagerWidget::PopAllScenes()
{
	SceneLayer->ClearChildren();
}

UGGSceneWidget* UGGSceneManagerWidget::GetCurrentScene() const
{
	if (SceneLayer->GetChildrenCount() > 0)
	{
		return Cast<UGGSceneWidget>(SceneLayer->GetChildAt(0));
	}
	return nullptr;
}

int32 UGGSceneManagerWidget::GetSceneStackCount() const
{
	return SceneStack.Num();
}

void UGGSceneManagerWidget::OnCloseAnimationFinished(UGGSceneWidget* closedScene)
{
	if (!SceneLayer->RemoveChild(closedScene))
	{
		//Log Error
	}
}
