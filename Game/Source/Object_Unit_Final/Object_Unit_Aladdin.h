#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Aladdin : public Object_Unit {
public:
	Object_Unit_Aladdin();
	~Object_Unit_Aladdin() {};

	void ObjectUpdateEvent(float delay);
};