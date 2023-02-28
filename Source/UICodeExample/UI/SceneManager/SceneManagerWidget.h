#pragma once

#include "CoreMinimal.h"
#include <Blueprint/UserWidget.h>
#include "SceneManagerWidget.generated.h"

class UGGSceneWidget;
class UCanvasPanel;

UCLASS()
class UICODEEXAMPLE_API UGGSceneManagerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void PushScene(UGGSceneWidget* newScene);
	void PopScene();
	void PopAllScenes();
	UGGSceneWidget* GetCurrentScene() const;
	int32 GetSceneStackCount() const;

private:
	void OnCloseAnimationFinished(UGGSceneWidget* closedScene);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UCanvasPanel* SceneLayer;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UCanvasPanel* PopupLayer;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess))
	UCanvasPanel* ToolTipLayer;
};
