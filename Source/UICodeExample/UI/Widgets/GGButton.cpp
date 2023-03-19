#include "GGButton.h"
#include "UICodeExample/UI/Data/UIButtonStylesData.h"
#include <UICodeExample/DeveloperSettings/UIDataSettings.h>
#include <Components/Image.h>
#include <Components/PanelSlot.h>
#include <Components/Overlay.h>
#include <Components/OverlaySlot.h>

bool UGGButton::Initialize()
{
	Super::Initialize();

	currentBitMask = static_cast<uint32>(EButtonStates::Default);
	return true;
}

void UGGButton::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	UpdateButtonStyle();
	SetButtonTextures();
	SetButtonLayout();
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

	OnFocusedDelegate.Broadcast();

	return FReply::Handled();
}

void UGGButton::NativeOnFocusLost(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnFocusLost(InFocusEvent);
	ClearButtonBitMask(EButtonStates::Focused);

	OnLostFocusedDelegate.Broadcast();
}

void UGGButton::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	SetButtonBitMask(EButtonStates::Hovered);

	OnHoveredDelegate.Broadcast();
}

void UGGButton::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	ClearButtonBitMask(EButtonStates::Selected);
	ClearButtonBitMask(EButtonStates::Hovered);

	OnHoveredDelegate.Broadcast();
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

	OnClickedDelegate.Broadcast();

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

	OnClickedDelegate.Broadcast();

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

void UGGButton::SetButtonTextures()
{
	if (currentButtonStyle)
	{
		if (defaultTexture)
		{
			defaultTexture->SetBrush(currentButtonStyle->DefaultBrush);
		}

		if (hoveredTexture)
		{
			hoveredTexture->SetBrush(currentButtonStyle->HoveredBrush);
		}

		if (focusedTexture)
		{
			focusedTexture->SetBrush(currentButtonStyle->FocusedBrush);
		}

		if (selectedTexture)
		{
			selectedTexture->SetBrush(currentButtonStyle->SelectedBrush);
		}

		if (selectedTexture)
		{
			selectedTexture->SetBrush(currentButtonStyle->SelectedBrush);
		}
	}
	
}

void UGGButton::SetButtonLayout()
{
	if (currentButtonStyle)
	{
		if (UOverlaySlot* contentSlot = Cast<UOverlaySlot>(contentOverlay->Slot))
		{
			contentSlot->SetPadding(currentButtonStyle->ContentPadding);
			contentSlot->SetHorizontalAlignment(currentButtonStyle->ContentHorizontalAlignment);
			contentSlot->SetVerticalAlignment(currentButtonStyle->ContentVerticalAlignment);
		}
	}
}

void UGGButton::UpdateButtonStyle()
{
	const UUIDataSettings* uiDataSettings = GetDefault<UUIDataSettings>();
	if (uiDataSettings)
	{
		if (UUIButtonStylesData* data = uiDataSettings->UIButtonStylesData.LoadSynchronous())
		{
			if (data->buttonStyles.Contains(ButtonStyleName))
			{
				currentButtonStyle = data->buttonStyles.Find(ButtonStyleName);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Could not find button style in UUIButtonStylesData"));
			}
		}
	}
}
