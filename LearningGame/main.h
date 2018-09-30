#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "mainConstants.h"

HWND createGameWindow(HINSTANCE hInstance, int nCmdShow,
	int screenWidth, int screenHeight);
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int run();