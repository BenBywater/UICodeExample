#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Widgets/GGSceneWidget.h"
#include "GGPlaceholderSceneWidget.generated.h"

class UGGButton;

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
	UGGButton* button = nullptr;

};