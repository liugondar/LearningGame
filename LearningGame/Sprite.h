#pragma once
#include"Game.h"

class Sprite
{
private:
	int id;
	int left;
	int top;
	int right;
	int bottom;

	LPDIRECT3DTEXTURE9 texture;
public:
	Sprite(int id, int left, int top, int right, int bottom,
		LPDIRECT3DTEXTURE9 texture);
	void draw(float x,float y);
};

