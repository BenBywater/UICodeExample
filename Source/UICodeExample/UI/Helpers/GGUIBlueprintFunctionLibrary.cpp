#include "GGUIBlueprintFunctionLibrary.h"
#include <Engine/World.h>
#include <Components/TextBlock.h>
#include "GGUIHelpers.h"
#include "UICodeExample/UI/Bindables/FloatBindable.h"
#include "UICodeExample/UI/Bindables/ProgressBarBindable.h"
#include "UICodeExample/UI/Widgets/GGProgressBarWidget.h"
#include "UICodeExample/UI/Bindables/TextBindable.h"


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
