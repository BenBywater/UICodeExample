#pragma once

#include "CoreMinimal.h"
#include "Engine\GameInstance.h"
#include "UICodeExample/UI/Data/UIDataProvider.h"
#include "GGGameInstance.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UICODEEXAMPLE_API UGGGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UGGGameInstance();

	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	void CreateSceneManagerWidget();

	UPROPERTY(EditAnywhere, BlueprintReadOnly) 
	TSubclassOf<UUIDataProvider> UIDataProviderClass;
};
