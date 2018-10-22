#pragma once
#include "Game.h"
#include "Mario.h"
#include "Brick.h"
using namespace std;

class GameObjectManger
{
private:
	static GameObjectManger* instance;
	Mario* mario;
	vector<GameObject*> bricks;
public:
	static GameObjectManger* getInstance() {
		if (instance == nullptr) instance = new GameObjectManger();
		return instance;
	}
	void init(Mario* mario);
	void render();
	void update(DWORD dt);
	
	void addBrick(Brick* brick) {
		bricks.push_back(brick);
	}

	Mario* getMario() { return mario; }
	vector<GameObject*> getBricks() { return bricks; }
};

