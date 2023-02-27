#include "GGPlayerController.h"
#include <UICodeExample/DeveloperSettings/UIDataSettings.h>
#include <UICodeExample/UI/Data/UIMenuButtonData.h>
#include <UICodeExample/UI/Helpers/GGUIHelpers.h>
#include <UICodeExample/UI/Data/UIMainMenuScenePayload.h>

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
