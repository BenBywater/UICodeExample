#pragma once

#include "CoreMinimal.h"
#include <Engine/DataAsset.h>
#include "UIButtonStylesData.generated.h"

USTRUCT(BlueprintType)
struct FUIButtonStyle
{
    GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Brushes")
	FSlateBrush DefaultBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Brushes")
	FSlateBrush HoveredBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Brushes")
	FSlateBrush FocusedBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Brushes")
	FSlateBrush SelectedBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Brushes")
	FSlateBrush DeactiveBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Layout")
	FMargin ButtonPadding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Button Style|Layout")
	FMargin ContentPadding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Button Style|Layout")
	TEnumAsByte<EHorizontalAlignment> ContentHorizontalAlignment = EHorizontalAlignment::HAlign_Fill;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Button Style|Layout")
	TEnumAsByte <EVerticalAlignment> ContentVerticalAlignment = EVerticalAlignment::VAlign_Fill;
};


UCLASS(BlueprintType)
class UICODEEXAMPLE_API UUIButtonStylesData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FUIButtonStyle> buttonStyles;

};
