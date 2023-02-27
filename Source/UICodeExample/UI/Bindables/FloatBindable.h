#pragma once

#include "CoreMinimal.h"
#include "FloatBindable.generated.h"

class UTextBlock;

USTRUCT(BlueprintType)
struct UICODEEXAMPLE_API FFloatBindable
{
	GENERATED_BODY()

public:
	void operator = (float inValue);

	void SetFloatDataBinding(UTextBlock* inTextBlock);

private:
	void UpdateBidning();

	UPROPERTY()
	UTextBlock* textBlock = nullptr;

	float currentValue = 0.f;
};