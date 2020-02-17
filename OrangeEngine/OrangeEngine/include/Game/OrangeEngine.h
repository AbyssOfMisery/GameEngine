#ifndef ORANGE_ENGINE_H
#define ORANGE_ENGINE_H

#include <functional>
#include "../Manager/SceneManager.h"
#include "../Scene/Scene1.h"
#include "../Actor/Player.h"
#include "../Debug/SFMLDebugDraw.h"

class OrangeEngine : public SceneManager {
public:
	OrangeEngine(std::shared_ptr<Window> windowprt);
	~OrangeEngine();

	void Update();
	void Render();
	virtual void RestartClock();

	sf::Time GetElapsed();

private:
	std::function<void()> m_newLevelCallback;
	bool m_generateNewLevel = false;

	Scene1 m_Scene;
	b2World m_world;
	SFMLDebugDraw m_debugDraw;

	Player m_player;

	sf::Clock m_clock;
	sf::Time m_previousTime;
	sf::Font m_font;
};

#endif // !GAME_HPP
