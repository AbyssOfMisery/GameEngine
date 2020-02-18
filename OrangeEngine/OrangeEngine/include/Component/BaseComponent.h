#ifndef BASE_COMPONENT_H
#define BASE_COMPONENT_H

class ComponentManager;

class BaseComponent {
public:
	BaseComponent(ComponentManager &obj) : m_gameObject(obj) {};
	virtual void Update(float timeDelta) = 0;

protected:
	ComponentManager& m_gameObject;
};

#endif // !BASE_COMPONENT_H

