#pragma once

#include "CoreMinimal.h"
#include <Blueprint/UserWidget.h>
#include "SceneManagerWidget.generated.h"

class UGGSceneWidget;

UCLASS()
class UICODEEXAMPLE_API UGGSceneManagerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void PushScene(UGGSceneWidget* newScene);
	void PopScene();

private:
	void OnCloseAnimationFinished(UGGSceneWidget* closedScene);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	class UCanvasPanel* SceneLayer;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	class UCanvasPanel* PopupLayer;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	class UCanvasPanel* ToolTipLayer;

	UPROPERTY()
	TArray<UGGSceneWidget*> SceneStack;
};
