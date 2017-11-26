#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

enum class UnitState {
	Running,
	Attacking,
	Dead
};

enum class Team {
	Player,
	Computer
};

class BattleScene;

class Unit {
public:
	Sprite* sprite;
	int hp;
	int damage;
	int defense;
	UnitState state;
	Team team;

	virtual void AddToBattleScene(BattleScene * scene) = 0;

	void ReceiveAttackFromUnit(Unit* enemy);
	void UpdateState();
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

	void RemoveDeadUnit(Unit* unit);
	void unit_dead_callback(Unit* unit);

	void unit_select_callback(int i);

private:
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

	std::vector<Unit*> units;

	Unit* player_tower;
	Unit* computer_tower;
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

class Unit2 : public Unit {
public:
	Unit2() {
		hp = 150;
		damage = 30;
		defense = 7;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("unit2_norma.png");
		sprite->setPosition(Vec2(45, 100));
		sprite->setScale(0.5);
		scene->addChild(sprite);

		scene->AddUnit(this);

		auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
		sprite->runAction(moveBy1);
	}
};

class Unit3 : public Unit {
public:
	Unit3() {
		hp = 400;
		damage = 20;
		defense = 10;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("unit3_norma.png");
		sprite->setPosition(Vec2(45, 100));
		sprite->setScale(0.5);
		scene->addChild(sprite);

		scene->AddUnit(this);

		auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
		sprite->runAction(moveBy1);
	}
};

class Unit4 : public Unit {
public:
	Unit4() {
		hp = 250;
		damage = 50;
		defense = 15;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("unit4_norma.png");
		sprite->setPosition(Vec2(45, 100));
		sprite->setScale(0.5);
		scene->addChild(sprite);

		scene->AddUnit(this);

		auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
		sprite->runAction(moveBy1);
	}
};

class Unit5 : public Unit {
public:
	Unit5() {
		hp = 500;
		damage = 80;
		defense = 25;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("unit5_norma.png");
		sprite->setPosition(Vec2(45, 100));
		sprite->setScale(0.5);
		scene->addChild(sprite);

		scene->AddUnit(this);

		auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
		sprite->runAction(moveBy1);
	}
};

class Unit6 : public Unit {
public:
	Unit6() {
		hp = 100;
		damage = 25;
		defense = 0;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("unit6_norma.png");
		sprite->setPosition(Vec2(45, 100));
		sprite->setScale(0.5);
		scene->addChild(sprite);

		scene->AddUnit(this);

		auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
		sprite->runAction(moveBy1);
	}
};

class Unit7 : public Unit {
public:
	Unit7() {
		hp = 100;
		damage = 50;
		defense = 3;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("unit7_norma.png");
		sprite->setPosition(Vec2(45, 100));
		sprite->setScale(0.5);
		scene->addChild(sprite);

		scene->AddUnit(this);

		auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
		sprite->runAction(moveBy1);
	}
};

class Unit8 : public Unit {
public:
	Unit8() {
		hp = 200;
		damage = 20;
		defense = 15;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("unit8_norma.png");
		sprite->setPosition(Vec2(45, 100));
		sprite->setScale(0.5);
		scene->addChild(sprite);

		scene->AddUnit(this);

		auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
		sprite->runAction(moveBy1);
	}
};

class Unit9 : public Unit {
public:
	Unit9() {
		hp = 500;
		damage = 20;
		defense = 25;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("unit9_norma.png");
		sprite->setPosition(Vec2(45, 100));
		sprite->setScale(0.5);
		scene->addChild(sprite);

		scene->AddUnit(this);

		auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
		sprite->runAction(moveBy1);
	}
};

class Unit10 : public Unit {
public:
	Unit10() {
		hp = 500;
		damage = 80;
		defense = 25;
		state = UnitState::Running;
	};

	virtual void AddToBattleScene(BattleScene * scene)
	{
		sprite = Sprite::create("unit10_norma.png");
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
		hp = 2500;
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
		hp = 2500;
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
