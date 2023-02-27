#include "TextBindable.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"


void FTextBindable::operator=(FText inValue)
{
	currentValue = inValue;
	UpdateBidning();
}

void FTextBindable::SetTextDataBinding(UTextBlock* inTextBlock)
{
	textBlock = inTextBlock;
	UpdateBidning();
}

void FTextBindable::UpdateBidning()
{
	if (textBlock)
	{
		textBlock->SetText(currentValue);
	}
}