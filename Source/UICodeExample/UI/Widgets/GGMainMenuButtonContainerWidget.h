#pragma once

#include "CoreMinimal.h"
#include "GGCollectionPanelWidget.h"
#include "GGMainMenuButtonContainerWidget.generated.h"

class UGGViewModel;

UCLASS(Abstract)
class UICODEEXAMPLE_API UGGMainMenuButtonContainerWidget : public UGGCollectionPanelWidget
{
	GENERATED_BODY()

public:
	virtual void SetDataContext(UGGViewModel* inViewModel) override;
};
