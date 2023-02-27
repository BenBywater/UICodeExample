#pragma once

#include "CoreMinimal.h"
#include "TextBindable.generated.h"

class UTextBlock;

USTRUCT(BlueprintType)
struct UICODEEXAMPLE_API FTextBindable
{
	GENERATED_BODY()

public:
	void operator = (FText inValue);

	void SetTextDataBinding(UTextBlock* inTextBlock);

private:
	void UpdateBidning();

	UPROPERTY()
	UTextBlock* textBlock = nullptr;

	FText currentValue;
};