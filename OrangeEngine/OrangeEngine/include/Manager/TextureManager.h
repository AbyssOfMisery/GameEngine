#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <memory>
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	/**
	 * Default constructor.
	 */
	TextureManager();

	/**
	 * Adds a texture to the manager and returns its id in the map.
	 */
	static int AddTexture(std::string filePath);

	/**
	 * Removes a texture from the manager from a given id.
	 */
	static void RemoveTexture(int textureID);

	/**
	 * Gets a texture from the texture manager from an ID.
	*/
	static sf::Texture& GetTexture(int textureId);

private:
	/**
	 * A map of each texture name with its ID.
	 */
	static std::map<std::string, std::pair<int, std::unique_ptr<sf::Texture>>> m_textures;

	/**
	 * The current key value.
	 */
	static int m_currentId;
};
#endif