#pragma once
#include <Windows.h>
#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
class GameObject
{
protected:
	float x;
	float y;
	LPDIRECT3DTEXTURE9 texture;

public:
	GameObject();
	GameObject(LPCWSTR texturePath);
	~GameObject();

	void setPosition(float x, float y) { this->x = x; this->y = y; }
	void update(DWORD dt);
	void render();
};

