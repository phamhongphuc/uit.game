#include "Object_Unit_Static_Spend_These.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Spend_These::Object_Unit_Static_Spend_These(RECT u) : Object_Unit("Item") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("spendthese_item", 1);
	mAutoNextFrame = true;
}

void Object_Unit_Static_Spend_These::ObjectUpdateEvent(float dt) {

}

void Object_Unit_Static_Spend_These::ObjectIntersect(Object * pObject)
{
	mScene->mSpendthese++;
	mScene->mScore += 150;
	mIsMarkedDelete = true;
}