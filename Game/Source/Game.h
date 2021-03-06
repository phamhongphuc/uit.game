﻿#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include "GameTime.h"
#include "GameGlobal.h"
#include "Scene/Scene.h"
#include "../Define.h"

class Game {
public:
	Game();
	~Game();
protected:
	LPDIRECT3DDEVICE9	mDevice;

	//khởi tạo vòng lặp game
	//đc gọi khi khởi tạo đối tượng game
	void InitLoop();

	//hàm update của game
	void GameRender(float dt);
};
