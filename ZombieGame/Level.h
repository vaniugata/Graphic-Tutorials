#pragma once
#include <string>
#include <vector>
#include <GameEngine\SpriteBatch.h>

class Level
{
public:
	Level(const std::string& path);
	~Level();

	void Draw();

private:
	std::vector<std::string> m_vecLevelData;
	int m_iNumHumans;
	GameEngine::SpriteBatch m_spriteBatch;
};

