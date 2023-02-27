#include "FloatBindable.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"


void FFloatBindable::operator=(float inValue)
{
	currentValue = inValue;
	UpdateBidning();
}

void FFloatBindable::SetFloatDataBinding(UTextBlock* inTextBlock)
{
	textBlock = inTextBlock;
	UpdateBidning();
}

void FFloatBindable::UpdateBidning()
{
	if (textBlock)
	{
		textBlock->SetText(FText::AsNumber(currentValue));
	}
}