#pragma once

#include "CoreMinimal.h"
#include "GGViewModel.h"
#include "UICodeExample/UI/Bindables/TextBindable.h"
#include "GGMenuButtonViewModel.generated.h"

struct FUIMenuButtonData;

UCLASS(BlueprintType)
class UICODEEXAMPLE_API UGGMenuButtonViewModel : public UGGViewModel
{
	GENERATED_BODY()

public:
	void InitializeViewModel(FUIMenuButtonData const& data);
	void OnButtonClicked();

private:
	UPROPERTY(BlueprintReadWrite, meta =(AllowPrivateAccess ="true"))
	FTextBindable nameTextBinding;

	FString buttonID;
};
