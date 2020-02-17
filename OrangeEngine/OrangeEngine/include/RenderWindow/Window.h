#ifndef WINDOW_H
#define WINDOW_H

#include "../Utility/Util.h"
#include "../Utility/Enums.h"

class Window {
public:
	Window();
	~Window();

	void BeginDraw();
	void Draw(sf::Drawable& drawable);
	void EndDraw();

	void Update();
	void MoveView(sf::Vector2f position);

	bool IsDone();
	bool IsFullscreen();
	bool IsDebug();

	sf::RenderWindow* GetRenderWindow();
	sf::Vector2u GetWindowSize();

	void ToggleFullscreen();

private:
	void Setup();
	void SplashScreen();
	void Create();
	void Destroy();

	sf::RenderWindow m_window;
	sf::View m_views[static_cast<int>(VIEW::COUNT)];
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;

	VIEW m_currentView;

	bool m_isDone;
	bool m_isFullscreen;
	bool m_isDebug;
};

#endif // !WINDOW_H