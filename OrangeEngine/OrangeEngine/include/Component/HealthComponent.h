#ifndef HealthComponent_h
#define HealthComponent_h

#include "../Manager/ComponentManager.h"
#include "BaseComponent.h"

class BaseComponent;

class HealthComponent : public BaseComponent {
public:
	HealthComponent(ComponentManager& obj) : BaseComponent(obj) {}
	HealthComponent(ComponentManager& obj, int health) : BaseComponent(obj), m_health(health) {}
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