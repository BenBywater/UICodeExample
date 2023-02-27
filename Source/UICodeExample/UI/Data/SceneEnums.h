#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class SceneEnum : uint8
{
  Placeholder   UMETA(DisplayName = "Placeholder"),
  Title     UMETA(DisplayName = "Title"),
  MainMenu      UMETA(DisplayName = "MainMenu"),
  HUD   UMETA(DisplayName = "HUD"),
  Inventory   UMETA(DisplayName = "Inventory"),
};