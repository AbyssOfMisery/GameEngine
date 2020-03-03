#ifndef PHYSICS_COMPONENT_H
#define PHYSICS_COMPONENT_H

#include <functional>
#include "../Actor/GameObject.h"
#include "BaseComponent.h"
#include "../Utility/Util.h"
#include <sol.hpp>
class BaseComponent;
class ComponentManager;

class PhysicsComponent : public BaseComponent {
public:
	PhysicsComponent(sol::state &_luaPlus,GameObject& obj, b2Body* body);
	virtual ~PhysicsComponent() {};

	void Update(float timeDelta);

	void SetVelocity(sf::Vector2f velocity);
	void SetPosition(sf::Vector2f position);
	void SetPositions(float x, float y);
	sf::Vector2f GetVelocity() const;
	sf::Vector2f GetPosition() const;

private:

	b2Body* m_body;
	b2World* m_world;

	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
};

#endif // !PhysicsComponent_h
