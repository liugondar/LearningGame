#include "GameObjectManger.h"

GameObjectManger* GameObjectManger::instance = nullptr;

void GameObjectManger::init(Mario * mario)
{
	this->mario = mario;
}

void GameObjectManger::render()
{
	this->mario->render();
}

void GameObjectManger::update(DWORD dt)
{
	mario->update(dt);
}
