#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Mario.h"
using namespace std;

class GameObjectManger
{
private:
	static GameObjectManger* instance;
	Mario* mario;
public:
	static GameObjectManger* getInstance() {
		if (instance == nullptr) instance = new GameObjectManger();
		return instance;
	}
	void init(Mario* mario);
	void render();
	void update(DWORD dt);
};

