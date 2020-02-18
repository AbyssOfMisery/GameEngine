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
#include "../Component/SpriteComponent.h"
#include "../Component/AnimatorComponent.h"

class InputComponent;
class GraphicsComponent;
class PhysicsComponent;
class ScriptComponent;
class SpriteComponent;
class AnimatorComponent;

class ComponentManager : public sf::Drawable {

public:
	ComponentManager();
	virtual ~ComponentManager() {};

	virtual void Update(float timeDelta);

	//void LoadScriptFile(std::string c);

	void SetInputComponent(std::shared_ptr<InputComponent> input) { m_input = input; }
	void SetPhysicsComponent(std::shared_ptr<PhysicsComponent> physics) { m_physics = physics; }
	//void SetGraphicsComponent(std::shared_ptr<GraphicsComponent> graphics) { m_graphics = graphics; }
	void SetScriptComponent(std::shared_ptr<ScriptComponent> script) { m_script = script; }
	void SetSpriteComponent(std::shared_ptr<SpriteComponent> sprite) { m_sprite = sprite; }
	void SetAnimatorComponent(std::shared_ptr<AnimatorComponent> animator) { m_animator = animator; }


	std::shared_ptr<InputComponent> GetInputComponent() { return m_input; }
	std::shared_ptr<PhysicsComponent> GetPhysicsComponent() { return m_physics; }
	std::shared_ptr<GraphicsComponent> GetGraphicsComponent() { return nullptr; }
	std::shared_ptr<SpriteComponent> GetSpriteComponent() { return m_sprite; }
	std::shared_ptr<ScriptComponent> GetScriptComponent() { return m_script; }
	std::shared_ptr<AnimatorComponent> GetAnimatorComponent() { return m_animator; }

protected:

	std::shared_ptr<InputComponent> m_input;
	std::shared_ptr<PhysicsComponent> m_physics;
	//std::shared_ptr<GraphicsComponent> m_graphics;
	std::shared_ptr<SpriteComponent> m_sprite;
	std::shared_ptr<ScriptComponent> m_script;
	std::shared_ptr<AnimatorComponent> m_animator;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif