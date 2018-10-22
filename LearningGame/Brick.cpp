#include "Brick.h"


Brick::Brick()
{
}


Brick::~Brick()
{
}

void Brick::render()
{
	RenderBoundingBox();
	animations[ANIMATION_BRICK_IDLE]->render(x, y);
}

Box Brick::getBoundingBox()
{
	auto box = Box();
	box.x = x;
	box.y = y;
	box.width = x + BRICK_BBOX_WIDTH;
	box.height = y + BRICK_BBOX_HEIGHT;
	return box;
}
