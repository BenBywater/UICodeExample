#include "VisibilityBindable.h"
#include "Components/Widget.h"

void FVisibilityBindable::operator=(ESlateVisibility inValue)
{
	currentValue = inValue;
	UpdateBidning();
}

void FVisibilityBindable::SetVisibilityBinding(UWidget* inWidget)
{
	widget = inWidget;
	UpdateBidning();
}

void FVisibilityBindable::UpdateBidning()
{
	if (widget)
	{
		widget->SetVisibility(currentValue);
	}
}