#pragma once

#include "CoreMinimal.h"
#include "GGViewModel.h"
#include "GGSceneViewModel.generated.h"

class UUISceneDataPayload;

UCLASS()
class UICODEEXAMPLE_API UGGSceneViewModel : public UGGViewModel
{
	GENERATED_BODY()

public:
	virtual void InitializeSceneViewModel(UUISceneDataPayload* scenePayload) {};

protected:
	template <typename T>
	T* GetPlayerController() const;
};

template <typename T>
T* UGGSceneViewModel::GetPlayerController() const
{
	return Cast<T>(GetWorld()->GetFirstPlayerController());
}
