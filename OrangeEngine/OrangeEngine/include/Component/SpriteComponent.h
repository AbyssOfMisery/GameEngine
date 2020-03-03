#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <memory>
#include "../Actor/GameObject.h"
#include "BaseComponent.h"

class SpriteComponent : public BaseComponent, public sf::Drawable {
public:
	SpriteComponent(GameObject& obj);
	
	void Update(float timeDelta);

	void SetSprite(int textureID);
	void SetSprite(sf::Texture& texture);
	void SetSpriteTextureRect(sf::IntRect rect);
	sf::IntRect GetSpriteTextureRect() const;
	std::shared_ptr<sf::Sprite> GetSprite() const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::shared_ptr<sf::Sprite> m_sprite;
};

#endif // !SPRITECOMPONENT_H
