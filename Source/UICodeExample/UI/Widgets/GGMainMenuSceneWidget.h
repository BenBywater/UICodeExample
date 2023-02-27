#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Widgets/GGSceneWidget.h"
#include "GGMainMenuSceneWidget.generated.h"

class UGGMainMenuButtonContainerWidget;

UCLASS(Abstract)
class UICODEEXAMPLE_API UGGMainMenuSceneWidget : public UGGSceneWidget
{
	GENERATED_BODY()
public:
	virtual void SetDataContext(UGGViewModel* inViewModel) override;

private:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UGGMainMenuButtonContainerWidget* MainMenuButtonContainerWidget = nullptr;
};