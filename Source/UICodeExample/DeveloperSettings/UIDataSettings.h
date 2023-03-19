#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include <Engine/DataAsset.h>
#include <UICodeExample/UI/SceneManager/SceneManagerWidget.h>
#include <UICodeExample/UI/Data/UISceneData.h>
#include <UICodeExample/UI/Data/UIMenuButtonData.h>
#include <UICodeExample/UI/Data/UIButtonStylesData.h>
#include "UIDataSettings.generated.h"

UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "UI Data"))
class UICODEEXAMPLE_API UUIDataSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UUIDataSettings() = default;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "UI|SceneManager")
	TSubclassOf<class UGGSceneManagerWidget> SceneManagerWidgetClass;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "UI|SceneManager")
	TSoftObjectPtr<UUISceneData> UISceneDataPath;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "UI|MainMenu")
	TSoftObjectPtr<UUIMainMenuButtonData> UIMenuButtonData;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "UI|Buttons")
	TSoftObjectPtr<UUIButtonStylesData> UIButtonStylesData;
};