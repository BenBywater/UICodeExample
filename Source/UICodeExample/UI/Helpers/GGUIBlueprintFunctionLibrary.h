#pragma once

#include "CoreMinimal.h"
#include "UICodeExample/UI/Data/SceneEnums.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UICodeExample/UI/Bindables/VisibilityBindable.h"
#include "UICodeExample/UI/Bindables/ProgressBarBindable.h"
#include "UICodeExample/UI/Bindables/TextBindable.h"
#include "UICodeExample/UI/Bindables/FloatBindable.h"
#include "GGUIBlueprintFunctionLibrary.generated.h"

class UTextBlock;
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

    UFUNCTION(BlueprintCallable, Category="Bindables")
    static void BindVisibilityBindable(UPARAM(ref)FVisibilityBindable& inBinding, UWidget* inWidget);
};