#pragma once
#include "Level.h"
#include <GameEngine\GameEngine.h>
#include <GameEngine\Window.h>
#include <GameEngine\GLSLProgram.h>
#include <GameEngine\Camera2D.h>

class MainGame
{
public:
	MainGame();
	~MainGame();

	void Run();
	void InitSystems();
	void InitShaders();

private:
	std::vector<Level*> m_vecLevels;
	GameEngine::Window m_window;
	GameEngine::GLSLProgram	m_textureProgram;
	GameEngine::Camera2D m_camera;
	int m_iScreenWidth, m_iScreenHeight;
};