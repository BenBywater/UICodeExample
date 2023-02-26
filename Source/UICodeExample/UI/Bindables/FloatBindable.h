#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FloatBindable.generated.h"

class UTextBlock;

UCLASS(BlueprintType)
class UICODEEXAMPLE_API UFloatBindable : public UObject
{
	GENERATED_BODY()

public:
	UFloatBindable() = default;

	void operator = (float inValue);

	UFUNCTION(BlueprintCallable)
	void SetFloatDataBinding(UTextBlock* inTextBlock);

private:
	void UpdateBidning();

	UPROPERTY()
	UTextBlock* textBlock = nullptr;

	float currentValue = 0.f;
};