﻿#pragma once
#include <list>
#include "../GameGlobal.h"
#include "../Scene/Scene_Camera.h"
#include "../Object_Map_Block/Object_Map_Block.h"

using namespace std;
class Object;

class Scene : public map<string, Object *> {
private:
	static Scene * mCurrentScene;
public:
	Scene();
	~Scene();

	Vector mCamera;
	Object_Map_Block * mMapBlock;

	void SceneRender(float delay);

	void OnKeyDown(int pKeyCode);
	void OnKeyUp(int pKeyCode);
	void OnMouseDown(float pX, float pY) {};

	void Add(string pName, Object * pObject);
	void Remove(string pName);

	static void ReplaceScene(Scene * pScene);
	static Scene * GetCurrentScene();
};