#include "UIGameSubsystem.h"
#include <UICodeExample/UI/SceneManager/SceneManager.h>
#include <UICodeExample/DeveloperSettings/UIDataSettings.h>

// Sets default values
UUIGameSubsystem::UUIGameSubsystem()
{

}

void UUIGameSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	sceneManager = NewObject<UGGSceneManager>(this);
}

void UUIGameSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UUIGameSubsystem::CreateSceneManagerWidget()
{
	const UUIDataSettings* uiDataSettings = GetDefault<UUIDataSettings>();

	if (sceneManager && uiDataSettings)
	{
		sceneManager->InitialiseSceneManagerWidget(uiDataSettings->SceneManagerWidgetClass);
	}
}

UGGSceneManager* UUIGameSubsystem::GetSceneManager() const
{
	return sceneManager;
}
