#pragma once

struct Box
{
	float x;
	float y;

	float width;
	float height;

	float vx;
	float vy;

	float dx;
	float dy;
	float dt;
	Box();
	Box(float x,float y,float w,float h);
};
