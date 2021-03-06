﻿#include "Scene_AgrabahMarket.h"
#include "Scene_JafarPalace.h"

#include "../../Define.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Object_Status_Final/Object_Status_Cloud.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

Scene_AgrabahMarket::Scene_AgrabahMarket() : Scene() {
	delete mBackScene;
	oStatus = new Scene_Status();
	oBackground = new Object_List();

	const vector<State_Cloud> Vector_State_Cloud = {
		Cloud1, Cloud2, Cloud3, Cloud4, Sand1, Sand2, Sand3, Sand4, Sand5 };
	for (const auto &v : Vector_State_Cloud) {
		oBackground->push_back(new Object_Status_Cloud(v));
	}
	mStartPoint = { 50, 624 };
	oObjectStore = new Scene_ObjectStore("AgrabahMarket_Block");
	oPlayer = new Object_Unit_Aladdin(mStartPoint.x, mStartPoint.y);
	oMapBack = new Object_Map_AgrabahMarket_Back();
	oMapFront = new Object_Map_AgrabahMarket_Front();

	oMapBack->AfterAddToScene();
	oMapFront->AfterAddToScene();

	((Object_Screen *)oTransparentScreen)->mAlpha = 0;
	mIsSound = false;
	mIsNext = false;
	Scene::mRestartPoint = NULL;

	mSound = new GameSound(L"Sound/OST/03_Prince Ali.wav");
}

void Scene_AgrabahMarket::SceneRender(float delay) {
	auto op = oPlayer->GetPosition();
	if (op->x() > 4720 && op->y() < 215 && !mIsNext) {
		mIsNext = true;
		Scene::NextScene(new Scene_JafarPalace());
	}
	//# Update
	Scene::mScore.Update(delay);

	oPlayer->ObjectUpdateEvent(delay);
	oObjectStore->ObjectUpdateEvent(delay);
	oTransparentScreen->ObjectUpdateEvent(delay);
	oMapBack->ObjectUpdateEvent(delay);
	oMapFront->ObjectUpdateEvent(delay);
	oStatus->ObjectUpdateEvent(delay);
	oBackground->ObjectUpdateEvent(delay);

	//# Remove item in RemoveList
	oObjectStore->ObjectRemoveMarkedDelete();

	//# Render
	oBackground->ObjectRender(delay);
	oMapBack->ObjectRender(delay);
	oObjectStore->ObjectRender(delay);
	oPlayer->ObjectRender(delay);
	oMapFront->ObjectRender(delay);
	oStatus->ObjectRender(delay);
	oTransparentScreen->ObjectRender(delay);
}