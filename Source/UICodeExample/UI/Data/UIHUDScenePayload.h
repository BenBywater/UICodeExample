#pragma once

#include "CoreMinimal.h"
#include "UISceneDataPayload.h"
#include "UIHUDScenePayload.generated.h"

UCLASS(BlueprintType)
class UICODEEXAMPLE_API UUIHUDScenePayload : public UUISceneDataPayload
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintType, BlueprintReadWrite)
    float Health = 0;

    UPROPERTY(BlueprintType, BlueprintReadWrite)
    float AmmoCount = 0;
};
