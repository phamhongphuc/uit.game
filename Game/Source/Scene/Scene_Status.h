#pragma once
#include <list>
using namespace std;
class Object;
class Scene_Status : public list<Object *> {
private:
	void operator<<(Object * pObject);
public:
	Scene_Status();
	~Scene_Status() {};
	void ObjectUpdateEvent(float delay);
	void ObjectRender(float delay);
};
