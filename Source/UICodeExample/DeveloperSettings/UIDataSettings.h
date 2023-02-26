#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include <UICodeExample/UI/SceneManager/SceneManagerWidget.h>
#include <UICodeExample/UI/Data/UISceneData.h>
#include <Engine/DataAsset.h>
#include "UIDataSettings.generated.h"

UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "UI Data"))
class UICODEEXAMPLE_API UUIDataSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UUIDataSettings();

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UGGSceneManagerWidget> SceneManagerWidgetClass;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSoftObjectPtr<UUISceneData> UUISceneDataPath;
};