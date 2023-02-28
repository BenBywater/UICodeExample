#include "GGHUDSceneViewModel.h"
#include "UICodeExample/UI/Bindables/FloatBindable.h"
#include "UICodeExample/UI/Data/UIHUDScenePayload.h"
#include "UICodeExample/UI/Data/UISceneDataPayload.h"
#include "UICodeExample/PlayerController/GGPlayerController.h"
#include "GGProgressBarViewModel.h"


void UGGHUDSceneViewModel::InitializeSceneViewModel(UUISceneDataPayload* scenePayload)
{
	Super::InitializeSceneViewModel(scenePayload);

	UUIHUDScenePayload* hudPayload = Cast<UUIHUDScenePayload>(scenePayload);

	if (hudPayload == nullptr)
	{
		// Log Error
		return;
	}

	if (healthBarViewModel == nullptr)
	{
		healthBarViewModel = NewObject<UGGProgressBarViewModel>(this);
	}

	ammoBinding = hudPayload->AmmoCount;

	if (AGGPlayerController* playerController = GetPlayerController<AGGPlayerController>())
	{
		playerController->HealthResourceChangedDelegate.BindUObject(this, &ThisClass::UpdatePlayerHealth);
		playerController->AmmoResourceChangedDelegate.BindUObject(this, &ThisClass::UpdatePlayerAmmoCount);
	}

	if (healthBarViewModel)
	{
		healthBarViewModel->UpdateProgressBar(hudPayload->Health);
	}

	playerDiedBinding = ESlateVisibility::Collapsed;
}

void UGGHUDSceneViewModel::UpdatePlayerHealth(float newHealth)
{
	if (healthBarViewModel != nullptr)
	{
		healthBarViewModel->UpdateProgressBar(newHealth);
	}

	if (newHealth <= 0.f)
	{
		playerDiedBinding = ESlateVisibility::SelfHitTestInvisible;
	}
}

void UGGHUDSceneViewModel::UpdatePlayerAmmoCount(float newAmmo)
{
	ammoBinding = newAmmo;
}

UGGProgressBarViewModel* UGGHUDSceneViewModel::GetHealthBarViewModel() const
{
	return healthBarViewModel;
}
