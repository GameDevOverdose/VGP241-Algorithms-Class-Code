#include "TextureManager.h"
#include "Globals.h"

TextureManager& TextureManager::Get()
{
	static TextureManager instance;
	return instance;
}

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

std::size_t TextureManager::LoadTexture(const std::string& filePath)
{
	std::size_t uniqueID = Globals::HashFunction(filePath);

	mTextures[uniqueID] = filePath;

	return uniqueID;
}

Texture& TextureManager::GetTexture(const std::size_t& key)
{
	return mTextures[key];
}