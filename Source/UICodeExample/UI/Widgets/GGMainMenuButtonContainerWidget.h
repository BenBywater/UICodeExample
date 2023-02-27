#pragma once

#include "CoreMinimal.h"
#include "GGCollectionPanelWidget.h"
#include <Layout/Margin.h>
#include "GGMainMenuButtonContainerWidget.generated.h"

class UGGViewModel;
class UPanelSlot;

UCLASS(Abstract)
class UICODEEXAMPLE_API UGGMainMenuButtonContainerWidget : public UGGCollectionPanelWidget
{
	GENERATED_BODY()

public:
	virtual void SetDataContext(UGGViewModel* inViewModel) override;

	virtual void OnChildAddedToPanel(UPanelSlot* childSlot)	override;

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess))
	FVector4d childWidgetPadding;
};
