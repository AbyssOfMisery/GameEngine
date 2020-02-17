#ifndef InputComponent_h
#define InputComponent_h

#include <map>

#include "../Utility/Enums.h"
#include "../Manager/ComponentManager.h"
#include "../Component/Command.h"


class ComponentManager;
class Command;

class InputComponent {

public:

	InputComponent();
	~InputComponent() {};

	void BindKey(KEY key, sf::Keyboard::Key keyToBind);
	void Update(ComponentManager& obj);

protected:
	// Default key bindings
	std::map<KEY, sf::Keyboard::Key> m_keyMappings;

	std::shared_ptr<Command> m_keyLeftCommand;
	std::shared_ptr<Command> m_keyRightCommand;
	std::shared_ptr<Command> m_keyUpCommand;
	std::shared_ptr<Command> m_keyDownCommand;
	std::shared_ptr<Command> m_keyAttackCommand;

private:
	static const int WALK_ACCELERATION = 1;
};

#endif
