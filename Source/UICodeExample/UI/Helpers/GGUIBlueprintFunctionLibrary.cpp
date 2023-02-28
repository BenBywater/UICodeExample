#include "GGUIBlueprintFunctionLibrary.h"
#include <Engine/World.h>
#include <Components/TextBlock.h>
#include "GGUIHelpers.h"

void UGGUIBlueprintFunctionLibrary::OpenScene(UObject* WorldContextObject, SceneEnum scene, UUISceneDataPayload* sceneDataPayload)
{
	if (UWorld* world = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		UIHelpers::OpenScene(world, scene, sceneDataPayload);
	}
	//Log Error
}

void UGGUIBlueprintFunctionLibrary::CloseScene(UObject* WorldContextObject)
{
	if (UWorld* world = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		UIHelpers::CloseScene(world);
	}
	//Log Error
}

void UGGUIBlueprintFunctionLibrary::BindFloatBindable(UPARAM(ref)FFloatBindable& inBinding, UTextBlock* inTextBlock)
{
	if (inTextBlock)
	{
		inBinding.SetFloatDataBinding(inTextBlock);
	}
	//Log Error
}

void UGGUIBlueprintFunctionLibrary::BindTextBindable(FTextBindable& inBinding, UTextBlock* inTextBlock)
{
	if (inTextBlock)
	{
		inBinding.SetTextDataBinding(inTextBlock);
	}
}

void UGGUIBlueprintFunctionLibrary::BindProgressBarBindable(FProgressBarBindable& inBinding, UGGProgressBarWidget* inProgressBar)
{
	if (inProgressBar)
	{
		inBinding.SetProgressBarBinding(inProgressBar);
	}
	//Log Error
}

void UGGUIBlueprintFunctionLibrary::BindVisibilityBindable(FVisibilityBindable& inBinding, UWidget* inWidget)
{
	if (inWidget)
	{
		inBinding.SetVisibilityBinding(inWidget);
	}
	//Log Erro
}