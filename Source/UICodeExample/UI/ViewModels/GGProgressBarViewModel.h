#pragma once

#include "CoreMinimal.h"
#include "GGViewModel.h"
#include "UICodeExample/UI/Bindables/ProgressBarBindable.h"
#include "GGProgressBarViewModel.generated.h"

class UFloatBindable;

UCLASS(BlueprintType)
class UICODEEXAMPLE_API UGGProgressBarViewModel : public UGGViewModel
{
	GENERATED_BODY()

public:
	void UpdateProgressBar(float inValue);

private:
	UPROPERTY(BlueprintReadWrite, meta =(AllowPrivateAccess ="true"))
	FProgressBarBindable progressBarBinding;
};
