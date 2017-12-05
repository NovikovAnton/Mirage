#include "AI.h"
#include "BattleScene.h"

#include <random>

void RandomAI::ReactPlayerUnitSelect(UnitID id)
{
	int num = RandomGen(gen);

	Unit* unit = nullptr;

	if (num < 30)
		unit = new Unit6();

	if (num >= 30 && num < 50)
		unit = new Unit7();

	if (num>=50)
		unit = new Unit8();

	unit->AddToBattleScene(bs);
}

void HardAI::ReactPlayerUnitSelect(UnitID id)
{
}
