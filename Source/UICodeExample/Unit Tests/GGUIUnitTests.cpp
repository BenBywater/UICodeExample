#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Engine.h"
#include "EngineUtils.h"
#include "UICodeExample/UI/Data/UIHUDScenePayload.h"
#include "UICodeExample/UI/Helpers/GGUIHelpers.h"
#include "UICodeExample/UI/Widgets/GGHUDSceneWidget.h"
#include "UICodeExample/UI/Widgets/GGMainMenuSceneWidget.h"
#include "UICodeExample/UI/ViewModels/GGMenuButtonViewModel.h"

UWorld* GetTestWorld()
{
	const TIndirectArray<FWorldContext>& WorldContexts = GEngine->GetWorldContexts();
	for (const FWorldContext& Context : WorldContexts)
	{
		if (((Context.WorldType == EWorldType::PIE) || (Context.WorldType == EWorldType::Game)) && (Context.World() != nullptr))
		{
			return Context.World();
		}
	}

	return nullptr;
}

void BeforeEachTestSetup()
{
	AutomationOpenMap(TEXT("/Game/FirstPerson/Maps/FirstPersonMap"));
	UIHelpers::CloseAllScenes(GetTestWorld());
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUIUnitTest_SceneManager_NoScene, "UICodeExample.UI.SceneManager_NoScene", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FUIUnitTest_SceneManager_NoScene::RunTest(const FString& Parameters)
{
	BeforeEachTestSetup();

	UWorld* world = GetTestWorld();
	if (world)
	{
		int32 sceneStackCount = UIHelpers::GetSceneStackCount(world);
		return sceneStackCount == 0;

	}
	return false;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUIUnitTest_SceneManager_OneScene, "UICodeExample.UI.SceneManager_OneScene", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FUIUnitTest_SceneManager_OneScene::RunTest(const FString& Parameters)
{
	BeforeEachTestSetup();

	UWorld* world = GetTestWorld();
	UUIHUDScenePayload* hudPayload = NewObject<UUIHUDScenePayload>();
	if (world && hudPayload)
	{
		UIHelpers::OpenScene(world, SceneEnum::HUD, hudPayload);
		int32 sceneStackCount = UIHelpers::GetSceneStackCount(world);
		return sceneStackCount == 1;
	}
	return false;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUIUnitTest_SceneManager_TwoScene, "UICodeExample.UI.SceneManager_TwoScene", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FUIUnitTest_SceneManager_TwoScene::RunTest(const FString& Parameters)
{
	BeforeEachTestSetup();

	UWorld* world = GetTestWorld();
	UUIHUDScenePayload* hudPayload = NewObject<UUIHUDScenePayload>();
	if (world && hudPayload)
	{
		hudPayload->Health = 1.f;
		hudPayload->AmmoCount = 10;

		UIHelpers::OpenScene(world, SceneEnum::HUD, hudPayload);
		UIHelpers::OpenScene(world, SceneEnum::HUD, hudPayload);

		int32 sceneStackCount = UIHelpers::GetSceneStackCount(world);
		return sceneStackCount == 2;
	}
	return false;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUIUnitTestSceneManager_CloseScene, "UICodeExample.UI.SceneManager_CloseScene", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)
// Note that this test only works for scene that do not contain an Exit animation
bool FUIUnitTestSceneManager_CloseScene::RunTest(const FString& Parameters)
{
	BeforeEachTestSetup();

	UWorld* world = GetTestWorld();
	UUIHUDScenePayload* hudPayload = NewObject<UUIHUDScenePayload>();
	if (world && hudPayload)
	{
		hudPayload->Health = 1.f;
		hudPayload->AmmoCount = 10;

		UIHelpers::OpenScene(world, SceneEnum::HUD, hudPayload);
		UIHelpers::OpenScene(world, SceneEnum::HUD, hudPayload);
		UIHelpers::CloseScene(world);

		int32 sceneStackCount = UIHelpers::GetSceneStackCount(world);
		return sceneStackCount == 1;
	}
	return false;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUIUnitTest_HUDInit, "UICodeExample.UI.HUDInit", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FUIUnitTest_HUDInit::RunTest(const FString& Parameters)
{
	BeforeEachTestSetup();

	UWorld* world = GetTestWorld();
	UUIHUDScenePayload* hudPayload = NewObject<UUIHUDScenePayload>();
	if (world && hudPayload)
	{
		hudPayload->Health = 1.f;
		hudPayload->AmmoCount = 10;

		UIHelpers::OpenScene(world, SceneEnum::HUD, hudPayload);
		UGGSceneWidget* currentScene = UIHelpers::GetCurrentSceneWidget(world);
		if (UGGHUDSceneWidget* hudScene = Cast<UGGHUDSceneWidget>(currentScene))
		{
			bool isHealthCorrect = hudScene->GetHealth() == 1.f;
			bool isAmmoCorrect = hudScene->GetAmmo() == 10;

			return (isHealthCorrect && isAmmoCorrect);
		}
	}
	return false;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUIUnitTest_CollectionPanelWidget_WidgetPool, "UICodeExample.UI.CollectionPanelWidget_WidgetPool", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FUIUnitTest_CollectionPanelWidget_WidgetPool::RunTest(const FString& Parameters)
{
	BeforeEachTestSetup();

	UWorld* world = GetTestWorld();
	if (const UUIDataSettings* uiDataSettings = GetDefault<UUIDataSettings>())
	{
		UUIMainMenuButtonData* data = uiDataSettings->UIMenuButtonData.LoadSynchronous();
		UUIMainMenuScenePayload* payload = NewObject<UUIMainMenuScenePayload>();
		if (payload && data)
		{
			payload->menuButtonData = data->menuButtonData;
			UIHelpers::OpenScene(world, SceneEnum::MainMenu, payload);
		}

		UGGSceneWidget* currentScene = UIHelpers::GetCurrentSceneWidget(world);
		if (UGGMainMenuSceneWidget* mainMenuScene = Cast<UGGMainMenuSceneWidget>(currentScene))
		{
			TArray<UGGMenuButtonViewModel*> ButtonViewModels;
			if (UGGMenuButtonViewModel* ButtonViewModel = NewObject<UGGMenuButtonViewModel>())
			{
				ButtonViewModels.Add(ButtonViewModel);
				mainMenuScene->UpdateButtonContainerWidget(ButtonViewModels);
				return mainMenuScene->GetMenuButtonCount() == ButtonViewModels.Num();
			}
		}
	}
	return false;
}