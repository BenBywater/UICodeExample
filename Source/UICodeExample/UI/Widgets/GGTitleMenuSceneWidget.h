#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Widgets/GGSceneWidget.h"
#include "GGTitleMenuSceneWidget.generated.h"

class UWidgetAnimation;


UCLASS(Abstract)
class UICODEEXAMPLE_API UGGTitleMenuSceneWidget : public UGGSceneWidget
{
	GENERATED_BODY()
public:
	virtual void SetDataContext(UGGViewModel* inViewModel) override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

protected:
	void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

private:
	UPROPERTY(BlueprintReadWrite, transient, meta = (BindWidgetAnimOptional, AllowPrivateAccess = "true"))
	UWidgetAnimation* IdleAnimation = nullptr;
};