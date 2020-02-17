#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../Component/GraphicsComponent.h"
#include "../Component/InputComponent.h"
#include "../Component/PhysicsComponent.h"
#include "../Component/ScriptComponent.h"

class InputComponent;
class GraphicsComponent;
class PhysicsComponent;
class ScriptComponent;

class ComponentManager : public sf::Drawable {

public:
	ComponentManager();
	virtual ~ComponentManager() {};

	virtual void Update(float timeDelta);

	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition() const { return m_position; }

	void SetInfluence(float influence) { m_influenceValue = influence; }
	float GetInfluence() const { return m_influenceValue; }

	void LoadScriptFile(std::string c);

	void SetInputComponent(std::shared_ptr<InputComponent> input) { m_input = input; }
	void SetPhysicsComponent(std::shared_ptr<PhysicsComponent> physics) { m_physics = physics; }
	void SetGraphicsComponent(std::shared_ptr<GraphicsComponent> graphics) { m_graphics = graphics; }
	void SetScriptComponent(std::shared_ptr<ScriptComponent> script) { m_script = script; }

	std::shared_ptr<InputComponent> GetInputComponent() { return m_input; }
	std::shared_ptr<PhysicsComponent> GetPhysicsComponent() { return m_physics; }
	std::shared_ptr<GraphicsComponent> GetGraphicsComponent() { return m_graphics; }
	std::shared_ptr<ScriptComponent> GetScriptComponent() { return m_script; }

protected:
	sf::Vector2f m_position;
	float m_influenceValue;

	std::shared_ptr<InputComponent> m_input;
	std::shared_ptr<PhysicsComponent> m_physics;
	std::shared_ptr<GraphicsComponent> m_graphics;
	std::shared_ptr<ScriptComponent> m_script;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif