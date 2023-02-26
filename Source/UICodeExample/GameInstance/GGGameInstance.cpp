#include "GGGameInstance.h"
#include <UICodeExample/Subsystems/UIGameSubsystem.h>

UGGGameInstance::UGGGameInstance()
{
	
}

void UGGGameInstance::Init()
{
	Super::Init();

	
}

void UGGGameInstance::CreateSceneManagerWidget()
{
	UUIGameSubsystem* uiSubsystem = GetSubsystem<UUIGameSubsystem>();

	if (uiSubsystem)
	{
		uiSubsystem->CreateSceneManagerWidget();
	}
}
