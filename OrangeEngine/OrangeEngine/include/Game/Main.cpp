#include "Menu.h"
#include "../Game/OrangeEngine.h"

int main(int argc, char** argv) {
	std::shared_ptr<Window> window = std::make_shared<Window>();
	ImGui::SFML::Init(*window->GetRenderWindow());
	std::shared_ptr<SceneManager> currentScene;

	std::shared_ptr<SceneManager> menuScene = std::make_shared<Menu>(window);
	std::shared_ptr<SceneManager> gameScene = std::make_shared<OrangeEngine>(window);


	currentScene = gameScene;

	while (!currentScene->IsDone()) {
			currentScene->Update();
			currentScene->Render();
			currentScene->RestartClock();
			if (currentScene->IsChangeScene()) {
				currentScene->SetChangeScene(false);
				currentScene = currentScene == menuScene ? gameScene : menuScene;
			}
		}

	ImGui::SFML::Shutdown();
	return 0;
}