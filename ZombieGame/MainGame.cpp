#include "MainGame.h"
#include <iostream>

MainGame::MainGame() :
	m_iScreenWidth(800), 
	m_iScreenHeight(600)
{

}

MainGame::~MainGame()
{
	for(int i = 0; i < m_vecLevels.size(); i++)
	{
		delete m_vecLevels[i];
		m_vecLevels[i] = nullptr;
	}
}

void MainGame::Run()
{
	m_vecLevels.push_back(new Level("Levels/level1.txt"));

}

void MainGame::InitSystems()
{
	GameEngine::init();

	m_window.create("Zombie Game", m_iScreenWidth, m_iScreenHeight, 0);

	InitShaders();

	m_vecLevels.push_back(new Level("Levels/level1.txt"));
}

void MainGame::InitShaders()
{
	m_textureProgram.compileShaders("Shaders/textureShading.vert", "Shaders/textureShading.frag");
	m_textureProgram.addAttribute("vertexPosition");
	m_textureProgram.addAttribute("vertexColor");
	m_textureProgram.addAttribute("vertexUV");
	m_textureProgram.linkShaders();
}


