#pragma once

#include "CoreMinimal.h"
#include <Blueprint/UserWidget.h>
#include "GGButton.generated.h"

class UTexture;
struct FUIButtonStyle;
class UImage;
class UOverlay;

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

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonClickedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonFocusedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonHoverDelegate);

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

	UPROPERTY(BlueprintAssignable, Category="Button|Delegate")
	FOnButtonClickedDelegate OnClickedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Button|Delegate")
	FOnButtonFocusedDelegate OnFocusedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Button|Delegate")
	FOnButtonFocusedDelegate OnLostFocusedDelegate;

	UPROPERTY( BlueprintAssignable, Category = "Button|Delegate" )
	FOnButtonHoverDelegate OnHoveredDelegate;

	UPROPERTY( BlueprintAssignable, Category = "Button|Delegate" )
	FOnButtonHoverDelegate OnUnhoveredDelegate;

protected:
	virtual void SynchronizeProperties() override;

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

	void SetButtonTextures();
	void SetButtonLayout();
	void UpdateButtonStyle();

	int32 currentBitMask = 0;

	FUIButtonStyle* currentButtonStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Button Style|Layout", meta = (AllowprivateAccess = "true"))
	FString ButtonStyleName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UImage* defaultTexture = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UImage* hoveredTexture = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UImage* focusedTexture = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UImage* selectedTexture = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UImage* deactiveTexture = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UOverlay* contentOverlay = nullptr;
};