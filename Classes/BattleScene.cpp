#include "ui/CocosGUI.h"

#include "BattleScene.h"
#include "SimpleAudioEngine.h"

#include <string>

USING_NS_CC;

BattleScene::~BattleScene()
{
	//NotificationCenter::getInstance()->destroyInstance();
}

void BattleScene::AddUnit(Unit * unit)
{
	units_player.push_back(unit);
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

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// add "StartMenuScene" splash screen"
	auto sprite = Sprite::create("Battle.png");
	if (sprite == nullptr)
	{
		problemLoading("'Battle.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite);
	}

	// Создание фона "Mirage"

	auto label1 = Label::createWithTTF("Battle", "fonts/Marker Felt.ttf", 14);
	label1->setColor(Color3B::BLACK);
	if (label1 == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label1->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label1->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label1);
	}


	// Надпись красной команды
	auto label2 = Label::createWithTTF("Red team", "fonts/Marker Felt.ttf", 14);
	label2->setColor(Color3B::RED);
	if (label2 == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label2->setPosition(Vec2(origin.x + 30, origin.y + 255));

		// add the label as a child to this layer
		this->addChild(label2);
	}


	// Надпись синей команды команды
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



	// Добавление башни №1
	auto tower1 = new TowerPlayer();
	tower1->AddToBattleScene(this);

	// Добавление башни №2 
	auto tower2 = new TowerComputer();
	tower2->AddToBattleScene(this);


	//************* adds unit1 game ***********
	auto unit1_normal = Sprite::create("unit1_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
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

	//************* adds unit2 game ***********

	auto unit2_normal = Sprite::create("unit2_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
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
				CallFunc::create(CC_CALLBACK_0(BattleScene::unit2_select_callback, this)), NULL));
		}
	});

	this->addChild(button_unit2);

	
	//************* adds unit3 game ***********
	auto unit3_normal = Sprite::create("unit3_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
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
				CallFunc::create(CC_CALLBACK_0(BattleScene::unit3_select_callback, this)), NULL));
		}
	});

	this->addChild(button_unit3);


	//************* adds unit4 game ***********
	auto unit4_normal = Sprite::create("unit4_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
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
				CallFunc::create(CC_CALLBACK_0(BattleScene::unit4_select_callback, this)), NULL));
		}
	});

	this->addChild(button_unit4);



	////************* adds unit5 game ***********
	auto unit5_normal = Sprite::create("unit5_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
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
				CallFunc::create(CC_CALLBACK_0(BattleScene::unit5_select_callback, this)), NULL));
		}
	});

	this->addChild(button_unit5);

	//************* adds unit6 game ***********
	auto unit6_normal = Sprite::create("unit6_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
	if (unit6_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}
	unit6_menu = MenuItemSprite::create(unit6_normal, unit6_normal, nullptr);
	unit6_menu->setPosition(Vec2(origin.x + 290, origin.y + 5));
	unit6_menu->setScale(1.0);

	//************* adds unit7 game ***********
	auto unit7_normal = Sprite::create("unit7_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
	if (unit7_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}
	unit7_menu = MenuItemSprite::create(unit7_normal, unit7_normal, nullptr);
	unit7_menu->setPosition(Vec2(origin.x + 330, origin.y - 7));
	unit7_menu->setScale(1.0);

	//************* adds unit8 game ***********
	auto unit8_normal = Sprite::create("unit8_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
	if (unit8_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}
	unit8_menu = MenuItemSprite::create(unit8_normal, unit8_normal, nullptr);
	unit8_menu->setPosition(Vec2(origin.x + 365, origin.y ));
	unit8_menu->setScale(1.0);

	//************* adds unit9 game ***********
	auto unit9_normal = Sprite::create("unit9_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
	if (unit9_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}
	unit9_menu = MenuItemSprite::create(unit9_normal, unit9_normal, nullptr);
	unit9_menu->setPosition(Vec2(origin.x + 410, origin.y - 2));
	unit9_menu->setScale(1.0);

	//************* adds unit10 game ***********
	auto unit10_normal = Sprite::create("unit10_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
	if (unit10_normal == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}
	unit10_menu = MenuItemSprite::create(unit10_normal, unit10_normal, nullptr);
	unit10_menu->setPosition(Vec2(origin.x + 450, origin.y + 8));
	unit10_menu->setScale(1.0);

//	auto units_menu = Menu::create(unit6_menu, unit7_menu, unit8_menu, unit9_menu, unit10_menu,/*, license_item, credits_item*/ NULL);
//	units_menu->setPosition(units_menu_pos);

//	this->addChild(units_menu);


	unit6_normal->setScale(0.5);
	unit7_normal->setScale(0.6);
	unit8_normal->setScale(0.6);
	unit9_normal->setScale(0.6);
	unit10_normal->setScale(0.5);


	this->schedule(schedule_selector(BattleScene::updateGame));

	return true;
}

void BattleScene::updateGame(float dt)
{

	std::vector<Unit*> units_to_stop;

	for (auto player_unit : units_player)
	{
		auto s = player_unit->sprite;
		auto player_unit_rect = s->boundingBox();

		for (auto computer_unit : units_computer)
		{
			auto s = computer_unit->sprite;
			auto computer_unit_rect = s->boundingBox();
			
			//this->addChild(computer_unit_rect);

			if (player_unit_rect.intersectsRect(computer_unit_rect)) {
				units_to_stop.push_back(computer_unit);
				units_to_stop.push_back(player_unit);

				//std::string s1 = "computer:" + std::to_string(computer_unit.sprite->getPosition().x) + " " + std::to_string(computer_unit.sprite->getPosition().y);
				//std::string s2 = "player:" + std::to_string(player_unit.sprite->getPosition().x) + " " + std::to_string(player_unit.sprite->getPosition().y);

				//auto label1 = Label::createWithTTF(s1, "fonts/Marker Felt.ttf", 14);
				//label1->setColor(Color3B::BLACK);
				//label1->setPosition(Vec2(200, 200));
				//this->addChild(label1);
				//
				//auto label2 = Label::createWithTTF(s2, "fonts/Marker Felt.ttf", 14);
				//label2->setColor(Color3B::BLACK);
				//label2->setPosition(Vec2(200, 150));
				//this->addChild(label2);

				//auto box1 = DrawNode::create();

				// box1->drawRect(Vec2(player_unit.sprite->getPosition().x - (player_unit.sprite->getContentSize().width / 2), player_unit.sprite->getPosition().y - (player_unit.sprite->getContentSize().height / 2)),
				// 	Vec2(player_unit.sprite->getContentSize().width, player_unit.sprite->getContentSize().height), Color4F::RED);

				
				//box1->drawRect(player_unit.sprite->boundingBox().origin, player_unit.sprite->boundingBox().origin + player_unit.sprite->boundingBox().size, Color4F::RED);

				//box1->setLineWidth(2);
				//this->addChild(box1); // this being a node or scene

				//auto box2 = DrawNode::create();

				//box2->drawRect(computer_unit.sprite->boundingBox().origin, computer_unit.sprite->boundingBox().origin + computer_unit.sprite->boundingBox().size, Color4F::BLUE);
				//box2->setLineWidth(2);
				//this->addChild(box2); // this being a node or scene
			}
		}

		for (auto unit : units_to_stop)
			unit->sprite->stopAllActions();
	}
}

//void BattleScene::unit2_select(Ref* sender)
//{
//	
//}

//void BattleScene::unit3_select(Ref* sender)
//{
//	
//}

//void BattleScene::unit4_select(Ref* sender)
//{
//	
//}

//void BattleScene::unit5_select(Ref* sender)
//{
//	
//}



void BattleScene::unit_select_callback(int i)
{
	switch (i) {
	case 1:
		auto unit = new Unit1();
		unit->AddToBattleScene(this);

		break;
	}

}

void BattleScene::unit2_select_callback()
{
	auto unit = Sprite::create("unit2_norma.png");
	unit->setPosition(Vec2(45, 100));
	unit->setScale(0.5);
	addChild(unit);

	auto moveBy2 = MoveBy::create(4, Vec2(400, 0));
	unit->runAction(moveBy2);
}

void BattleScene::unit3_select_callback()
{
	auto unit = Sprite::create("unit3_norma.png");
	unit->setPosition(Vec2(45, 100));
	unit->setScale(0.5);
	addChild(unit);

	auto moveBy3 = MoveBy::create(4, Vec2(400, 0));
	unit->runAction(moveBy3);
}

void BattleScene::unit4_select_callback()
{
	auto unit = Sprite::create("unit4_norma.png");
	unit->setPosition(Vec2(45, 100));
	unit->setScale(0.5);
	addChild(unit);

	auto moveBy4 = MoveBy::create(4, Vec2(400, 0));
	unit->runAction(moveBy4);
}

void BattleScene::unit5_select_callback()
{
	auto unit = Sprite::create("unit5_norma.png");
	unit->setPosition(Vec2(45, 100));
	unit->setScale(0.5);
	addChild(unit);

	auto moveBy5 = MoveBy::create(4, Vec2(400, 0));
	unit->runAction(moveBy5);
}

void BattleScene::unit6_select_callback()
{
	//auto scene = BattleScene::createScene();
	//Director::getInstance()->replaceScene(scene);
}

void BattleScene::unit7_select_callback()
{
	//auto scene = BattleScene::createScene();
	//Director::getInstance()->replaceScene(scene);
}

void BattleScene::unit8_select_callback()
{
	//auto scene = BattleScene::createScene();
	//Director::getInstance()->replaceScene(scene);
}

void BattleScene::unit9_select_callback()
{
	//auto scene = BattleScene::createScene();
	//Director::getInstance()->replaceScene(scene);
}

void BattleScene::unit10_select_callback()
{
	//auto scene = BattleScene::createScene();
	//Director::getInstance()->replaceScene(scene);
}

void BattleScene::increaseScore(float dt) {
	this->score++;
	std::stringstream ss;
	std::string str;
	ss << score;
	ss >> str;
	const char *p = str.c_str();
	scoreLabel->setString(p);
}

void BattleScene::ShowGameOver(Ref* pObj)
{
	//unschedule(schedule_selector(BattleScene::increaseScore));
	//    BulletController::reset();
	//    EnemyController::reset();
	//auto gameoverlayer = GameOverLayer::create(this->score);
	//addChild(gameoverlayer, 10);
}
