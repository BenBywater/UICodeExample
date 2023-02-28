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
		UE_LOG(LogTemp, Warning, TEXT("newScene or SceneLayer are nullptr. Could not add newScene to viewport"));
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
				UE_LOG(LogTemp, Warning, TEXT("Could not get SceneLayers first child scene"));
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SceneLayer is nullptr, unable to exit scene"));
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
		UE_LOG(LogTemp, Warning, TEXT("SceneLayer is nullptr, Could not remove all scenes"));
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
	UE_LOG(LogTemp, Warning, TEXT("SceneLayer is nullptr, Could not get current scenes"));
	return nullptr;
}

int32 UGGSceneManagerWidget::GetSceneStackCount() const
{
	if (SceneLayer != nullptr)
	{
		return SceneLayer->GetChildrenCount();
	}

	UE_LOG(LogTemp, Warning, TEXT("SceneLayer is nullptr, Could not get scenes count"));
	return -1;
}

void UGGSceneManagerWidget::OnCloseAnimationFinished(UGGSceneWidget* closedScene)
{
	if (SceneLayer != nullptr)
	{
		if (!SceneLayer->RemoveChild(closedScene))
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not remove child from Scene Layer"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SceneLayer is nullptr, Could not remove child from Scene Layer"));
	}
}
