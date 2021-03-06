﻿#ifndef Scene_Included
#define Scene_Included

#pragma once
#include <list>
#include "../GameDebug.h"
#include "../GameGlobal.h"
#include "../Object/Object.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../Utility/Float_Easing.h"
#include "../GameSound.h"

using namespace std;

class Object_Unit_Aladdin;
class Object_Screen;
class Scene {
private:
    static bool mIsDie;
    static float mTimer;
    static float mDelay;

protected:
    float mMapHeight, mMapWidth;
	bool mIsSound;

public:
    Scene();
    ~Scene();

    Vector mCamera;

	GameSound * mSound;
    Object_Unit_Aladdin* oPlayer;
    Scene_ObjectStore* oObjectStore;
    static Object_Screen* oTransparentScreen;

    //# Status Value
	V2 mStartPoint;
    static Object* mRestartPoint;
    static int mBlood;
    static int mApple;
    static int mSpendthese;
    static int mExtrahealth;
    static Float_Easing mScore;

    virtual void SceneRender(float pDelay);
    void SceneTranlation(float pDelay);

    void OnKeyDown(int pKeyCode);
    void OnKeyUp(int pKeyCode);
    void OnMouseDown(float pX, float pY){};

    static void NextScene(Scene* pScene);
    static Scene* mScene;
    static Scene* mNextScene;
    static Scene* mBackScene;
};

#endif  // !Scene_included