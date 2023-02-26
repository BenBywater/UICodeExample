#include "GGUIBlueprintFunctionLibrary.h"
#include <Engine/World.h>
#include "GGUIHelpers.h"
#include "../Bindables/FloatBindable.h"
#include <Components/TextBlock.h>
#include "../Bindables/ProgressBarBindable.h"
#include "../Widgets/GGProgressBarWidget.h"


void UGGUIBlueprintFunctionLibrary::OpenScene(UObject* WorldContextObject, SceneEnum scene, UUISceneDataPayload* sceneDataPayload)
{
	if (UWorld* world = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		UIHelpers::OpenScene(world, scene, sceneDataPayload);
	}
	
}

void UGGUIBlueprintFunctionLibrary::CloseScene(UObject* WorldContextObject)
{
	if (UWorld* world = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		UIHelpers::CloseScene(world);
	}
}

void UGGUIBlueprintFunctionLibrary::BindFloatBindable(UFloatBindable* inBinding, UTextBlock* inTextBlock)
{
	if (inBinding && inTextBlock)
	{
		inBinding->SetFloatDataBinding(inTextBlock);
	}
}

void UGGUIBlueprintFunctionLibrary::BindProgressBarBindable(FProgressBarBindable& inBinding, UGGProgressBarWidget* inProgressBar)
{
	if (inProgressBar)
	{
		inBinding.SetProgressBarBinding(inProgressBar);
	}
}
