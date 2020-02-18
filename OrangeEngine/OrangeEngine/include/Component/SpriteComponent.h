#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_HPP

#include "BaseComponent.h"

class SpriteComponent : public BaseComponent {
public:
	SpriteComponent(ComponentManager& obj);

	void Update(float timeDelta);
};

#endif // !SPRITECOMPONENT_H
