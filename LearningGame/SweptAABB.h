#pragma once
#include <math.h>
#include <limits>
#include <iostream>
#include <algorithm>

#include "eDirection.h"
#include "Box.h"

bool isColliding(const Box& object, const Box& other);
Box getSweptBroadphaseRect(const Box& object,float dx,float dy);
void findCollisonAndExittime(float& txEntry, float& tyEntry,
	float& txExit, float& tyExit,
	float dxEntry, float dxExit,
	float dyEntry, float dyExit,
	Box movingObject, Box StandingObject
);

void sweptAABB(
	Box movingObject, Box standingObject,
	float dx, float dy,
	float &t, float &nx, float &ny);