#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UICodeExample/UI/Widgets/GGUserWidget.h"
#include "GGSceneWidget.generated.h"

class UWidgetAnimation;
class UWidget;

UENUM(BlueprintType)
enum class SceneInputModeEnum : uint8
{
	UIOnly,
	GameAndUI,
	GameOnly
};

DECLARE_DELEGATE_OneParam(FOnSceneAnimationFinished, UGGSceneWidget* /* CloseScene */)

UCLASS(Abstract)
class UICODEEXAMPLE_API UGGSceneWidget : public UGGUserWidget
{
	GENERATED_BODY()
public:
	FOnSceneAnimationFinished EnterAnimationFinishedDelegate;
	FOnSceneAnimationFinished CloseAnimationFinishedDelegate;

	virtual bool Initialize() override;

	virtual void EnterScene();
	virtual void ExitScene();

protected:
	void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

private:
	UPROPERTY(BlueprintReadWrite, transient, meta = (BindWidgetAnimOptional, AllowPrivateAccess = "true"))
	UWidgetAnimation* EnterSceneAnimation = nullptr;

	UPROPERTY(BlueprintReadWrite, transient, meta = (BindWidgetAnimOptional, AllowPrivateAccess = "true"))
	UWidgetAnimation* ExitSceneAnimation = nullptr;

	UPROPERTY(BlueprintReadWrite, transient, meta = (BindWidgetOptional, AllowPrivateAccess = "true"))
	UWidget* DefaultFocusWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Input Mode", meta = (BindWidgetOptional, AllowPrivateAccess = "true"))
	SceneInputModeEnum DefaultInputMode = SceneInputModeEnum::UIOnly;
};