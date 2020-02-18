#include "Command.h"


void Command::Walk(ComponentManager& obj, sf::Vector2f newVelocity) {
	if (obj.GetPhysicsComponent() != nullptr) obj.GetPhysicsComponent()->SetVelocity(newVelocity);
}

void WalkLeftCommand::Execute(ComponentManager& obj) {
	Command::Walk(obj, { -WALK_ACCELERATION, 0 });
	if (obj.GetAnimatorComponent() != nullptr) obj.GetAnimatorComponent()->SetCurrentAnimation(static_cast<int>(ANIMATION_STATE::WALK_LEFT));
}

void WalkRightCommand::Execute(ComponentManager& obj) {
	Command::Walk(obj, { WALK_ACCELERATION, 0 });
	if (obj.GetAnimatorComponent() != nullptr) obj.GetAnimatorComponent()->SetCurrentAnimation(static_cast<int>(ANIMATION_STATE::WALK_RIGHT));
}

void WalkUpCommand::Execute(ComponentManager& obj) {
	Command::Walk(obj, { 0, -WALK_ACCELERATION });
	if (obj.GetAnimatorComponent() != nullptr) obj.GetAnimatorComponent()->SetCurrentAnimation(static_cast<int>(ANIMATION_STATE::WALK_UP));
}

void WalkDownCommand::Execute(ComponentManager& obj) {
	Command::Walk(obj, { 0, WALK_ACCELERATION });
	if (obj.GetAnimatorComponent() != nullptr) obj.GetAnimatorComponent()->SetCurrentAnimation(static_cast<int>(ANIMATION_STATE::WALK_DOWN));
}

void DoNothingCommand::Execute(ComponentManager& obj) {
	Command::Walk(obj, { 0, 0 });
}