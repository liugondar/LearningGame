#include "SweptAABB.h"

bool isColliding(const Box& object, const Box& other)
{
	auto notCollision = (object.width< other.x || object.x> other.width ||
		object.height< other.y || object.y> other.height);

	float left = object.width - other.x;
	float top = object.x - other.width;
	float right = object.height - other.y;
	float bottom = object.y - other.height;

	return !notCollision;
}

Box getSweptBroadphaseRect(const Box& object,float dx,float dy)
{
	float x = dx > 0 ? object.x : dx + object.vx;
	float y = dy > 0 ? object.y :dy + object.vy;
	float w = dx > 0 ? object.width + dx : object.width;
	float h = dy > 0 ? object.height +dy : object.height;
	return Box(x,y,w,h);
}

void findDistance(float& dxEntry, float& dyEntry,
	float& dxExit, float& dyExit,
	float dx, float dy,
	Box movingObject,
	Box standingObject)
{
	auto ml = movingObject.x, mt = movingObject.y, mr = movingObject.width, mb = movingObject.height;
	auto sl = standingObject.x, st = standingObject.y, sr = standingObject.width, sb = standingObject.height;

	if (dx > 0)
	{
		dxEntry = sl - mr;
		dxExit = sr - ml;
	}
	else if (dx < 0)
	{
		dxEntry = sr - ml;
		dxExit = sl - mr;
	}


	if (dy > 0)
	{
		dyEntry = st - mb;
		dyExit = sb - mt;
	}
	else if (dy < 0)
	{
		dyEntry = sb - mt;
		dyExit = st - mb;
	}
}

void findCollisonAndExittime(float& txEntry, float& tyEntry,
	float& txExit, float& tyExit,
	float dxEntry, float dxExit,
	float dyEntry, float dyExit,
	float dx, float dy
)
{
	if (dx == 0)
	{
		txEntry = -99999999999;
		txExit = 99999999999;
	}
	else
	{
		txEntry = dxEntry / dx;
		txExit = dxExit / dx;
	}

	if (dy == 0)
	{
		tyEntry = -99999999999;
		tyExit = 99999999999;
	}
	else
	{
		tyEntry = dyEntry / dy;
		tyExit = dyExit / dy;
	}

}

void sweptAABB(
	Box movingObject, Box standingObject,
	float dx, float dy,
	float &t, float &nx, float &ny)
{
	auto ml = movingObject.x, mt = movingObject.y, mr = movingObject.width, mb = movingObject.height;
	auto sl = standingObject.x, st = standingObject.y, sr = standingObject.width, sb = standingObject.height;

	float dxEntry, dxExit, txEntry, txExit;
	float dyEntry, dyExit, tyEntry, tyExit;

	float entryTime;
	float exitTime;

	t = -1.0f;			// no collision
	nx = ny = 0;
	auto box = getSweptBroadphaseRect(movingObject, dx, dy);
	if (!isColliding(box, standingObject)) return ;

	if (dx == 0 && dy == 0) return;		// moving object is not moving > obvious no collision

	findDistance(dxEntry, dyEntry, dxExit, dyExit, dx,dy,movingObject, standingObject);
	findCollisonAndExittime(txEntry, tyEntry, txExit, tyExit, dxEntry, dxExit, dyEntry, dyExit, dx, dy);

	// get final entry time and exit time
	entryTime = std::max(txEntry, tyEntry);
	exitTime = std::min(txExit, tyExit);

	bool notCollision = (entryTime > exitTime
		|| (txEntry < 0.0f && tyEntry < 0.0f)
		|| txEntry > 1.0f
		|| tyEntry > 1.0f
		);
	if (notCollision) return ;

	// time collison = entry time
	t = entryTime;

	// find direction result
	if (txEntry > tyEntry)
	{
		ny = 0.0f;
		dx > 0 ? nx = -1.0f : nx = 1.0f;
	}
	else
	{
		nx = 0.0f;
		dy > 0 ? ny = -1.0f : ny = 1.0f;
	}

}