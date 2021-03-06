﻿#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"


class Object_Unit_Knife final : public Object_Unit{
private:
	bool mFlip;
	bool mIsCollision;
public:
	Object_Unit_Knife(float x, float y, float pVelocityX, float pVelocityY, bool isFlip);
	~Object_Unit_Knife(){};
	void ObjectIntersect(Object * pObject);
	void ObjectIntersectBack(Object * pObject);
	void ObjectUpdateEvent(float dt);
};

