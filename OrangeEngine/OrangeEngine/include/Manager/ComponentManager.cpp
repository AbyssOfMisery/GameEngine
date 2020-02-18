#include "ComponentManager.h"


ComponentManager::ComponentManager(){}

void ComponentManager::Update(float timeDelta) {
	if (m_input != nullptr) m_input->Update(timeDelta);
	if (m_physics != nullptr) m_physics->Update(timeDelta);
	//if (m_graphics != nullptr) m_graphics->Update(*this, timeDelta);
	if (m_animator != nullptr) m_animator->Update(timeDelta);
	if (m_sprite != nullptr) m_sprite->Update(timeDelta);
	if (m_script != nullptr) m_script->Update(timeDelta);
	if (m_physics != nullptr) m_physics->SetVelocity({ 0,0 });

}

void ComponentManager::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	//if (m_graphics != nullptr) m_graphics->Draw(target);
	if (m_sprite != nullptr) target.draw(*m_sprite);
}