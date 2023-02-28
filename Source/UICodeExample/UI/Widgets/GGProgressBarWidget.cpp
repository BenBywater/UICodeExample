#include "GGProgressBarWidget.h"
#include <Components/Image.h>
#include <Materials/MaterialInstanceDynamic.h>
#include "../ViewModels/GGViewModel.h"

void UGGProgressBarWidget::SetProgressBar(float inPercentage)
{
	currentPercentage = inPercentage;
	if (UMaterialInstanceDynamic* material = progressBar->GetDynamicMaterial())
	{
		material->SetScalarParameterValue("FirstBar", currentPercentage);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not get dynamic material from progress bar"));
	}
}

void UGGProgressBarWidget::BlueprintTick(float InDeltaTime)
{
	if (UMaterialInstanceDynamic* material = progressBar->GetDynamicMaterial())
	{
		float currentSecondBar = 0.f;

		FName ParameterName = "SecondBar";
		material->GetScalarParameterValue(ParameterName, currentSecondBar);
		float healthDiff = currentSecondBar - currentPercentage;
		if (healthDiff > 0)
		{
			float lerpVal = FMath::Lerp(currentSecondBar, currentPercentage, InDeltaTime * lerpMultiplyer);
			material->SetScalarParameterValue("SecondBar", lerpVal);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not get dynamic material from progress bar"));
	}
}

float UGGProgressBarWidget::GetProgressValue() const
{
	return currentPercentage;
}
