#include "Object_Unit_Enemy_Assassin.h"
#include "../Object_Unit_Final/Object_Unit_Jar_Copper.h"

#define mAni			mAnimation
#define mPos			mPosition
#define	mObjectStore	Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Assassin::Object_Unit_Enemy_Assassin(RECT u)
	: Object_Unit("CivilianEnemies") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top) + 22;
	mAni.Set("assassin", 1);
}

void Object_Unit_Enemy_Assassin::ObjectUpdateEvent(float dt) {
	ObjectEachState();
}

void Object_Unit_Enemy_Assassin::ObjectEachState() {
	if (mAni.GetCycleIndex() == 8) {
		Scene::mScene->oObjectStore->mLost.push_back(
			new Object_Unit_Jar_Copper(xx, yy)
		);
	}
}

void Object_Unit_Enemy_Assassin::ObjectGetDame(Object * pObject) {
	mHealthPoint--;
	if (mHealthPoint <= 0) {
		mIsMarkedDelete = true;
	}
}