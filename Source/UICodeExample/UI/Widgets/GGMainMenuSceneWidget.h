#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Widgets/GGSceneWidget.h"
#include "GGMainMenuSceneWidget.generated.h"

class UGGMainMenuButtonContainerWidget;
class UGGMenuButtonViewModel;

UCLASS(Abstract)
class UICODEEXAMPLE_API UGGMainMenuSceneWidget : public UGGSceneWidget
{
	GENERATED_BODY()
public:
	virtual void SetDataContext(UGGViewModel* inViewModel) override;
	void UpdateButtonContainerWidget(TArray<UGGMenuButtonViewModel*> viewModels);
	int32 GetMenuButtonCount() const;
private:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UGGMainMenuButtonContainerWidget* MainMenuButtonContainerWidget = nullptr;
};