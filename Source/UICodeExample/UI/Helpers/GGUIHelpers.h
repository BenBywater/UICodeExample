#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Data/SceneEnums.h"

class UUISceneDataPayload;
class UGGSceneWidget;

namespace UIHelpers
{
	void OpenScene(const UWorld* world, SceneEnum scene, UUISceneDataPayload* sceneDataPayload);
	void CloseScene(const UWorld* world);
	void CloseAllScenes(const UWorld* world);
	UGGSceneWidget* GetCurrentSceneWidget(const UWorld* world);
	int32 GetSceneStackCount(const UWorld* world);
}
