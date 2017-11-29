﻿#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include "Object_Vector2.h"

class Object;

class Object_Transform: public D3DXMATRIX {
private:
	bool mFlip;	// Flip
public:
	Object_Transform();

	// Lấy thông tin Transform từ
	// + Json
	// + Position
	void Update(Object * pObject);
	void SetFlip(bool pFlip);
};