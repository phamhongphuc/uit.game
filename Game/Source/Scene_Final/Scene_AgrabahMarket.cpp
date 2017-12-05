﻿#include "Scene_AgrabahMarket.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"
#include "../Object_Map_Block/Object_Map_Block.h"

#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../../Define.h"

Scene_AgrabahMarket::Scene_AgrabahMarket() {
	mMapBlock = new Object_Map_Block("AgrabahMarket_Block");

	// Add Object
	Add("1", new Object_Map_AgrabahMarket_Back());
	Add("5", new Object_Unit_Aladdin());

	Add("9", new Object_Map_AgrabahMarket_Front());
}