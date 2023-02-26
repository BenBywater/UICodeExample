#pragma once

#include "CoreMinimal.h"
#include "GGSceneViewModel.h"
#include "GGHUDSceneViewModel.generated.h"

class UUISceneDataPayload;
class UFloatBindable;
class UGGProgressBarViewModel;

UCLASS(BlueprintType)
class UICODEEXAMPLE_API UGGHUDSceneViewModel : public UGGSceneViewModel
{
	GENERATED_BODY()

public:
	void InitializeSceneViewModel(UUISceneDataPayload* scenePayload) override;

	void UpdatePlayerHealth(float newHealth);
	void UpdatePlayerAmmoCount(float newAmmo);

	UGGProgressBarViewModel* GetHealthBarViewModel() const;

private:
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UFloatBindable* ammoBinding;

	UPROPERTY()
	UGGProgressBarViewModel* healthBarViewModel = nullptr;
};
