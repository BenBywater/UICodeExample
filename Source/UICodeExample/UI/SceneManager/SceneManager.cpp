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
		UE_LOG(LogTemp, Warning, TEXT("Scene Manager nullptr"));
	}
}



void UGGSceneManager::OpenScene(SceneEnum scene, UUISceneDataPayload* sceneDataPayload)
{

	const UUIDataSettings* uiDataSettings = GetDefault<UUIDataSettings>();
	if (uiDataSettings && sceneManager)
	{
		UUISceneData* data = uiDataSettings->UISceneDataPath.LoadSynchronous();

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
}

void UGGSceneManager::CloseScene()
{
	if (sceneManager)
	{
		sceneManager->PopScene();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Scene Manager nullptr"));
	}
	
}

void UGGSceneManager::CloseAllScenes()
{
	if (sceneManager)
	{
		sceneManager->PopAllScenes();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Scene Manager nullptr"));
	}
}

UGGSceneWidget* UGGSceneManager::GetCurrentSceneWidget() const
{
	if (sceneManager)
	{
		return sceneManager->GetCurrentScene();
	}

	UE_LOG(LogTemp, Warning, TEXT("Scene Manager nullptr"));
	return nullptr;
}

int32 UGGSceneManager::GetSceneStackCount() const
{
	if (sceneManager)
	{
		return sceneManager->GetSceneStackCount();
	}

	UE_LOG(LogTemp, Warning, TEXT("Scene Manager nullptr"));
	return 0;
}
