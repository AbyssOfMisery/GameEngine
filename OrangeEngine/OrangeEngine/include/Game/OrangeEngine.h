#ifndef ORANGE_ENGINE_H
#define ORANGE_ENGINE_H

#include <functional>
#include "../Manager/SceneManager.h"
#include "../Scene/Scene1.h"
#include "../Collision/PhysicsCollisionListener.h"
#include "../Debug/SFMLDebugDraw.h"
#include "../Actor/GameObject.h"
#include "../Utility/Util.h"
#include <lua.h>
#define SOL_ALL_SAFETIES_ON 1
#include "../sol/sol.hpp"
class OrangeEngine : public SceneManager {
public:
	OrangeEngine(std::shared_ptr<Window> windowprt);
	~OrangeEngine();


	virtual void Update();
	virtual void Render();
	virtual void RestartClock();

	sf::Time GetElapsed();
	sol::state luaPlus;
private:

	void SetupNewLevel();
	int SetupGameObject(std::string texture, std::string sound, uint16 physicsCategory, bool isEntity, int frames = ANIMATION_FRAMES, bool isPlayer = false);

	// Callbacks to collisions
	std::function<void(void* ptr)> m_newLevelCallback;
	std::function<void(void* ptr)> m_unlockDoorCallback;
	std::function<void(void* ptr)> m_collectScoreCallback;

	Scene1 m_Scene;
	b2World m_world;
	PhysicsCollisionListener m_collisionListener;
	SFMLDebugDraw m_debugDraw;


	std::vector<std::shared_ptr<GameObject>> m_gameObjects;

	std::vector<std::shared_ptr<InputComponent>> m_inputComponents;
	std::vector<std::shared_ptr<PhysicsComponent>> m_physicComponents;
	std::vector<std::shared_ptr<AnimatorComponent>> m_animatorComponents;
	std::vector<std::shared_ptr<SpriteComponent>> m_spriteComponents;
	std::vector<std::shared_ptr<HealthComponent>> m_healthComponents;
	std::vector<std::shared_ptr<SoundComponent>> m_soundComponents;
	std::vector<std::shared_ptr<ScriptComponent>> m_scriptComponents;

	sf::Clock m_clock;
	sf::Time m_previousTime;
	sf::Font m_font;

	int m_scoreTotal;
	bool m_generateNewLevel;
};

#endif // !ORANGE_ENGINE_H
