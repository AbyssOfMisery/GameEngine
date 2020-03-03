#ifndef SOUNDCOMPONENT_H
#define SOUNDCOMPONENT_H

#include <SFML/Audio.hpp>
#include "../Actor/GameObject.h"
#include "../Component/BaseComponent.h"

class BaseComponent;

class SoundComponent : public BaseComponent {
public:
	SoundComponent(GameObject& obj, int soundID);
	SoundComponent(GameObject& obj, sf::SoundBuffer& soundBuffer);

	void Update(float timeDelta);

	void AddSound(int soundID);
	void AddSound(sf::SoundBuffer& soundBuffer);

	void PlaySound();
	void SetSoundLooping(bool loop);

private:
	sf::Sound m_sound;
};

#endif // !SOUNDCOMPONENT_H