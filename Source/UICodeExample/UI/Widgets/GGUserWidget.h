#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GGUserWidget.generated.h"

class UGGViewModel;

UCLASS(Abstract)
class UICODEEXAMPLE_API UGGUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void SetDataContext(UGGViewModel* inViewModel);
protected:
	UFUNCTION(BlueprintImplementableEvent, meta = (BlueprintProtected))
	void OnDataContextChanged(UGGViewModel* currentViewModel);

	template <typename T>
	T* GetViewModel() const;

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UGGViewModel* viewModel = nullptr;
};

template <typename T>
T* UGGUserWidget::GetViewModel() const
{
	return Cast<T>(viewModel);
}