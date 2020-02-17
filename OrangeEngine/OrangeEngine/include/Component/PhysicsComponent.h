#ifndef PHYSICS_COMPONENT_H
#define PHYSICS_COMPONENT_H

#include <functional>
#include "../Manager/ComponentManager.h"
#include "../Utility/Util.h"

class ComponentManager;

class PhysicsComponent : public b2ContactListener {
public:
	PhysicsComponent(ComponentManager& obj, b2World& world);
	virtual ~PhysicsComponent() {};

	void Update(ComponentManager& obj, float timeDelta);
	void SetVelocity(sf::Vector2f velocity);
	void SetCollisionCallback(char* collisionWith, std::function<void()> callback);
	void ResetPosition(sf::Vector2f position);
	sf::Vector2f GetVelocity() const;

private:
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

	sf::Vector2f m_velocity;

	b2Body* m_body;
	b2World* m_world;
	std::map<char*, std::function<void()>> m_collisionCallbacks;
};

#endif // !PhysicsComponent_h
