#include "GGUIHelpers.h"
#include <Engine/World.h>
#include "UICodeExample/Subsystems/UIGameSubsystem.h"
#include "UICodeExample/UI/SceneManager/SceneManager.h"
#include "UICodeExample/UI/Data/UISceneDataPayload.h"
#include "UICodeExample/UI/Widgets/GGSceneWidget.h"

namespace UIHelpers
{
	void OpenScene(const UWorld* world, SceneEnum scene, UUISceneDataPayload* sceneDataPayload)
	{
		if (UGameInstance* GameInstance = world->GetGameInstance())
		{
			if (UUIGameSubsystem* UISubsystem = GameInstance->GetSubsystem<UUIGameSubsystem>())
			{
				if (UGGSceneManager* sceneManager = UISubsystem->GetSceneManager())
				{
					sceneManager->OpenScene(scene, sceneDataPayload);
				}
			}
		}

		// Log Error
	}

	void CloseScene(const UWorld* world)
	{
		if (UGameInstance* GameInstance = world->GetGameInstance())
		{
			if (UUIGameSubsystem* UISubsystem = GameInstance->GetSubsystem<UUIGameSubsystem>())
			{
				if (UGGSceneManager* sceneManager = UISubsystem->GetSceneManager())
				{
					sceneManager->CloseScene();
				}
			}
		}
		// Log Error
	}

	void CloseAllScenes(const UWorld* world)
	{
		if (UGameInstance* GameInstance = world->GetGameInstance())
		{
			if (UUIGameSubsystem* UISubsystem = GameInstance->GetSubsystem<UUIGameSubsystem>())
			{
				if (UGGSceneManager* sceneManager = UISubsystem->GetSceneManager())
				{
					sceneManager->CloseAllScenes();
				}
			}
		}
		//Log Error
	}

	UGGSceneWidget* GetCurrentSceneWidget(const UWorld* world)
	{
		if (UGameInstance* GameInstance = world->GetGameInstance())
		{
			if (UUIGameSubsystem* UISubsystem = GameInstance->GetSubsystem<UUIGameSubsystem>())
			{
				if (UGGSceneManager* sceneManager = UISubsystem->GetSceneManager())
				{
					return sceneManager->GetCurrentSceneWidget();
				}
			}
		}

		// Log Error
		return nullptr;
	}

	int32 GetSceneStackCount(const UWorld* world)
	{
		if (UGameInstance* GameInstance = world->GetGameInstance())
		{
			if (UUIGameSubsystem* UISubsystem = GameInstance->GetSubsystem<UUIGameSubsystem>())
			{
				if (UGGSceneManager* sceneManager = UISubsystem->GetSceneManager())
				{
					return sceneManager->GetSceneStackCount();
				}
			}
		}

		// Log Error
		return -1 ;
	}

}