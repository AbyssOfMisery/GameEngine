#ifndef InputComponent_h
#define InputComponent_h

#include <map>

#include "../Utility/Enums.h"
#include "../Actor/GameObject.h"
#include "../Component/Command.h"
#include "BaseComponent.h"

class BaseComponent;
class Command;

class InputComponent : public BaseComponent{

public:

	InputComponent(GameObject& obj);
	~InputComponent() {};

	void BindKey(KEY key, sf::Keyboard::Key keyToBind);
	void Update(float timeDelta);

protected:
	// Default key bindings
	std::map<KEY, sf::Keyboard::Key> m_keyMappings;

	std::shared_ptr<Command> m_keyLeftCommand;
	std::shared_ptr<Command> m_keyRightCommand;
	std::shared_ptr<Command> m_keyUpCommand;
	std::shared_ptr<Command> m_keyDownCommand;
	std::shared_ptr<Command> m_keyAttackCommand;
	std::shared_ptr<Command> m_doNothingCommand;

private:
	static const int WALK_ACCELERATION = 1;
};

#endif
