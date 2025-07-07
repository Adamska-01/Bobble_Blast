#include "Application.h"
#include "Constants/AssetPaths.h"
#include "Scenes/MainMenuScene.h"
#include <SubSystems/Window.h>


Application::Application()
{
	Window::SetWindowIcon(AssetPaths::Files::ARROW_IMAGE_PATH);
	Window::SetWindowTitle("Bobble Blast");

	SceneManager::LoadScene<MainMenuScene>();
}