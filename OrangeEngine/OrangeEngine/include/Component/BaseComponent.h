#ifndef BASE_COMPONENT_H
#define BASE_COMPONENT_H

#include <string>
class GameObject;

class BaseComponent {
public:
	BaseComponent(GameObject &obj) : m_gameObject(obj), m_active(true) {};
	virtual void Update(float timeDelta) = 0;

	void SetActive(bool active) { m_active = active; }
	bool IsActive() const { return m_active; }

	std::string componentName;
protected:
	GameObject& m_gameObject;
	bool m_active;
};

#endif // !BASE_COMPONENT_H

