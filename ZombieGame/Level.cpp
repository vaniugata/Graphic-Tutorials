#include "Level.h"
#include <fstream>
#include <GameEngine/Errors.h>
#include <iostream>


Level::Level(const std::string& path)
{
	std::ifstream file;
	file.open(path);

	if(file.fail()) { GameEngine::fatalError("Failed to open " + path); }

	std::string temp;
	file >> temp >> m_iNumHumans;

	while(std::getline(file, temp))
	{
		m_vecLevelData.push_back(temp);
	}

	m_spriteBatch.begin();
	m_spriteBatch.end();
}


Level::~Level()
{
}

void Level::Draw()
{
}
