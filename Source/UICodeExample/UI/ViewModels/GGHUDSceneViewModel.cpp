#include "GGHUDSceneViewModel.h"
#include "UICodeExample/UI/Bindables/FloatBindable.h"
#include "UICodeExample/UI/Data/UIHUDScenePayload.h"
#include "UICodeExample/UI/Data/UISceneDataPayload.h"
#include "UICodeExample/PlayerController/GGPlayerController.h"
#include "GGProgressBarViewModel.h"


void UGGHUDSceneViewModel::InitializeSceneViewModel(UUISceneDataPayload* scenePayload)
{
	Super::InitializeSceneViewModel(scenePayload);

	if (UUIHUDScenePayload* hudPayload = Cast<UUIHUDScenePayload>(scenePayload))
	{
		
		// Here could be a good opportunity to cache a TWeakPtr of a game play object.
		// For example, if we wanted to show UI of a pawn in the world, we would want
		// to own a weak pointer of that object as to not have ownership of it for when
		// its despawned from the world

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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could cast payload to HUDScenePayload"));
	}
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
