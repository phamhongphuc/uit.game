#include "Object_Unit_Static_Genie_Bonus.h"


#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Genie_Bonus::Object_Unit_Static_Genie_Bonus(RECT u) : Object_Unit("Item") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("geniebonus", 1);
	mTimePerFrame = 0.08f;
	mAutoNextFrame = true;
}

void Object_Unit_Static_Genie_Bonus::ObjectUpdateEvent(float dt)
{
}

void Object_Unit_Static_Genie_Bonus::ObjectIntersect(Object * pObject)
{
	Scene::mScene->mScore += 250;
	Scene::mScene->AddToRemoveList(this);
}
