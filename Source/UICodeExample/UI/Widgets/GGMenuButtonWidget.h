#pragma once

#include "CoreMinimal.h"
#include "GGUserWidget.h"
#include "GGMenuButtonWidget.generated.h"

class UGGMenuButtonWidget;
class UButton;

UCLASS(Abstract)
class UICODEEXAMPLE_API UGGMenuButtonWidget : public UGGUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

private:
	UFUNCTION()
	void OnButtonClicked();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	UButton* button = nullptr;
};
