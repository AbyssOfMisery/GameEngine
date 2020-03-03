#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <vector>
#include "../Utility/Util.h"
#include "../Actor/GameObject.h"
#include "../Component/BaseComponent.h"

class BaseComponent;

class AnimationComponent : public BaseComponent {
public:
	AnimationComponent(GameObject& obj, sf::Texture& texture, int animationSpeed = ANIMATION_SPEED);

	void Update(float timeDelta);

	void AddFrame(sf::IntRect frame);

	sf::Texture& GetTexture() const;

private:
	void NextFrame();

	std::vector<sf::IntRect> m_frames;
	int m_currentFrame;
	float m_animationSpeed;
	float m_progress;
	sf::Texture& m_texure;
};

#endif // !ANIMATIONCOMPONENT_HPP