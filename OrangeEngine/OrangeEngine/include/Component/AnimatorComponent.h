#ifndef ANIMATORCOMPONENT_H
#define ANIMATORCOMPONENT_H

#include <map>
#include "../Utility/Util.h"
#include "../Component/AnimationComponent.h"
#include "../Component/BaseComponent.h"

class BaseComponent;
class AnimationComponent;

class AnimatorComponent : public BaseComponent {
public:
	AnimatorComponent(GameObject& obj);

	void Update(float timeDelta);

	void AddAnimation(int animationID, int textureID);
	void AddAnimation(int animationID, sf::Texture& texture);
	void AddAnimation(int animationID, std::shared_ptr<AnimationComponent> animation);

	void SetCurrentAnimation(int animationID);
	int GetCurrentAnimation();

	AnimationComponent& GetAnimation(int animationID);
private:
	// map of AnimationID -> Animation
	std::map<int, std::shared_ptr<AnimationComponent>> m_animations;
	int m_currentAnimation;
};

#endif // !ANIMATORCOMPONENT_HPP