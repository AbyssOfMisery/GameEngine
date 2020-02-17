#include "../Game/OrangeEngine.h"

int main(int argc, char** argv) {
	std::shared_ptr<Window> window = std::make_shared<Window>();
	std::shared_ptr<SceneManager> currentScene;

	std::shared_ptr<SceneManager> gameScene = std::make_shared<OrangeEngine>(window);

	currentScene = gameScene;

	while (!window->IsDone()) {
		currentScene->Update();
		currentScene->Render();
		currentScene->RestartClock();
	}
	return 0;
}