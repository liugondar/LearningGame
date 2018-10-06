#include "Mario.h"

void Mario::update(DWORD dt)
{
	GameObject::update(dt);

	// simple fall down
	vy += MARIO_GRAVITY;
	if (y > 100)
	{
		vy = 0; y = 100.0f;
	}

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
}

void Mario::render()
{
	int animationId;
	// vc==0 => mario is idle
	if (vx == 0) {
		if (faceSide > 0) animationId = ANIMATION_MARIO_IDLE_RIGHT;
		else animationId = ANIMATION_MARIO_IDLE_LEFT;
	}
	else if (vx > 0) {
		animationId = ANIMATION_MARIO_FACE_RIGHT;
	}
	else
	{
		animationId = ANIMATION_MARIO_FACE_LEFT;
	}
	animations[animationId]->render(x, y);
}

void Mario::setState(int state)
{
	GameObject::setState(state);
	switch (state)
	{
	case MARIO_STATE_WALKING_RIGHT:
		vx = MARIO_WALKING_SPEED;
		faceSide= FACE_TO_RIGHT;
		break;

	case MARIO_STATE_WALKING_LEFT:
		vx = -MARIO_WALKING_SPEED;
		faceSide= FACE_TO_LEFT;
		break;

	case MARIO_STATE_JUMP:
		if (y == 100)
			vy = -MARIO_JUMP_SPEED_Y;

	case MARIO_STATE_IDLE:
		vx = 0;
		break;
	}
}
