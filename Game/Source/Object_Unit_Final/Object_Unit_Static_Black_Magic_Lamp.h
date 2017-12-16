#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Black_Magic_Lamp final : public Object_Unit {
public:
	Object_Unit_Static_Black_Magic_Lamp(RECT u);
	~Object_Unit_Static_Black_Magic_Lamp() {}
	void ObjectIntersect(Object * pObject);
	void ObjectUpdateEvent(float delay);
};

