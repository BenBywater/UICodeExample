#pragma once

#include "CoreMinimal.h"
#include <GameFramework/PlayerController.h>
#include "GGPlayerController.generated.h"

DECLARE_DELEGATE_OneParam(FOnResourceChanged, float)


UCLASS()
class UICODEEXAMPLE_API AGGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	FOnResourceChanged HealthResourceChangedDelegate;
	FOnResourceChanged AmmoResourceChangedDelegate;

	UFUNCTION(BlueprintCallable)
	void PlayerTakeDamage();

	UFUNCTION(BlueprintCallable)
	void PlayerFireGun();

	UFUNCTION(BlueprintCallable)
	void OpenTitleMenu();

	UFUNCTION(BlueprintCallable)
	void OpenMainMenu();

private:
	float playerHealth = 1.f;
	float playerAmmoCount = 10.f;
};