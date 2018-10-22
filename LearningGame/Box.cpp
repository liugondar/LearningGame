#include "Box.h"

Box::Box()
{
	x = y = width = height = vx = vy = 0.f;
}

Box::Box(float x, float y, float w, float h)
{
	this->x = x;
	this->y = y;
	width = w;
	height = h;
	vx = 0.f;
	vy = 0.f;
}
