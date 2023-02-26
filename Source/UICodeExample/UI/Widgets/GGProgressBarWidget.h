#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Widgets/GGUserWidget.h"
#include <Layout/Geometry.h>
#include "GGProgressBarWidget.generated.h"

class UImage;


UCLASS(Abstract)
class UICODEEXAMPLE_API UGGProgressBarWidget : public UGGUserWidget
{
	GENERATED_BODY()

public:
	void Tick(FGeometry MyGeometry, float InDeltaTime);

	void SetProgressBar(float inPercentage);

	UFUNCTION(BlueprintCallable)
	void BlueprintTick(float InDeltaTime);

private:
	float currentPercentage = 1.f;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UImage* progressBar = nullptr;

	UPROPERTY(EditAnywhere, meta = (ClampMin = 1, ClampMax = 3, UIMin = 1, UIMax = 3))
	float lerpMultiplyer = 1.f;

};