#ifndef Command_h
#define Command_h

#include "../Manager/ComponentManager.h"
#include "../Component/PhysicsComponent.h"
#include "../Utility/Enums.h"

class ComponentManager;

class Command {
public:
	virtual ~Command() {}
	virtual void Execute(ComponentManager& obj) = 0;

protected:
	void Walk(ComponentManager& obj, sf::Vector2f newVelocity);
};

class AttackCommand : public Command {
	void Execute(ComponentManager& obj) {
		std::cout << "Attack Not Implemented" << std::endl;
	}
};

class WalkLeftCommand : public Command {
public:
	void Execute(ComponentManager& obj);
};

class WalkRightCommand : public Command {
public:
	void Execute(ComponentManager& obj);
};

class WalkUpCommand : public Command {
public:
	void Execute(ComponentManager& obj);
};

class WalkDownCommand : public Command {
public:
	void Execute(ComponentManager& obj);


};
class DoNothingCommand : public Command {
public:
	void Execute(ComponentManager& obj);
};

#endif // !Command_h

