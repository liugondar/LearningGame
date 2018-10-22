#include "GameObjectManger.h"

GameObjectManger* GameObjectManger::instance = nullptr;

void GameObjectManger::init(Mario * mario)
{
	this->mario = mario;
}

void GameObjectManger::render()
{
	this->mario->render();
	for (int i = 0; i < bricks.size(); i++)
	{
		bricks[i]->render();
	}
}

void GameObjectManger::update(DWORD dt)
{
	this->mario->update(dt,&bricks);
}
