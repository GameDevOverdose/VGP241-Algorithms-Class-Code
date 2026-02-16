#pragma once

#include "Texture.h"
#include "UnorderedMap.h"

class TextureManager
{
public:
	~TextureManager();

	static TextureManager& Get();

	std::size_t LoadTexture(const std::string& filePath);
	Texture& GetTexture(const std::size_t& key);

private:
	TextureManager();

	UnorderedMap<std::size_t, Texture> mTextures;
};