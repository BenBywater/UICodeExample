#include "GGPlayerController.h"

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
