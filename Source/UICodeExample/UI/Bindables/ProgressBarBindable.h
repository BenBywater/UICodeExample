#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ProgressBarBindable.generated.h"

class UGGProgressBarWidget;

USTRUCT(BlueprintType)
struct UICODEEXAMPLE_API FProgressBarBindable
{
	GENERATED_BODY()

public:
	void operator = (float inValue);

	void SetProgressBarBinding(UGGProgressBarWidget* inProgressBar);

private:
	void UpdateBidning();

	UPROPERTY()
	UGGProgressBarWidget* progressBar = nullptr;

	float currentValue = 0.f;
};