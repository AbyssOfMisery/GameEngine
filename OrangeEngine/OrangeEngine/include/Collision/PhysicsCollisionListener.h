#ifndef PHYSICSCOLLISIONLISTENER_H
#define PHYSICSCOLLISIONLISTENER_H

#include <functional>
#include <map>
#include "Box2D/Box2D.h"

class PhysicsCollisionListener : public b2ContactListener {
public:
	void SetCollisionCallback(uint16 collisionMask, std::function<void(void* ptr)> callback);

private:
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

	std::map<uint16, std::function<void(void* ptr)>> m_collisionCallbacks;
};

#endif // !PHYSICSCOLLISIONLISTENER_HPP
