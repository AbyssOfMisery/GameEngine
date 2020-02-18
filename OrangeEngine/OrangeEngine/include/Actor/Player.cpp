#include "Player.h"
#include <iostream>
#include "../Utility/Util.h"
#include "../Manager/TextureManager.h"

Player::Player(b2World& world) {
	//m_graphics = std::make_shared<PlayerGraphicsComponent>("Demo");
	m_sprite = std::make_shared<SpriteComponent>(*this);
	m_physics = std::make_shared<PhysicsComponent>(*this, world);
	m_input = std::make_shared<InputComponent>(*this);
	m_health = std::make_shared<HealthComponent>(*this);

	auto texture = TextureManager::AddTexture("resource/players/mage/spr_mage_idle_up.png");
	m_sprite->SetSprite(texture);
}

// Updates the player object.
void Player::Update(float timeDelta) {
	ComponentManager::Update(timeDelta);
}

// Returns the player's class.
PLAYER_CLASS Player::GetClass() const {
	return m_class;
}

// Set the player's health.
void Player::SetHealth(int healthValue) {
	if (m_health == nullptr) return;

	m_health->SetHealth(healthValue);
}