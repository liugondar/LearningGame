#pragma once
#include "MarioConstants.h"
#include "GameObject.h"

class Mario :
	public GameObject
{
public:
	void update(DWORD dt);
	void render();
	void checkBound();

	void updateVelocity();
	void checkOutOfGround();

};

