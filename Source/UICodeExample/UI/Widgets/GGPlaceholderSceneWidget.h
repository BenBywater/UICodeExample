#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Widgets/GGSceneWidget.h"
#include "GGPlaceholderSceneWidget.generated.h"

class UButton;

UCLASS(Abstract)
class UICODEEXAMPLE_API UGGPlaceholderSceneWidget : public UGGSceneWidget
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