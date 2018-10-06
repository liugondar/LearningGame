#pragma once
#include "Game.h"
#include "AnimationManager.h"
using namespace std;

#define FACE_TO_RIGHT 1
#define FACE_TO_LEFT -1

class GameObject
{
protected:
	float x;
	float y;
	float vx;
	float vy;
	int faceSide;

	int currentState;
	static unordered_map<int ,Animation*> animations;

	LPDIRECT3DTEXTURE9 texture;

public:
	GameObject() {
		x = y = 0;
		vx = vy = 0;
		faceSide= FACE_TO_RIGHT; // right side
	}
	~GameObject();

	void setPosition(float x, float y) { this->x = x; this->y = y; }
	void setState(int state) { this->currentState = state; }
	int getState() { return currentState; }

	static void addAnimation(int animationId);
	void update(DWORD dt);
	void render();
};

