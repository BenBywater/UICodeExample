#include "FloatBindable.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"


void UFloatBindable::operator=(float inValue)
{
	currentValue = inValue;
	UpdateBidning();
}

void UFloatBindable::SetFloatDataBinding(UTextBlock* inTextBlock)
{
	textBlock = inTextBlock;
	UpdateBidning();
}

void UFloatBindable::UpdateBidning()
{
	if (textBlock)
	{
		textBlock->SetText(FText::AsNumber(currentValue));
	}
}