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
	if (SceneLayer != nullptr)
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
	else
	{
		// Log Error
	}
}

void UGGSceneManagerWidget::PopAllScenes()
{
	if (SceneLayer != nullptr)
	{
		SceneLayer->ClearChildren();
	}
	else
	{
		// log error
	}

}

UGGSceneWidget* UGGSceneManagerWidget::GetCurrentScene() const
{
	if (SceneLayer != nullptr)
	{
		if (SceneLayer->GetChildrenCount() > 0)
		{
			return Cast<UGGSceneWidget>(SceneLayer->GetChildAt(0));
		}
	}
	// lorg error
	return nullptr;
}

int32 UGGSceneManagerWidget::GetSceneStackCount() const
{
	if (SceneLayer != nullptr)
	{
		return SceneLayer->GetChildrenCount();
	}

	// log error
	return -1;
}

void UGGSceneManagerWidget::OnCloseAnimationFinished(UGGSceneWidget* closedScene)
{
	if (SceneLayer != nullptr)
	{
		if (!SceneLayer->RemoveChild(closedScene))
		{
			//Log Error
		}
	}
	else
	{
		// log error
	}
}
