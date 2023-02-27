#pragma once

#include "CoreMinimal.h"
#include "UISceneDataPayload.h"
#include "UIMainMenuScenePayload.generated.h"

UCLASS(BlueprintType)
class UICODEEXAMPLE_API UUIMainMenuScenePayload : public UUISceneDataPayload
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintType, BlueprintReadWrite)
    TArray<FUIMenuButtonData> menuButtonData;
};
