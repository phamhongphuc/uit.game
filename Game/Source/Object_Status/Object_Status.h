#pragma once
#include "../../Define.h"
#include "../Object/Object.h"
#include "../Scene/Scene.h"

class Object_Status : public Object {
public:
	bool mAutoNextFrame = false;
	Object_Status(string pName);
	~Object_Status() {};

	virtual void ObjectUpdateEvent(float delay) {};
	void ObjectUpdateProperties(float delay);
};
