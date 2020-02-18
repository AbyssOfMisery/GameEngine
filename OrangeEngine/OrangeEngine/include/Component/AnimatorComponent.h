#ifndef ANIMATORCOMPONENT_H
#define ANIMATORCOMPONENT_H

#include <map>
#include "../Utility/Util.h"
#include "../Component/AnimationComponent.h"
#include "../Component/BaseComponent.h"

class Component;
class AnimationComponent;

class AnimatorComponent : public BaseComponent {
public:
	AnimatorComponent(ComponentManager& obj);

	void Update(float timeDelta);

	void AddAnimation(int animationID, int textureID);
	void AddAnimation(int animationID, sf::Texture& texture);
	void AddAnimation(int animationID, std::shared_ptr<AnimationComponent> animation);

	void SetAnimation(int animationID);
	AnimationComponent& GetAnimation(int animationID);

private:
	// map of AnimationID -> Animation
	std::map<int, std::shared_ptr<AnimationComponent>> m_animations;
	int m_currentAnimation;
};

#endif // !ANIMATORCOMPONENT_HPP