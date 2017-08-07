#include "Bullet.h"
#include <GameEngine/ResourceManager.h>



Bullet::Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifeTime): 
	_postion(pos), _direction(dir), _speed(speed), _lifeTime(lifeTime)
{
}


Bullet::~Bullet()
{
}

void Bullet::draw(GameEngine::SpriteBatch& spriteBatch)
{
	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	static GameEngine::GLTexture texture = GameEngine::ResourceManager::getTexture("Textures/JimmyJumpPack/PNG/Bullet.png");

	GameEngine::Color color(255, 255, 255, 255); //White
	
	glm::vec4 posAndSize = glm::vec4(_postion.x, _postion.y, 30, 30);

	spriteBatch.draw(posAndSize, uv, texture.id, 0.0f, color);
}

bool Bullet::update()
{
	_postion += _direction * _speed;
	_lifeTime--;
	if (_lifeTime == 0)
	{
		return true;
	}

	return false;
}
