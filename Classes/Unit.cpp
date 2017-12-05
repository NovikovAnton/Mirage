#include "Unit.h"
#include "BattleScene.h"

void Unit::ReceiveAttackFromUnit(Unit * enemy)
{
	int d;
	if (enemy->damage > this->defense)
		d = enemy->damage - this->defense;
	else
		d = 0;

	this->hp = this->hp - d;
	this->UpdateState();
}

void Unit::UpdateState()
{
	if (this->hp <= 0)
		this->state = UnitState::Dead;
}

void Unit1::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("unit1_norma.png");
	sprite->setPosition(Vec2(45, 100));
	sprite->setScale(0.5);
	scene->addChild(sprite);

	scene->AddUnit(this);

	auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
	sprite->runAction(moveBy1);
}

void Unit2::AddToBattleScene(BattleScene * scene)
{
		sprite = Sprite::create("unit2_norma.png");
		sprite->setPosition(Vec2(45, 100));
		sprite->setScale(0.5);
		scene->addChild(sprite);

		scene->AddUnit(this);

		auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
		sprite->runAction(moveBy1);
}

void Unit3::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("unit3_norma.png");
	sprite->setPosition(Vec2(45, 100));
	sprite->setScale(0.5);
	scene->addChild(sprite);

	scene->AddUnit(this);

	auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
	sprite->runAction(moveBy1);
}

void Unit4::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("unit4_norma.png");
	sprite->setPosition(Vec2(45, 100));
	sprite->setScale(0.5);
	scene->addChild(sprite);

	scene->AddUnit(this);

	auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
	sprite->runAction(moveBy1);
}

void Unit5::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("unit5_norma.png");
	sprite->setPosition(Vec2(45, 100));
	sprite->setScale(0.5);
	scene->addChild(sprite);

	scene->AddUnit(this);

	auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
	sprite->runAction(moveBy1);
}

void Unit6::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("unit6_norma.png");
	sprite->setPosition(Vec2(450, 100));
	sprite->setScale(0.5);
	scene->addChild(sprite);

	scene->AddUnit(this);

	auto moveBy1 = MoveBy::create(4, Vec2(-400, 0));
	sprite->runAction(moveBy1);
}

void Unit7::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("unit7_norma.png");
	sprite->setPosition(Vec2(45, 100));
	sprite->setScale(0.5);
	scene->addChild(sprite);

	scene->AddUnit(this);

	auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
	sprite->runAction(moveBy1);
}

void Unit8::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("unit8_norma.png");
	sprite->setPosition(Vec2(45, 100));
	sprite->setScale(0.5);
	scene->addChild(sprite);

	scene->AddUnit(this);

	auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
	sprite->runAction(moveBy1);
}

void Unit9::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("unit9_norma.png");
	sprite->setPosition(Vec2(45, 100));
	sprite->setScale(0.5);
	scene->addChild(sprite);

	scene->AddUnit(this);

	auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
	sprite->runAction(moveBy1);
}

void Unit10::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("unit10_norma.png");
	sprite->setPosition(Vec2(45, 100));
	sprite->setScale(0.5);
	scene->addChild(sprite);

	scene->AddUnit(this);

	auto moveBy1 = MoveBy::create(4, Vec2(400, 0));
	sprite->runAction(moveBy1);
}

void TowerPlayer::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("Tower1.png");
	sprite->setPosition(Vec2(32, 110));
	sprite->setScale(0.15);
	scene->addChild(sprite);
	scene->AddUnit(this);
}

void TowerComputer::AddToBattleScene(BattleScene * scene)
{
	sprite = Sprite::create("Tower2.png");
	sprite->setPosition(Vec2(450, 110));
	sprite->setScale(0.15);
	scene->addChild(sprite);
	scene->AddUnit(this);
}


