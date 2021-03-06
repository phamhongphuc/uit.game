#include "GameDebug.h"
#include "../Define.h"
int GameDebug::count = 0;

void GameDebug::Log(string input) {
	OutputDebugString(
		StringToLPCWSTR(input)
	);
}

void GameDebug::Title(float input) {
	Title(to_string(input));
}
void GameDebug::Title(int input) {
	Title(to_string(input));
}

void GameDebug::Title(RECT input) {
	Title(
		to_string(input.left) + "    " +
		to_string(input.top) + "    " +
		to_string(input.right) + "    " +
		to_string(input.bottom)
	);
}

void GameDebug::Title(string input) {
	wstring wstring;
	wstring.assign(input.begin(), input.end());
	SetWindowText(
		GameGlobal::GetHWND(),
		wstring.c_str()
	);
}

void GameDebug::TitleCount() {
	count++;
	Title(count);
}

void GameDebug::Draw(RECT pRect, D3DCOLOR pColor) {
	LPDIRECT3DDEVICE9 device = GameGlobal::GetDevice();
	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPDIRECT3DSURFACE9	  surface = NULL;;
	device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_LEFT, &backBuffer);
	device->CreateOffscreenPlainSurface(
		1, 1, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &surface, NULL
	);
	device->ColorFill(surface, NULL, pColor);

	device->StretchRect(
		surface,			// from
		NULL,				// which portion?
		backBuffer,			// to
		&pRect,				// which portion?
		D3DTEXF_NONE
	);
}

void GameDebug::DrawHL(LONG pTop, LONG pWeight, D3DCOLOR pColor) {
	Draw(RECT{
		0,
		pTop,
		WIDTH,
		pTop + pWeight
	}, pColor);
}

void GameDebug::DrawVL(LONG pLeft, LONG pWeight, D3DCOLOR pColor) {
	Draw(RECT{
		pLeft,
		0,
		pLeft + pWeight,
		HEIGHT
	}, pColor);
}