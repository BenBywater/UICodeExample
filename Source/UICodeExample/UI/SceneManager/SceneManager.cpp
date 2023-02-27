#include "SceneManager.h"
#include "SceneManagerWidget.h"
#include <Blueprint/GameViewportSubsystem.h>
#include <UICodeExample/DeveloperSettings/UIDataSettings.h>
#include "../Widgets/GGSceneWidget.h"
#include "../Data/UISceneDataPayload.h"
#include "../Data/UISceneData.h"
#include "../ViewModels/GGSceneViewModel.h"

void UGGSceneManager::InitialiseSceneManagerWidget(TSubclassOf<UGGSceneManagerWidget> const& sceneManagerWidgetClass)
{
	UWorld* world = GetWorld();
	sceneManager = CreateWidget<UGGSceneManagerWidget>(world, sceneManagerWidgetClass);
	if (sceneManager)
	{
		sceneManager->AddToViewport();
	}
	else
	{
		// Log Error
	}
}



void UGGSceneManager::OpenScene(SceneEnum scene, UUISceneDataPayload* sceneDataPayload)
{

	const UUIDataSettings* uiDataSettings = GetDefault<UUIDataSettings>();
	if (uiDataSettings && sceneManager)
	{
		UUISceneData* data = uiDataSettings->UUISceneDataPath.LoadSynchronous();

		if (FUISceneTypeData* sceneTypeData = data->sceneData.Find(scene))
		{
			TSubclassOf<class UGGSceneWidget> sceneWidgetClass = sceneTypeData->sceneWidgetType;
			TSubclassOf<class UGGSceneViewModel> sceneViewModelClass = sceneTypeData->sceneViewModelType;

			UGGSceneViewModel* newSceneViewModel = NewObject<UGGSceneViewModel>(GetWorld(), sceneViewModelClass);
			newSceneViewModel->InitializeSceneViewModel(sceneDataPayload);

			UGGSceneWidget* newScene = CreateWidget<UGGSceneWidget>(GetWorld(), sceneWidgetClass);
			newScene->SetDataContext(newSceneViewModel);
			sceneManager->PushScene(newScene);
		}
		
	}
	// Log Error
}

void UGGSceneManager::CloseScene()
{
	if (sceneManager)
	{
		sceneManager->PopScene();
	}
	// Log Error
}

void UGGSceneManager::CloseAllScenes()
{
	if (sceneManager)
	{
		sceneManager->PopAllScenes();
	}
	// Log Error
}

UGGSceneWidget* UGGSceneManager::GetCurrentSceneWidget() const
{
	if (sceneManager)
	{
		return sceneManager->GetCurrentScene();
	}
	// Log Error
	return nullptr;
}

int32 UGGSceneManager::GetSceneStackCount() const
{
	if (sceneManager)
	{
		return sceneManager->GetSceneStackCount();
	}

	return 0;
}
