#pragma once

#include "CoreMinimal.h"
#include "GGSceneViewModel.h"
#include "UICodeExample/UI/Bindables/FloatBindable.h"
#include "../Bindables/VisibilityBindable.h"
#include "GGHUDSceneViewModel.generated.h"

class UUISceneDataPayload;
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
	FFloatBindable ammoBinding;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FVisibilityBindable playerDiedBinding;

	UPROPERTY()
	UGGProgressBarViewModel* healthBarViewModel = nullptr;
};