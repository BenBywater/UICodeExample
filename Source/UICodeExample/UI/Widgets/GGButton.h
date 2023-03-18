#pragma once

#include "CoreMinimal.h"
#include <Blueprint/UserWidget.h>
#include "GGButton.generated.h"

class UTexture;

// Represent the states of the button through a enum bit mask
// This will allow up to know if multiple states are true at once
UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EButtonStates : uint8
{
	NONE	   = 0 UMETA(Hidden),
	Default	   = 1 << 0,
	Hovered	   = 1 << 1,
	Focused   = 1 << 2,
	Selected = 1 << 3,
	Deactivated = 1 << 4,
};
ENUM_CLASS_FLAGS(EButtonStates);

UCLASS(Abstract)
class UICODEEXAMPLE_API UGGButton : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	bool IsBitMaskMatch(UPARAM(meta = (Bitmask, BitmaskEnum = EButtonStates)) int32 bitmask);

	UFUNCTION(BlueprintImplementableEvent, meta = (BlueprintProtected))
	void OnBitMaskStateChanged();

	void EnableButton();
	void DisableButton();

protected:
	virtual FReply NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent);
	virtual void NativeOnFocusLost(const FFocusEvent& InFocusEvent);
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
private:
	void SetButtonBitMask(EButtonStates bitmask);
	void ClearButtonBitMask(EButtonStates bitmask);

	int32 currentBitMask = 0;
};