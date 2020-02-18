#include "OrangeEngine.h"
#include <functional>
#include "../Manager/TextureManager.h"

OrangeEngine::OrangeEngine(std::shared_ptr<Window> windowprt) : 
	SceneManager(windowprt), m_world(b2Vec2(0, 0)),
	m_player(m_world),
	m_debugDraw(*m_window->GetRenderWindow())
{
	m_clock.restart();
	m_previousTime = m_clock.getElapsedTime();
	srand(time(nullptr));

	m_world.SetDebugDraw(&m_debugDraw);
	m_debugDraw.SetFlags(b2Draw::e_shapeBit);

	m_font.loadFromFile("resource/fonts/ADDSBP__.TTF");
	m_Scene = Scene1(*m_window->GetRenderWindow());
	sf::Vector2f PlayerPos = m_Scene.GenerateScene1(m_world);

	m_newLevelCallback = [&]() { m_generateNewLevel = true; };
	m_player.GetPhysicsComponent()->SetCollisionCallback(DOOR_UNLOCKED, m_newLevelCallback);
	
	m_player.GetPhysicsComponent()->SetPosition({ PlayerPos.x, PlayerPos.y });
	m_window->GetRenderWindow()->setFramerateLimit(FPS);
}

OrangeEngine::~OrangeEngine() {}

sf::Time OrangeEngine::GetElapsed() {
	return m_clock.getElapsedTime() - m_previousTime;
}

void OrangeEngine::RestartClock() {
	m_previousTime += GetElapsed();
	m_clock.restart();
}

void OrangeEngine::Update() {
	m_window->Update();
	sf::Time deltaTime = m_clock.getElapsedTime() - GetElapsed();

	m_player.Update(deltaTime.asSeconds());
	m_window->MoveView(m_player.GetPhysicsComponent()->GetPosition());

	if (m_generateNewLevel) {
		m_generateNewLevel = false;
		sf::Vector2f PlayerPos = m_Scene.GenerateScene1(m_world);
		m_player.GetPhysicsComponent()->SetPosition({ PlayerPos.x, PlayerPos.y });
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U)) m_Scene.UnlockDoor();
}

void OrangeEngine::Render() {
	m_window->BeginDraw();

	m_window->Draw(m_Scene);

	m_window->Draw(m_player);

	if (m_window->IsDebug()) m_world.DrawDebugData();

	m_window->EndDraw();

}