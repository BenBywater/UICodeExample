# UICodeExample
 Hello! This project is indeded show how MVVM can be used to create a scalable UI solution in unreal.
 Within this project I have created a framework for creating UI screens and the widgets within those screens.
 
 Please watch this video to see the demo and listen to myself explain what I created.
 https://www.youtube.com/watch?v=6fS324vINM8
 
You might notice a lack of smart pointers used in this project. I am aware of the smart pointers that the Standard Library includes. However, they cannot be used with unreals UObject system. This is because Unreals UObjects use a separate memory-tracking system that is better-tuned for game code. Hence, where I use raw UObject pointers, I tag them with a UPROPERTY macro. This ensures that unreal is aware of the raw pointer and will manage its life cycle once the pointer has gone out of scope. 

Below are areas of code I think you would find interesting to look at
## MVVM classes and the HUD scene as an example use case

UICodeExample\Source\UICodeExample\UI\Widgets\GGUserWidget.cpp
UICodeExample\Source\UICodeExample\UI\Widgets\GGUserWidget.h

UICodeExample\Source\UICodeExample\UI\ViewModels\GGViewModel.cpp
UICodeExample\Source\UICodeExample\UI\ViewModels\GGViewModel.h

UICodeExample\Source\UICodeExample\UI\Widgets\GGSceneWidget.cpp
UICodeExample\Source\UICodeExample\UI\Widgets\GGSceneWidget.h

UICodeExample\Source\UICodeExample\UI\ViewModels\GGSceneViewModel.cpp
UICodeExample\Source\UICodeExample\UI\ViewModels\GGSceneViewModel.h

UICodeExample\Source\UICodeExample\UI\Widgets\GGHUDSceneWidget.h
UICodeExample\Source\UICodeExample\UI\Widgets\GGHUDSceneWidget.h

UICodeExample\Source\UICodeExample\UI\ViewModels\GGHUDSceneViewModel.h
UICodeExample\Source\UICodeExample\UI\ViewModels\GGHUDSceneViewModel.h

## Scene Manager

UICodeExample\Source\UICodeExample\UI\SceneManager\SceneManager.cpp
UICodeExample\Source\UICodeExample\UI\SceneManager\SceneManager.h

UICodeExample\Source\UICodeExample\UI\SceneManager\SceneManagerWidget.cpp
UICodeExample\Source\UICodeExample\UI\SceneManager\SceneManagerWidget.h

## Data Bindings

UICodeExample\UI\Bindables\FloatBindable.cpp
UICodeExample\UI\Bindables\FloatBindable.h

## Custom Buttons with BitFlags
UICodeExample\Source\UICodeExample\UI\Widgets\GGButton.cpp
UICodeExample\Source\UICodeExample\UI\Widgets\GGButton.h

## Collection Panel Widget

UICodeExample\Source\UICodeExample\UI\Widgets\GGCollectionPanelWidget.cpp
UICodeExample\Source\UICodeExample\UI\Widgets\GGCollectionPanelWidget.h

## Progrss Bar Widget

UICodeExample\Source\UICodeExample\UI\Widgets\GGProgressBarWidget.cpp
UICodeExample\Source\UICodeExample\UI\Widgets\GGProgressBarWidget.h
UICodeExample\Content\UI\Generic\M_StackedBar.uasset
UICodeExample\Screenshots\ProgressBarMaterial.png

## Unit Tests
UICodeExample\Source\UICodeExample\Unit Tests\GGUIUnitTests.cpp