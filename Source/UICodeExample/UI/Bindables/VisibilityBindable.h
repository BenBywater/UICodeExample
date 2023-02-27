#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "VisibilityBindable.generated.h"

class UWidget;

USTRUCT(BlueprintType)
struct UICODEEXAMPLE_API FVisibilityBindable
{
	GENERATED_BODY()

public:
	void operator = (ESlateVisibility inValue);

	void SetVisibilityBinding(UWidget* inWidget);

private:
	void UpdateBidning();

	UPROPERTY()
	UWidget* widget = nullptr;

	ESlateVisibility currentValue = ESlateVisibility::SelfHitTestInvisible;

};