﻿#pragma once
#include "Game.h"
#include "GameGlobal.h"
#include "GameTime.h"
#include "Scene_Final\Scene_AgrabahMarket.h"

#include "../Define.h"

Game::Game()
{
	mDevice = GameGlobal::GetDevice();

	//# Game Start
	Scene::ReplaceScene(
		new Scene_AgrabahMarket()
	);
	InitLoop();
}
Game::~Game() {}

void Game::InitLoop()
{
	MSG msg;
	float
		timePerFrame = 1.f / FPS,		// Tickperframe là khoảng thời gian hiển thị của mỗi frame
		delay = 0;						// Delta chứa tổng tgian thực hiện của mỗi vòng while

	while (GameGlobal::isGameRunning) {
		GameTime::StartCounter();
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		delay += GameTime::GetCounter();
		if (delay >= timePerFrame) {
			if (delay < timePerFrame * 3) {
				GameRender(delay);
			}
			delay -= timePerFrame;
		}
		else {
			Sleep(
				(DWORD)((timePerFrame - delay) * 1000) // milisecond
			);
			delay = timePerFrame;
		}
	}
}

//# Được gọi bên trong vòng lặp
void Game::GameRender(float delay) {
	Scene        * mScene = Scene::GetCurrentScene();
	ID3DXSprite  * mSpriteHandler = GameGlobal::GetSpriteHandler();

	// Before
	mDevice->Clear(0, NULL, D3DCLEAR_TARGET, BACKGROUND_COLOR, 0.f, 0);
	mDevice->BeginScene();
	mSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	// ?
	mDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
	mDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
	mDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
	// Render
	mScene->SceneRender(delay);

	// End
	mSpriteHandler->End();
	mDevice->EndScene();
	mDevice->Present(0, 0, 0, 0);
}