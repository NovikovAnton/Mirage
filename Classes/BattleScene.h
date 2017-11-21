#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

enum class UnitState {
	Running,
	Attacking,
	Dead
};

class BattleScene;

class Unit {
public:
	Sprite* sprite;
	int hp;
	int damage;
	int defense;
	UnitState state;

	virtual void AddToBattleScene(BattleScene * scene) = 0;
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

	void unit_select_callback(int i);
	
	void unit2_select_callback();

	void unit3_select_callback();

	void unit4_select_callback();

	void unit5_select_callback();

	void unit6_select_callback();

	void unit7_select_callback();

	void unit8_select_callback();

	void unit9_select_callback();

	void unit10_select_callback();

private:
	CC_SYNTHESIZE(cocos2d::ProgressTimer*, hpView, HPView);
	CC_SYNTHESIZE(int, score, Score)
		CC_SYNTHESIZE(cocos2d::LabelAtlas*, scoreLabel, ScoreLabel);
	void increaseScore(float dt);
	void ShowGameOver(Ref* pObj);

	void updateGame(float dt);

	ui::Button * button_unit1;
	ui::Button * button_unit2;
	ui::Button * button_unit3;
	ui::Button * button_unit4;
	ui::Button * button_unit5;
	MenuItemSprite * unit6_menu;
	MenuItemSprite * unit7_menu;
	MenuItemSprite * unit8_menu;
	MenuItemSprite * unit9_menu;
	MenuItemSprite * unit10_menu;

	std::vector<Unit*> units_player;
	std::vector<Unit*> units_computer;

};


class Unit1 : public Unit {
public:
	Unit1() {
		hp = 100;
		damage = 20;
		defense = 5;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("unit1_norma.png");
		sprite->setPosition(Vec2(45, 100));
		sprite->setScale(0.5);
		scene->addChild(sprite);

		scene->AddUnit(this);

		auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
		sprite->runAction(moveBy1);
	}
};

class TowerPlayer : public Unit {
public:
	TowerPlayer() {
		hp = 1000;
		damage = 0;
		defense = 10;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("Tower1.png");
		sprite->setPosition(Vec2(32, 110));
		sprite->setScale(0.15);
		scene->addChild(sprite);
		scene->AddUnit(this);
	}
};

class TowerComputer : public Unit {
public:
	TowerComputer() {
		hp = 1000;
		damage = 0;
		defense = 10;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("Tower2.png");
		sprite->setPosition(Vec2(450, 110));
		sprite->setScale(0.15);
		scene->addChild(sprite);
		scene->AddUnit(this);
	}
};


//void unit1_select(Ref* sender, ui::Widget::TouchEventType type);
