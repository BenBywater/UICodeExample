#pragma once

#include "CoreMinimal.h"
#include <UObject/Object.h>
#include "../Data/SceneEnums.h"
#include "SceneManager.generated.h"

class UGGSceneManagerWidget;
class UUISceneDataPayload;

UCLASS()
class UICODEEXAMPLE_API UGGSceneManager : public UObject
{
	GENERATED_BODY()

public:
	void InitialiseSceneManagerWidget(TSubclassOf<UGGSceneManagerWidget> const & sceneManagerWidgetClass);

	void OpenScene(SceneEnum scene, UUISceneDataPayload* sceneDataPayload);
	void CloseScene();
private:
	UPROPERTY()
	UGGSceneManagerWidget* sceneManager = nullptr;

};
