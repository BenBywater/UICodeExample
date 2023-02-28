#include "GGPlayerController.h"
#include <UICodeExample/DeveloperSettings/UIDataSettings.h>
#include <UICodeExample/UI/Data/UIMenuButtonData.h>
#include <UICodeExample/UI/Helpers/GGUIHelpers.h>
#include <UICodeExample/UI/Data/UIMainMenuScenePayload.h>
#include <UICodeExample/UI/Data/UIHUDScenePayload.h>
#include <UICodeExample/UI/Data/UISceneDataPayload.h>
#include <Kismet/KismetSystemLibrary.h>

void AGGPlayerController::PlayerTakeDamage()
{
	playerHealth -= (playerHealth > 0) ? 0.1f : 0;
	HealthResourceChangedDelegate.ExecuteIfBound(playerHealth);
}

void AGGPlayerController::PlayerFireGun()
{
	playerAmmoCount -= (playerAmmoCount > 0) ? 1.f : 0;
	AmmoResourceChangedDelegate.ExecuteIfBound(playerAmmoCount);
}

void AGGPlayerController::OpenTitleMenu()
{
	UWorld* world = GetWorld();
	UUISceneDataPayload* payload = NewObject<UUISceneDataPayload>();
	if (world && payload)
	{
		UIHelpers::OpenScene(world, SceneEnum::Title, payload);
	}
}

void AGGPlayerController::OpenMainMenu()
{
	if (const UUIDataSettings* uiDataSettings = GetDefault<UUIDataSettings>())
	{
		UUIMainMenuButtonData* data = uiDataSettings->UIMenuButtonData.LoadSynchronous();
		UUIMainMenuScenePayload* payload = NewObject<UUIMainMenuScenePayload>();
		if (payload && data)
		{
			payload->menuButtonData = data->menuButtonData;
			UIHelpers::OpenScene(GetWorld(), SceneEnum::MainMenu, payload);
		}
		// Log Error
	}
	// Log Error
}

void AGGPlayerController::OnMainMenuCommand(FString command)
{
	if (command == "EnterMap")
	{
		UWorld* world = GetWorld();

		// Remove all scenes as we are leaving the front end
		UIHelpers::CloseAllScenes(world);

		UUIHUDScenePayload* hudPayload = NewObject<UUIHUDScenePayload>();
		if (hudPayload)
		{
			hudPayload->Health = 1.f;
			hudPayload->AmmoCount = 10.f;
			UIHelpers::OpenScene(world, SceneEnum::HUD, hudPayload);
		}
	}
	else if (command == "OpenSettings")
	{
		UWorld* world = GetWorld();
		UUISceneDataPayload* payload = NewObject<UUISceneDataPayload>();
		if (world && payload)
		{
			UIHelpers::OpenScene(world, SceneEnum::Placeholder, payload);
		}
	}
	else if (command == "CloseGame")
	{
		UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
	}
}