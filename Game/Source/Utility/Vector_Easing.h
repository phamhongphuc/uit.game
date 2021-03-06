﻿#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Vector.h"
#include "../../Define.h"
#include "Float_Easing.h"

class Vector_Easing {
protected:public:
	Vector_Easing() {}

	Float_Easing x, y;

	void operator+=(V2 pDelta);
	void operator-=(V2 pDelta);
	void operator=(V2 pLast);
	void operator<<(V2 pVector);

	void Update(float delay);
	V2 VECTOR2();
	Vector VECTOR();
};