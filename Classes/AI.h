#pragma once
#include "Unit.h"

class BattleScene;

class AI
{
public:
	BattleScene* bs;

	void ReactPlayerUnitSelect(UnitID id);

};