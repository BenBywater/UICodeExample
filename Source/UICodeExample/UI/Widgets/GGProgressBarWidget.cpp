#include "GGProgressBarWidget.h"
#include <Components/Image.h>
#include <Materials/MaterialInstanceDynamic.h>
#include "../ViewModels/GGViewModel.h"

#pragma optimize("", off)
void UGGProgressBarWidget::Tick(FGeometry MyGeometry, float InDeltaTime)
{
	Super::Tick(MyGeometry, InDeltaTime);

	if (UMaterialInstanceDynamic* material = ProgressBar->GetDynamicMaterial())
	{
		float currentSecondBar = 0.f;

		FName ParameterName = "SecondBar";
		material->GetScalarParameterValue(ParameterName, currentSecondBar);
		float healthDiff = currentSecondBar - currentPercentage;
		if (healthDiff > 0)
		{
			float lerpVal = FMath::Lerp(currentSecondBar, currentPercentage, 0.01f);
			material->SetScalarParameterValue("SecondBar", lerpVal);
		}
	}
}
#pragma optimize("", on)

void UGGProgressBarWidget::SetProgressBar(float inPercentage)
{
	currentPercentage = inPercentage;
	if (UMaterialInstanceDynamic* material = ProgressBar->GetDynamicMaterial())
	{
		material->SetScalarParameterValue("FirstBar", currentPercentage);
	}
}
