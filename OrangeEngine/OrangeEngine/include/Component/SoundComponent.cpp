#include "SoundComponent.h"
#include "../Manager/AssetManager.h"

SoundComponent::SoundComponent(GameObject& obj, int soundID) :
	BaseComponent(obj),
	m_sound(AssetManager::GetSoundBuffer(soundID))
{
	componentName = "SoundComponent";
	m_sound.setMinDistance(80.0f);
	m_sound.setAttenuation(10.0f);
}

SoundComponent::SoundComponent(GameObject& obj, sf::SoundBuffer& soundBuffer) :
	BaseComponent(obj),
	m_sound(soundBuffer)
{
	m_sound.setMinDistance(80.0f);
	m_sound.setAttenuation(10.0f);
}

void SoundComponent::Update(float timeDelta) {
	if (!IsActive()) return;

	if (m_gameObject.GetPhysicsComponent() == nullptr) return;
	sf::Vector2f pos = m_gameObject.GetPhysicsComponent()->GetPosition();
	m_sound.setPosition(pos.x, 0, pos.y);
}

void SoundComponent::AddSound(int soundID) {
	m_sound.setBuffer(AssetManager::GetSoundBuffer(soundID));
}

void SoundComponent::AddSound(sf::SoundBuffer& soundBuffer) {
	m_sound.setBuffer(soundBuffer);
}

void SoundComponent::PlaySound() {
	m_sound.play();
}

void SoundComponent::SetSoundLooping(bool loop) {
	m_sound.setLoop(loop);
	if (loop) m_sound.play();
}