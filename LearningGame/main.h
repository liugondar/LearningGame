#pragma once
#include "Game.h"
#include "KeyboardHandler.h"

#include "GameObject.h"
#include "Mario.h"

#include "AnimationManager.h"
#include "TextureManager.h"
#include "SpriteManager.h"

#include "TextureContanst.h"
#include "mainConstants.h"
#include "SpriteConstants.h"
#include "AnimationConstants.h"

HWND createGameWindow(HINSTANCE hInstance, int nCmdShow,
	int screenWidth, int screenHeight);
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int run();
void loadResources();
void update(DWORD dt);
void render();


class SampleKeyHander : public KeyboardHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};
