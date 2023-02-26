#include "GGProgressBarViewModel.h"
#include "UICodeExample/UI/Bindables/FloatBindable.h"

void UGGProgressBarViewModel::UpdateProgressBar(float inValue)
{
	progressBarBinding = inValue;
}
