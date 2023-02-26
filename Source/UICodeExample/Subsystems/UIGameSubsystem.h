#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UIGameSubsystem.generated.h"

class UGGSceneManager;

UCLASS(config = Game, transient, BlueprintType, Blueprintable)
class UICODEEXAMPLE_API UUIGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Sets default values for this empty's properties
	UUIGameSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize()  override;

	void CreateSceneManagerWidget();

	UGGSceneManager* GetSceneManager() const;

private:
	UPROPERTY()
	UGGSceneManager* sceneManager = nullptr;
};
