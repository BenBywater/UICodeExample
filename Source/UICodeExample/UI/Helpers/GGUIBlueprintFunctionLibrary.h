#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Data/SceneEnums.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GGUIBlueprintFunctionLibrary.generated.h"

class UTextBlock;
struct FProgressBarBindable;
class UGGProgressBarWidget;

UCLASS()
class UGGUIBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Scene Manager", meta = (WorldContext = "WorldContextObject"))
    static void OpenScene(UObject * WorldContextObject, SceneEnum scene, UUISceneDataPayload* sceneDataPayload);

    UFUNCTION(BlueprintCallable, Category="Scene Manager", meta = (WorldContext = "WorldContextObject"))
    static void CloseScene(UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category="Bindables")
    static void BindFloatBindable(UPARAM(ref)FFloatBindable& inBinding, UTextBlock* inTextBlock);

    UFUNCTION(BlueprintCallable, Category="Bindables")
    static void BindTextBindable(UPARAM(ref)FTextBindable& inBinding, UTextBlock* inTextBlock);

    UFUNCTION(BlueprintCallable, Category="Bindables")
    static void BindProgressBarBindable(UPARAM(ref)FProgressBarBindable& inBinding, UGGProgressBarWidget* inProgressBar);
};