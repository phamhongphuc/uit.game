﻿#pragma once
#include "Game.h"
#include "Scene_Final/Scene_AgrabahMarket.h"
#include "Scene_Final/Scene_JafarPalace.h"
#include "Scene_Final/Scene_Death.h"

Game::Game() {
	mDevice = GameGlobal::GetDevice();

	//# Game Start
	Scene::ReplaceScene(
		new Scene_AgrabahMarket()
		// new Scene_JafarPalace()
	);
	InitLoop();
}
Game::~Game() {}

void Game::InitLoop() {
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
				(DWORD)((timePerFrame - delay)) // milisecond 
				// ở đây là đang truyền vào theo đơn vị giây (không đúng)

				// Do bị dôi ra một khoảng thời gian sau khi thực hiện hàm GameRender
				// ở phía trên nên đoạn này nó cần sleep ít hơn thực tế 1 chút
				// Nếu để sleep lỗi như này thì trong 1 vòng nó sẽ sleep nhiều khoảng rất nhỏ 
				// (khoảng 1000 lần)
				// (DWORD)((timePerFrame - delay) * 1000) // milisecond

				// Edit: không hiểu tại sao khi dùng hàm đếm thì 
				// nó chỉ chạy thằng này theo đơn vị giây thôi mà 
				// Không chạy theo đơn vị ms
			);
			delay = timePerFrame;
		}
	}
}

//# Được gọi bên trong vòng lặp
void Game::GameRender(float delay) {
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
	Scene::mScene->SceneRender(delay);

	// End
	mSpriteHandler->End();
	mDevice->EndScene();
	mDevice->Present(0, 0, 0, 0);
}

//{
//	DWORD AlphaValue = D3DCOLOR_ARGB(50, 255, 255, 255);
//
//	mDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
//	mDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
//	mDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
//	mDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
//	mDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
//	mDevice->SetTextureStageState(0, D3DTSS_CONSTANT, AlphaValue);
//	mDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CONSTANT);
//	mDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
//	mDevice->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
//}