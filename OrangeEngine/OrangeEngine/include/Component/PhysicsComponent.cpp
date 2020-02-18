#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(ComponentManager& obj, b2Body* body) :
	BaseComponent(obj), 
	m_body(body)
{}

void PhysicsComponent::Update(float timeDelta) {
	m_body->SetActive(IsActive());
	if (!IsActive()) return;
	m_body->SetLinearVelocity({ m_velocity.x * timeDelta, m_velocity.y * timeDelta });
	//m_body->ApplyForce(b2Vec2(20,20), b2Vec2(2,2),true);
	m_position = { m_body->GetPosition().x * PIXEL_PER_METER , m_body->GetPosition().y * PIXEL_PER_METER };
}

void PhysicsComponent::SetVelocity(sf::Vector2f velocity) {
	m_velocity = velocity;
}

sf::Vector2f PhysicsComponent::GetVelocity() const {
	return m_velocity;
}


sf::Vector2f PhysicsComponent::GetPosition() const {
	return m_position;
}

void PhysicsComponent::SetPosition(sf::Vector2f position) {
	m_position = position;
	m_body->SetTransform({ position.x / PIXEL_PER_METER, position.y / PIXEL_PER_METER }, m_body->GetAngle());
}
