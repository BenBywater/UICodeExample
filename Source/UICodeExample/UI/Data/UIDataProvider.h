#pragma once

#include "CoreMinimal.h"
#include <UObject/Object.h>
#include "UICodeExample/UI/SceneManager/SceneManagerWidget.h"
#include "UIDataProvider.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UICODEEXAMPLE_API UUIDataProvider : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UGGSceneManagerWidget> SceneManagerWidgetClass;

};
