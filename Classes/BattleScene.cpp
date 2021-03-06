#include "ui/CocosGUI.h"

#include "BattleScene.h"
#include "SimpleAudioEngine.h"

#include <string>

USING_NS_CC;

BattleScene::~BattleScene()
{
	//NotificationCenter::getInstance()->destroyInstance();
	delete ai;
}

void BattleScene::AddUnit(Unit * unit)
{
	units.push_back(unit);
}

void BattleScene::setComplexity(Complexity c)
{
	this->c = c;
	std::string s;

	if (c == Complexity::Easy)
	{
		ai = new EasyRandomAI;
		s = "Easy";
	}
	if (c == Complexity::Hard){
		ai = new HardRandomAI;
		s = "Hard";
    }

	ai->bs = this;



	auto label1 = Label::createWithTTF(s, "fonts/Marker Felt.ttf", 10);
	label1->setColor(Color3B::ORANGE);
	if (label1 == nullptr)
	{
		//problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// ������������� ��������� �������
		label1->setPosition(Vec2(270, 276));

		// add the label as a child to this layer
		this->addChild(label1);
	}
}

void BattleScene::RemoveDeadUnit(Unit * unit)
{
	//unit->sprite->runAction(Sequence::create(
	//	/*RotateTo::create(0.1f, 45, -45),*/
	//	ScaleTo::create(0.1f, 1.1f),
	//	CallFunc::create(CC_CALLBACK_0(BattleScene::unit_select_callback, this, 3)), NULL));
	unit_dead_callback(unit);
}

void BattleScene::unit_dead_callback(Unit* unit)
{
	this->removeChild(unit->sprite, true);
	for (int i = 0; i < units.size(); ++i)
		if (units[i] == unit) 
		{
			units.erase(units.begin() +i);
			return;
		}
}


static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartMenuScene.cpp\n");
}

Scene* BattleScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = BattleScene::create();
	layer->setTag(100);
	// add layer as a child to scene
	scene->addChild(layer, 2);

	// add warning layer
	auto warningLayer = LayerColor::create(Color4B(255, 0, 0, 60));
	warningLayer->setOpacity(0);
	warningLayer->setTag(456);
	scene->addChild(warningLayer, 7);


	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool BattleScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	IsGameOver = false;

//	ai = new EasyRandomAI;
//	ai->bs = this;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// ������������� ��� ��� ������ �����
	auto sprite = Sprite::create("Battle.png");	
	if (sprite == nullptr)
	{
		problemLoading("'Battle.png'");
	}
	else
	{
		// ������������� ����� ��������� ������� ��������, ���������� ���������� ����� ����
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite);
	}
	/////////////////////////////////////////////////////////


	button_back_menu = ui::Button::create("back_norma.png", "back_pres.png");
	button_back_menu->setPosition(Vec2(210, 280));
	button_back_menu->setScale(0.3);
	button_back_menu->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
		{
			Director::getInstance()->popScene();
		}
	}
);

	this->addChild(button_back_menu);


	// �������� ������� "Battle"

	auto label1 = Label::createWithTTF("Battle", "fonts/Marker Felt.ttf", 14);
	label1->setColor(Color3B::BLACK);
	if (label1 == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// ������������� ��������� �������
		label1->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label1->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label1);
	}


	// �������� ������� "������� �������"
	auto label2 = Label::createWithTTF("Red team", "fonts/Marker Felt.ttf", 14);
	label2->setColor(Color3B::RED);
	if (label2 == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// ������������� ��������� �������
		label2->setPosition(Vec2(origin.x + 30, origin.y + 255));

		// add the label as a child to this layer
		this->addChild(label2);
	}


	// �������� ������� "����� �������"
	auto label3 = Label::createWithTTF("Blue team", "fonts/Marker Felt.ttf", 14);
	label3->setColor(Color3B::BLUE);
	if (label3 == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label3->setPosition(Vec2(origin.x + 450, origin.y + 255));

		// add the label as a child to this layer
		this->addChild(label3);
	}



	// ���������� ����� �1
	player_tower = new TowerPlayer();
	player_tower->AddToBattleScene(this);
	player_tower->team = Team::Player;

	// ���������� ����� �2 
	computer_tower = new TowerComputer();
	computer_tower->AddToBattleScene(this);
	computer_tower->team = Team::Computer;

	//************* �������� ������ ��� unit1  ***********
	auto unit1_normal = Sprite::create("unit1_norma.png");
	if (unit1_normal == nullptr )
	{
		problemLoading("'start_normal or start_pressed.png'");
	}

	button_unit1 = ui::Button::create("unit1_norma.png");
	button_unit1->setScale(0.5);
	button_unit1->setPosition(Vec2(origin.x + 15, origin.y + 15));

	button_unit1->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
		{
			button_unit1->runAction(Sequence::create(
				CallFunc::create(CC_CALLBACK_0(BattleScene::unit_select_callback, this, 1)), NULL));
		}
	});

	this->addChild(button_unit1);

	//************* �������� ������ ��� unit2 ***********

	auto unit2_normal = Sprite::create("unit2_norma.png");
	if (unit2_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}

	button_unit2 = ui::Button::create("unit2_norma.png");
	button_unit2->setScale(0.5);
	button_unit2->setPosition(Vec2(origin.x + 60, origin.y + 15));

	button_unit2->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
		{
			button_unit2->runAction(Sequence::create(
				CallFunc::create(CC_CALLBACK_0(BattleScene::unit_select_callback, this, 2)), NULL));
		}
	});

	this->addChild(button_unit2);

	
	//************* �������� ������ ��� unit3 ***********
	auto unit3_normal = Sprite::create("unit3_norma.png");
	if (unit3_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}

	button_unit3 = ui::Button::create("unit3_norma.png");
	button_unit3->setScale(0.5);
	button_unit3->setPosition(Vec2(origin.x + 105, origin.y + 15));

	button_unit3->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
		{
			button_unit3->runAction(Sequence::create(
				CallFunc::create(CC_CALLBACK_0(BattleScene::unit_select_callback, this, 3)), NULL));
		}
	});

	this->addChild(button_unit3);


	//************* �������� ������ ��� unit4 ***********
	auto unit4_normal = Sprite::create("unit4_norma.png");
	if (unit4_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}

	button_unit4 = ui::Button::create("unit4_norma.png");
	button_unit4->setScale(0.5);
	button_unit4->setPosition(Vec2(origin.x + 150, origin.y + 15));

	button_unit4->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
		{
			button_unit4->runAction(Sequence::create(
				CallFunc::create(CC_CALLBACK_0(BattleScene::unit_select_callback, this, 4)), NULL));
		}
	});

	this->addChild(button_unit4);



	////************* �������� ������ ��� unit5 ***********
	auto unit5_normal = Sprite::create("unit5_norma.png");
	if (unit5_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}

	button_unit5 = ui::Button::create("unit5_norma.png");
	button_unit5->setScale(0.5);
	button_unit5->setPosition(Vec2(origin.x + 195, origin.y + 15));

	button_unit5->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
		{
			button_unit5->runAction(Sequence::create(
				CallFunc::create(CC_CALLBACK_0(BattleScene::unit_select_callback, this, 5)), NULL));
		}
	});

	this->addChild(button_unit5);

	////************* adds unit6 button ***********
	auto unit6_normal = Sprite::create("unit6_norma.png");
	if (unit6_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}
	auto unit6_menu = Sprite::create("unit6_norma.png");
	unit6_menu->setPosition(Vec2(origin.x + 285, origin.y + 20));
	unit6_menu->setScale(0.5);
	addChild(unit6_menu);

	////************* adds unit7 button ***********
	auto unit7_normal = Sprite::create("unit7_norma.png");
	if (unit7_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}
	auto unit7_menu = Sprite::create("unit7_norma.png");
	unit7_menu->setPosition(Vec2(origin.x + 325, origin.y + 17));
	unit7_menu->setScale(0.62);
	addChild(unit7_menu);

	////************* adds unit8 button ***********
	auto unit8_normal = Sprite::create("unit8_norma.png");
	if (unit8_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}
	auto unit8_menu = Sprite::create("unit8_norma.png");
	unit8_menu->setPosition(Vec2(origin.x + 365, origin.y + 20));
	unit8_menu->setScale(0.6);
	addChild(unit8_menu);

	////************* adds unit9 button ***********
	auto unit9_normal = Sprite::create("unit9_norma.png");
	if (unit9_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}
	auto unit9_menu = Sprite::create("unit9_norma.png");
	unit9_menu->setPosition(Vec2(origin.x + 415, origin.y + 20));
	unit9_menu->setScale(0.7);
	addChild(unit9_menu);

	//************* adds unit10 button ***********
	auto unit10_menu = Sprite::create("unit10_norma.png");
	unit10_menu->setPosition(Vec2(origin.x + 450, origin.y + 20));
	unit10_menu->setScale(0.5);
	addChild(unit10_menu);


	this->schedule(schedule_selector(BattleScene::updateGame));

	return true;
}

void BattleScene::updateGame(float dt)
{
	for (auto unit : units)
		if (!UnitCanGo(unit))
			unit->sprite->pauseSchedulerAndActions();
		else
			unit->sprite->resumeSchedulerAndActions();

	for (auto unit_a : units)
		for (auto unit_b : units)
			if (unit_a != unit_b) {
				auto bbox_unit_a = unit_a->sprite->boundingBox();
				auto bbox_unit_b = unit_b->sprite->boundingBox();

				bbox_unit_a.origin.x += unit_a->delta_x;
				bbox_unit_b.origin.x += unit_b->delta_x;

				if (bbox_unit_a.intersectsRect(bbox_unit_b) && (unit_a->team != unit_b->team))
				{
					unit_a->state = UnitState::Attacking;
					unit_b->state = UnitState::Attacking;

					unit_a->ReceiveAttackFromUnit(unit_b);
					unit_b->ReceiveAttackFromUnit(unit_a);
				}
		}

	// �������� ���� ������� ������
	for (auto unit : units)
		if (unit->state == UnitState::Dead)
			this->RemoveDeadUnit(unit);

	// ��������, ��� ���� ���������
	if (player_tower->state == UnitState::Dead) {

		GameOver(false);
	}
	else if (computer_tower->state == UnitState::Dead) {

		GameOver(true);
	}
}		

bool BattleScene::UnitCanGo(Unit * unit)
{
	bool can_go = true;

	for (auto other_unit : units) 
		if (other_unit != unit) {
			auto bbox_unit = unit->sprite->boundingBox();
			auto bbox_other_unit = other_unit->sprite->boundingBox();

			bbox_unit.origin.x += unit->delta_x;
			bbox_other_unit.origin.x += other_unit->delta_x;

			if ((other_unit->team == unit->team) && ((other_unit->isTower) || (unit->isTower)))
				continue;

			if (bbox_unit.intersectsRect(bbox_other_unit))
				can_go = false;
	}

	return can_go;
}



void BattleScene::unit_select_callback(int i)
{
	Unit* unit = nullptr;

	switch (i) {
	case 1:
		unit = new Unit1();
		break;
	case 2:
		unit = new Unit2();
		break;
	case 3:
		unit = new Unit3();
		break;
	case 4:
		unit = new Unit4();
		break;
	case 5:
		unit = new Unit5();
		break;
	}

	unit->team = Team::Player;

	if (!IsGameOver) {
		unit->AddToBattleScene(this);
		BlockPlayerUnitButtons();
		this->schedule(schedule_selector(BattleScene::UnBlockPlayerUnitButtons), 0.5f);
		ai->ReactPlayerUnitSelect(unit->id);
	}
}


//void BattleScene::increaseScore(float dt) {
//	this->score++;
//	std::stringstream ss;
//	std::string str;
//	ss << score;
//	ss >> str;
//	const char *p = str.c_str();
//	scoreLabel->setString(p);
//}

void BattleScene::BlockPlayerUnitButtons()
{
	button_unit1->setEnabled(false);
	button_unit2->setEnabled(false);
	button_unit3->setEnabled(false);
	button_unit4->setEnabled(false);
	button_unit5->setEnabled(false);
}

void BattleScene::UnBlockPlayerUnitButtons(float dt)
{
	button_unit1->setEnabled(true);
	button_unit2->setEnabled(true);
	button_unit3->setEnabled(true);
	button_unit4->setEnabled(true);
	button_unit5->setEnabled(true);
	this->unschedule(schedule_selector(BattleScene::UnBlockPlayerUnitButtons));
}

void BattleScene::GameOver(bool player_wins)
{
	IsGameOver = true;
	
	if (player_wins)
	{	
		// ��������� ������ � ����������� ������
		auto GameOver = Sprite::create("Tower2_over.png");
		GameOver->setPosition(Vec2(450, 110));
		GameOver->setScale(0.15);
		addChild(GameOver);

		auto GameOver2 = Sprite::create("you_won.png");
		GameOver2->setPosition(Vec2(210, 192));
		GameOver2->setScale(0.45);
		addChild(GameOver2);
	}
	else {
		// ��������� ������ � ����������� ������
		auto GameOver = Sprite::create("Tower1_over.png");
		GameOver->setPosition(Vec2(32, 110));
		GameOver->setScale(0.15);
		addChild(GameOver);
		
		auto GameOver2 = Sprite::create("GameOver.png");
		GameOver2->setPosition(Vec2(250, 200));
		GameOver2->setScale(0.5);
		addChild(GameOver2);
	}
}
