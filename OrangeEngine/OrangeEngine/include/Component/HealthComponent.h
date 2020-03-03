#ifndef HealthComponent_h
#define HealthComponent_h

#include "../Actor/GameObject.h"
#include "BaseComponent.h"

class BaseComponent;

class HealthComponent : public BaseComponent {
public:
	HealthComponent(GameObject& obj) : BaseComponent(obj) {}
	HealthComponent(GameObject& obj, int health) : BaseComponent(obj), m_health(health) {}
	~HealthComponent() {};

	void Update(float timeDelta) {}
	void SetHealth(int health) { m_health = health; }
	int GetHealth() const { return m_health; }
	void Damage(int damage) { m_health -= damage; }
	bool IsDead() { return m_health > 0; }

protected:
	int m_health;
	int m_maxHealth;
};

#endif // !HealthComponent_h