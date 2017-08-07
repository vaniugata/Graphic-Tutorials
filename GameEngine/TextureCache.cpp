#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

namespace GameEngine
{
	TextureCache::TextureCache()
	{
	}


	TextureCache::~TextureCache()
	{
	}

	GLTexture TextureCache::getTexture(std::string texturePath)
	{
		std::map<std::string, GLTexture>::iterator mit = _textureMap.find(texturePath);

		if (mit == _textureMap.end())
		{
			GLTexture newTexture = ImageLoader::loadPNG(texturePath);
			std::pair<std::string, GLTexture> newPair(texturePath, newTexture);//Pair is needed to insert new el. in map
			_textureMap.insert(newPair);

			std::cout << "Loaded texture!\n";
			return newTexture;
		}

		std::cout << "Used Cached Texture!\n";
		return mit->second; // return the texture
	}
}