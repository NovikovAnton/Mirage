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

enum class UnitID {
	ID1,
	ID2,
	ID3,
	ID4,
	ID5,
	ID6,
	ID7,
	ID8,
	ID9,
	ID10
};

class Unit {
public:
	Sprite* sprite;
	int hp;
	int damage;
	int defense;
	int delta_x;
	UnitState state;
	Team team;

	UnitID id;

	bool isTower;

	virtual void AddToBattleScene(BattleScene * scene) = 0;

	void ReceiveAttackFromUnit(Unit* enemy);
	void UpdateState();
};

class Unit1 : public Unit {
public:
	Unit1() {
		id = UnitID::ID1;
		hp = 100;
		damage = 20;
		defense = 5;
		delta_x = 10;
		isTower = false;
		state = UnitState::Running;
		team = Team::Player;
	};

	virtual void AddToBattleScene(BattleScene * scene);
};

class Unit2 : public Unit {
public:
	Unit2() {
		id = UnitID::ID2;
		hp = 150;
		damage = 30;	
		defense = 7;
		delta_x = 10;
		state = UnitState::Running;
		team = Team::Player;
	};

	virtual void AddToBattleScene(BattleScene * scene);
};

class Unit3 : public Unit {
public:
	Unit3() {
		id = UnitID::ID3;
		hp = 400;
		damage = 20;
		defense = 10;
		delta_x = 10;
		state = UnitState::Running;
		team = Team::Player;
	};

	virtual void AddToBattleScene(BattleScene * scene);

};

class Unit4 : public Unit {
public:
	Unit4() {
		id = UnitID::ID4;
		hp = 250;
		damage = 50;
		defense = 15;
		delta_x = 10;
		state = UnitState::Running;
		team = Team::Player;
	};

	virtual void AddToBattleScene(BattleScene * scene);

};

class Unit5 : public Unit {
public:
	Unit5() {
		id = UnitID::ID5;
		hp = 500;
		damage = 80;
		defense = 25;
		delta_x = 10;
		state = UnitState::Running;
		team = Team::Player;
	};

	virtual void AddToBattleScene(BattleScene * scene);
};

class Unit6 : public Unit {
public:
	Unit6() {
		hp = 100;
		damage = 25;
		defense = 0;
		delta_x = -10;
		state = UnitState::Running;
		team = Team::Computer;
	};

	virtual void AddToBattleScene(BattleScene * scene);
};

class Unit7 : public Unit {
public:
	Unit7() {
		hp = 100;
		damage = 50;
		defense = 3;
		delta_x = -10;
		state = UnitState::Running;
		team = Team::Computer;
	};

	virtual void AddToBattleScene(BattleScene * scene);
};

class Unit8 : public Unit {
public:
	Unit8() {
		hp = 200;
		damage = 20;
		defense = 15;
		delta_x = -10;
		state = UnitState::Running;
		team = Team::Computer;
	};

	virtual void AddToBattleScene(BattleScene * scene);
};

class Unit9 : public Unit {
public:
	Unit9() {
		hp = 500;
		damage = 20;
		defense = 25;
		delta_x = -10;
		state = UnitState::Running;
		team = Team::Computer;
	};

	virtual void AddToBattleScene(BattleScene * scene);
};

class Unit10 : public Unit {
public:
	Unit10() {
		hp = 500;
		damage = 80;
		defense = 25;
		delta_x = -10;
		state = UnitState::Running;
		team = Team::Computer;
	};

	virtual void AddToBattleScene(BattleScene * scene);
};

class TowerPlayer : public Unit {
public:
	TowerPlayer() {
		hp = 2500;
		damage = 0;
		defense = 10;
		isTower = true;
		delta_x = 0;
		state = UnitState::Running;
		team = Team::Player;
	};

	virtual void AddToBattleScene(BattleScene * scene);
};

class TowerComputer : public Unit {
public:
	TowerComputer() {
		hp = 2500;
		damage = 0;
		defense = 10;
		isTower = true;
		delta_x = 0;
		state = UnitState::Running;
		team = Team::Computer;
	};

	virtual void AddToBattleScene(BattleScene * scene);
};


//void unit1_select(Ref* sender, ui::Widget::TouchEventType type);