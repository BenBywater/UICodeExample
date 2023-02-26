#include "SceneManagerWidget.h"
#include <Components/CanvasPanel.h>
#include <Components/CanvasPanelSlot.h>
#include "UICodeExample/UI/Widgets/GGSceneWidget.h"

void UGGSceneManagerWidget::PushScene(UGGSceneWidget* newScene)
{
	if (newScene != nullptr && SceneLayer != nullptr)
	{
		newScene->CloseAnimationFinishedDelegate.BindUObject(this, &ThisClass::OnCloseAnimationFinished);
		UCanvasPanelSlot* sceneSlot = SceneLayer->AddChildToCanvas(newScene);
		sceneSlot->SetAnchors(FAnchors(0, 0, 1, 1));
		sceneSlot->SetOffsets(FMargin(0, 0, 0, 0));
		SceneStack.Push(newScene);

		newScene->EnterScene();
	}
	else
	{
		// Log Error
	}
	
}

void UGGSceneManagerWidget::PopScene()
{

	if (UGGSceneWidget* scene = SceneStack.Top())
	{
		scene->ExitScene();
	}
	else
	{
		// Log Error
	}
}

void UGGSceneManagerWidget::OnCloseAnimationFinished(UGGSceneWidget* closedScene)
{
	SceneLayer->RemoveChild(closedScene);
	SceneStack.Pop();
}