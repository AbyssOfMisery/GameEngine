#ifndef ORANGE_ENGINE_H
#define ORANGE_ENGINE_H

#include <functional>
#include "../Manager/SceneManager.h"
#include "../Scene/Scene1.h"
#include "../Collision/PhysicsCollisionListener.h"
#include "../Debug/SFMLDebugDraw.h"
#include "../Manager/ComponentManager.h"

class OrangeEngine : public SceneManager {
public:
	OrangeEngine(std::shared_ptr<Window> windowprt);
	~OrangeEngine();

	void Update();
	void Render();
	virtual void RestartClock();

	sf::Time GetElapsed();

private:

	void SetupEntity(std::string textureFilenamePrefix, uint16 physicsCategory, sf::Vector2f position, bool isPlayer = false);
	void SetupItem(std::string textureFilename, sf::Vector2f position, uint16 physicsCategory);

	std::function<void()> m_newLevelCallback;
	std::function<void()> m_unlockDoorCallbak;
	bool m_generateNewLevel = false;

	Scene1 m_Scene;
	b2World m_world;
	PhysicsCollisionListener m_collisionListener;
	SFMLDebugDraw m_debugDraw;

	std::vector<std::shared_ptr<ComponentManager>> m_gameObjects;

	std::vector<std::shared_ptr<InputComponent>> m_inputComponents;
	std::vector<std::shared_ptr<PhysicsComponent>> m_physicComponents;
	std::vector<std::shared_ptr<AnimatorComponent>> m_animatorComponents;
	std::vector<std::shared_ptr<SpriteComponent>> m_spriteComponents;
	std::vector<std::shared_ptr<ScriptComponent>> m_scriptComponents;
	std::vector<std::shared_ptr<HealthComponent>> m_healthComponents;

	sf::Clock m_clock;
	sf::Time m_previousTime;
	sf::Font m_font;
};

#endif // !GAME_HPP
