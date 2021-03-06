#include "Object_Unit_Static_Fire.h"
#include "Object_Unit_Fire.h"
#include "Object_Unit_Aladdin.h"

#define mAni mAnimation
#define mPos mPosition
#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Static_Fire::Object_Unit_Static_Fire(RECT u) : Object_Unit("Item") {
    mPos.x << (float)(u.left);
    mPos.y << (float)(u.top);
    mAni.Set("fire", 1);
    mAutoNextFrame = false;
    mSourceRect.Update(this);
	tUnit = tUnitDamage = RECT{
		u.left + 10,
		u.top,
		u.right - 10,
		u.bottom
	};
}

Object_Unit_Static_Fire::~Object_Unit_Static_Fire() {}

void Object_Unit_Static_Fire::ObjectUpdateEvent(float delay) {
	mIsMakeDamage = false;
    Scene::mScene->oObjectStore->Collision_Enemy_Player(this);
}

void Object_Unit_Static_Fire::ObjectIntersect(Object* pObject) {}
