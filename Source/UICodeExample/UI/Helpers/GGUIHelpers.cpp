#include "GGUIHelpers.h"
#include <Engine/World.h>
#include <UICodeExample/Subsystems/UIGameSubsystem.h>
#include "UICodeExample/UI/SceneManager/SceneManager.h"
#include "../Data/UISceneDataPayload.h"

namespace UIHelpers
{
	void OpenScene(const UWorld* world, SceneEnum scene, UUISceneDataPayload* sceneDataPayload)
	{
		UGameInstance* GameInstance = world->GetGameInstance();

		UUIGameSubsystem* UISubsystem = GameInstance->GetSubsystem<UUIGameSubsystem>();
		UISubsystem->GetSceneManager()->OpenScene(scene, sceneDataPayload);
	}

	void CloseScene(const UWorld* world)
	{
		UGameInstance* GameInstance = world->GetGameInstance();

		UUIGameSubsystem* UISubsystem = GameInstance->GetSubsystem<UUIGameSubsystem>();
		UISubsystem->GetSceneManager()->CloseScene();
	}
}