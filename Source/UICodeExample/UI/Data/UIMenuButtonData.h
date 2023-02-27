#pragma once

#include "CoreMinimal.h"
#include <Engine/DataAsset.h>
#include "UIMenuButtonData.generated.h"

USTRUCT(BlueprintType)
struct FUIMenuButtonData
{
    GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText MenuText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString stringID;

};


UCLASS(BlueprintType)
class UICODEEXAMPLE_API UUIMainMenuButtonData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FUIMenuButtonData> menuButtonData;
};
