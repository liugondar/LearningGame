#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(LPCWSTR texturePath)
{
	x = y = 0;

	D3DXIMAGE_INFO imageInfo;
	auto result = D3DXGetImageInfoFromFile(texturePath, &imageInfo);
	if (result !=  D3D_OK) {
		return;
	}
	

	LPDIRECT3DDEVICE9 d3ddv = Game::getInstance()->getDirect3DDevice();

	result = D3DXCreateTextureFromFileEx(
		d3ddv,								// Pointer to Direct3D device object
		texturePath,						// Path to the image to load
		imageInfo.Width,							// Texture width
		imageInfo.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255),			// Transparent color
		&imageInfo,
		NULL,
		&texture);								// Created texture pointer

	if (result != D3D_OK)
	{
		OutputDebugString(L"[ERROR] CreateTextureFromFile failed\n");
		return;
	}

}


GameObject::~GameObject()
{
	if (texture != NULL) texture->Release();
}

void GameObject::update(DWORD dt)
{
}

void GameObject::render()
{
	Game::getInstance()->draw(x, y, texture);
}
