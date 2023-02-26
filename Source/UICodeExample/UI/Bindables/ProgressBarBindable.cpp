#include "ProgressBarBindable.h"
#include "UICodeExample/UI/Widgets/GGProgressBarWidget.h"


void FProgressBarBindable::operator=(float inValue)
{
	currentValue = inValue;
	UpdateBidning();
}

void FProgressBarBindable::SetProgressBarBinding(UGGProgressBarWidget* inProgressBar)
{
	progressBar = inProgressBar;
	UpdateBidning();
}

void FProgressBarBindable::UpdateBidning()
{
	if (progressBar)
	{
		progressBar->SetProgressBar(currentValue);
	}
}