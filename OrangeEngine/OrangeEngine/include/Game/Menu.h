#ifndef MENU_H
#define MENU_H

#include "imgui.h"
#include "imgui-SFML.h"
#include "../Manager/SceneManager.h"

class Menu : public SceneManager {
public:
	Menu(std::shared_ptr<Window> windowprt);
	void Update();
	void Render();
	void RestartClock() {}

private:
	void DisplayMainMenu();
};

#endif // !MENU_H