﻿#pragma once
#include "Game.h"
#include "GameGlobal.h"
#include "GameTime.h"
#include "SceneManager.h"
#include "Scene_AgrabahMarket.h"

Game::Game()
{
	mFPS = GameGlobal::GetFPS();
	mBackgroundColor = GameGlobal::GetBackgroundColor();

	// Game Start
	SceneManager::GetInstance()->ReplaceScene(
		new AgrabahMarket()
	);

	InitLoop();
}
Game::~Game() {}

void Game::InitLoop()
{
	MSG msg;
	float
		tickPerFrame = 1.0f / mFPS,		// Tickperframe là khoảng thời gian hiển thị của mỗi frame
		delta = 0;						// Delta chứa tổng tgian thực hiện của mỗi vòng while

	while (GameGlobal::isGameRunning)
	{

		GameTime::GetInstance()->StartCounter();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		delta += GameTime::GetInstance()->GetCounter();

		// vòng while đã chạy tgian lâu hơn hoặc bằng fps mình yêu cầu thì thực hiện update game và render lên màn hình
		if (delta >= tickPerFrame)
		{
			Update(delta);
			delta = 0;
		}
		else // fps cao hơn lúc bth, tạm sleep lại bằng khoảng tgian nó nhanh hơn, sau đó sẽ update và render tiếp
		{
			Sleep((DWORD)((tickPerFrame - delta) * 1000));
			delta = tickPerFrame;
		}
	}
}

// Được gọi bên trong vòng lặp (bên trong hàm update)
void Game::Render() {
	LPDIRECT3DDEVICE9 device = GameGlobal::GetCurrentDevice();
	Scene * scene = SceneManager::GetInstance()->GetCurrentScene();

	device->Clear(0, NULL, D3DCLEAR_TARGET, mBackgroundColor, 0.0f, 0);
	{
		device->BeginScene();
		GameGlobal::GetSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);
		{
			// Làm cho hình ảnh sau khi scale không bị nhòe
			device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
			device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
			device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
		}
		scene->Draw();
		GameGlobal::GetSpriteHandler()->End();
		device->EndScene();
	}
	device->Present(0, 0, 0, 0);
}

// Được gọi bên trong vòng lặp
void Game::Update(float delta) {
	SceneManager::GetInstance()->GetCurrentScene()->Update(delta);
	Render();
}