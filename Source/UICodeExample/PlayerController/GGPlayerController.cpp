#include "GGPlayerController.h"

void AGGPlayerController::PlayerTakeDamage()
{
	HealthResourceChangedDelegate.ExecuteIfBound(--playerHealth);
}

void AGGPlayerController::PlayerFireGun()
{
	AmmoResourceChangedDelegate.ExecuteIfBound(--playerAmmoCount);
}
