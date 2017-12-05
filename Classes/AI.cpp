#include "AI.h"
#include "BattleScene.h"

void AI::ReactPlayerUnitSelect(UnitID id)
{
	Unit* unit = nullptr;

	//if (id==UnitID::ID1)
	  unit = new Unit6();

	unit->AddToBattleScene(bs);
}
