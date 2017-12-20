#pragma once
#include "../../Define.h"
#include "../Object/Object.h"
#include "../Scene/Scene.h"

class Object_Unit : public Object {
protected:
    int mHealthPoint;

public:
    Object_Unit(string pName);
    ~Object_Unit(){};

    bool mAutoNextFrame;

	virtual void ObjectUpdateEvent(float delay) {};
	virtual void ObjectIntersect(Object * pObject) {};
	virtual void ObjectGetDame(Object * pObject) {};
	void ObjectUpdateProperties(float delay);
};
