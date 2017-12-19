#pragma once
#include "Unit.h"
#include <random>

class BattleScene;

class AI
{
public:
	BattleScene* bs;

	virtual void ReactPlayerUnitSelect(UnitID id) = 0;

};

class RandomAI : public AI
{
public:
	std::uniform_int_distribution<> RandomGen;
	virtual void ReactPlayerUnitSelect(UnitID id) = 0;

	RandomAI() : RandomGen(1, 100), gen(rd()) {};
	std::random_device rd;
	std::mt19937 gen;
};

class EasyRandomAI : public RandomAI
{
public:
	virtual void ReactPlayerUnitSelect(UnitID id);
};

class HardRandomAI : public RandomAI
{
public:
	virtual void ReactPlayerUnitSelect(UnitID id);
};