#include "GameObject.h"

unordered_map<int,Animation* > GameObject::animations;

GameObject::~GameObject()
{
	if (texture != NULL) texture->Release();
}

void GameObject::addAnimation(int animationId)
{
		auto animation = AnimationManager::getInstance()->get(animationId);
		animations[animationId] = animation;
}

void GameObject::update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void GameObject::render()
{
}
