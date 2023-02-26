#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Widgets/GGUserWidget.h"
#include "GGProgressBarWidget.generated.h"

class UImage;


UCLASS(Abstract)
class UICODEEXAMPLE_API UGGProgressBarWidget : public UGGUserWidget
{
	GENERATED_BODY()

public:
	void Tick(FGeometry MyGeometry, float InDeltaTime);

	void SetProgressBar(float inPercentage);

private:
	float currentPercentage = 1.f;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UImage* ProgressBar = nullptr;

};