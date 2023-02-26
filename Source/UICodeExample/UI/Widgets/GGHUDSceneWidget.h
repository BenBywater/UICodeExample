#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Widgets/GGSceneWidget.h"
#include "GGHUDSceneWidget.generated.h"

class UGGProgressBarWidget;


UCLASS(Abstract)
class UICODEEXAMPLE_API UGGHUDSceneWidget : public UGGSceneWidget
{
	GENERATED_BODY()
public:
	virtual void SetDataContext(UGGViewModel* inViewModel) override;

private:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UGGProgressBarWidget* healthBarWidget = nullptr;
};