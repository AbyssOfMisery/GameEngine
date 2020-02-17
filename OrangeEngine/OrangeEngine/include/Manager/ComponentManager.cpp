#include "ComponentManager.h"

ComponentManager::ComponentManager() {
	m_position = { 0,0 };
	m_influenceValue = 1.0f;
}

void ComponentManager::Update(float timeDelta) {
	if (m_input != nullptr) m_input->Update(*this);
	if (m_physics != nullptr) m_physics->Update(*this, timeDelta);
	if (m_graphics != nullptr) m_graphics->Update(*this, timeDelta);
	if (m_physics != nullptr) m_physics->SetVelocity({ 0,0 });

}

void ComponentManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_graphics != nullptr) m_graphics->Draw(target);
}

void ComponentManager::SetPosition(sf::Vector2f position) {
	m_position = position;
	if (m_physics != nullptr) m_physics->ResetPosition(position);
	if (m_graphics != nullptr) m_graphics->GetSprite().setPosition(position);
}

void ComponentManager::LoadScriptFile(std::string c)
{
	if (m_script != nullptr) m_script->loadScriptFile(c);
}
