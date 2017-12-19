#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Unit.h"
#include "AI.h"

USING_NS_CC;

enum class Complexity
{
	Easy,
	Hard
};

class BattleScene : public cocos2d::Scene
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(BattleScene);

	~BattleScene();

	void AddUnit(Unit* unit);

	void setComplexity(Complexity c);

	void RemoveDeadUnit(Unit* unit);
	void unit_dead_callback(Unit* unit);

	void unit_select_callback(int i);

	AI* ai;

	void BlockPlayerUnitButtons();
	void UnBlockPlayerUnitButtons(float dt);

private:
	void GameOver(bool player_wins);

	void updateGame(float dt);

	bool UnitCanGo(Unit* unit);

	ui::Button * button_unit1;
	ui::Button * button_unit2;
	ui::Button * button_unit3;
	ui::Button * button_unit4;
	ui::Button * button_unit5;

	ui::Button * button_back_menu;

	std::vector<Unit*> units;

	Unit* player_tower;
	Unit* computer_tower;

	bool IsGameOver;

	Complexity c;
};