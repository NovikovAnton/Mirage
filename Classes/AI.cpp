#include "AI.h"
#include "BattleScene.h"

#include <random>

void EasyRandomAI::ReactPlayerUnitSelect(UnitID id)
{
	int num = RandomGen(gen);

	Unit* unit = nullptr;

	if (num < 30)
		unit = new Unit6();

	if (num >= 30 && num < 55)
		unit = new Unit7();

	if (num >= 55 && num < 75)
		unit = new Unit8();

	if (num >= 75 && num < 90)
		unit = new Unit9();

	if (num >= 90 && num <= 100)
		unit = new Unit10();

	unit->AddToBattleScene(bs);
}

void HardRandomAI::ReactPlayerUnitSelect(UnitID id)
{
	int num = RandomGen(gen);

	Unit* unit = nullptr;

	if (num < 10)
		unit = new Unit6();

	if (num >= 10 && num < 25)
		unit = new Unit7();

	if (num >= 25 && num < 45)
		unit = new Unit8();

	if (num >= 45 && num < 70)
		unit = new Unit9();

	if (num >= 70 && num <= 100)
		unit = new Unit10();

	//unit->damage *= 2;
	//unit->defense *= 3;

	unit->AddToBattleScene(bs);
}
