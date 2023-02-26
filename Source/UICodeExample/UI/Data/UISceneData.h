#pragma once

#include "CoreMinimal.h"
#include <Engine/DataAsset.h>
#include "SceneEnums.h"
#include "UICodeExample/UI/Widgets/GGSceneWidget.h"
#include "UICodeExample/UI/ViewModels/GGSceneViewModel.h"
#include "UISceneData.generated.h"

USTRUCT(BlueprintType)
struct FUISceneTypeData
{
    GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UGGSceneWidget> sceneWidgetType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UGGSceneViewModel> sceneViewModelType;
};


UCLASS(BlueprintType)
class UICODEEXAMPLE_API UUISceneData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<SceneEnum, FUISceneTypeData> sceneData;

};
