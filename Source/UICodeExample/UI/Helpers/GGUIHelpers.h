#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Data/SceneEnums.h"

class UUISceneDataPayload;

namespace UIHelpers
{
	void OpenScene(const UWorld* world, SceneEnum scene, UUISceneDataPayload* sceneDataPayload);
	void CloseScene(const UWorld* world);
}
