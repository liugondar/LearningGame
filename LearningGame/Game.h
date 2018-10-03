#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib,"d3d9.lib") 

class Game
{
private:
	static Game* instance;
	HWND hWnd; // Window handle

	LPDIRECT3D9 d3d = NULL; // direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;// Direct 3d device object

	LPDIRECT3DSURFACE9 backBuffer = NULL; 
	LPD3DXSPRITE spriteHandler = NULL;  	// Sprite helper library to help us draw 2D image on the screen 

public:
	void init(HWND hWnd);
	void draw(float x, float y, LPDIRECT3DTEXTURE9 texture);
	static Game * getInstance() {
		if (instance == NULL) instance = new Game();
		return instance;
	};
	LPDIRECT3DDEVICE9 getDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 getBackBuffer() { return backBuffer; }
	LPD3DXSPRITE getSpriteHandler() { return this->spriteHandler; }
	~Game();
};

