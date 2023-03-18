#include "GGButton.h"

bool UGGButton::Initialize()
{
	Super::Initialize();

	currentBitMask = static_cast<uint32>(EButtonStates::Default);
	return true;
}

bool UGGButton::IsBitMaskMatch(int32 Bitmask)
{
	return currentBitMask & Bitmask;
}

void UGGButton::EnableButton()
{
	bIsFocusable = true;
	ClearButtonBitMask(EButtonStates::Deactivated);
}

void UGGButton::DisableButton()
{
	bIsFocusable = false;
	SetButtonBitMask(EButtonStates::Deactivated);
}

FReply UGGButton::NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent)
{
	Super::NativeOnFocusReceived(InGeometry, InFocusEvent);
	SetButtonBitMask(EButtonStates::Focused);

	return FReply::Handled();
}

void UGGButton::NativeOnFocusLost(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnFocusLost(InFocusEvent);
	ClearButtonBitMask(EButtonStates::Focused);
}

void UGGButton::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	SetButtonBitMask(EButtonStates::Hovered);
}

void UGGButton::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	ClearButtonBitMask(EButtonStates::Hovered);
}

FReply UGGButton::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	Super::NativeOnKeyDown(InGeometry, InKeyEvent);
	SetButtonBitMask(EButtonStates::Selected);

	return FReply::Handled();
}

FReply UGGButton::NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	Super::NativeOnKeyUp(InGeometry, InKeyEvent);
	ClearButtonBitMask(EButtonStates::Selected);

	return FReply::Handled();
}

FReply UGGButton::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	SetButtonBitMask(EButtonStates::Selected);

	return FReply::Handled();
}

FReply UGGButton::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent);
	ClearButtonBitMask(EButtonStates::Selected);

	return FReply::Handled();
}

void UGGButton::SetButtonBitMask(EButtonStates bitmask)
{
	if (!IsBitMaskMatch(static_cast<uint32>(bitmask)))
	{
		currentBitMask |= StaticCast<int32>(bitmask);
		OnBitMaskStateChanged();
	}
}

void UGGButton::ClearButtonBitMask(EButtonStates bitmask)
{
	if (IsBitMaskMatch(static_cast<uint32>(bitmask)))
	{
		currentBitMask &= ~StaticCast<int32>(bitmask);
		OnBitMaskStateChanged();
	}
}