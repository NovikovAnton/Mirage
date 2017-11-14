#include "BattleScene.h"
#include "SimpleAudioEngine.h"

// version ported to win32 by meir yanovich email : meiry242@gmail.com

USING_NS_CC;

BattleScene::~BattleScene()
{
	//NotificationCenter::getInstance()->destroyInstance();
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

	// add a label shows "Mirage"
	// create and initialize a label

	auto label = Label::createWithTTF("Battle", "fonts/Marker Felt.ttf", 14);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - 10 - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label);
	}

	auto tower1 = Sprite::create("Tower1.png");

	if (tower1 == nullptr)
	{
		problemLoading("'Tower1'");
	}
	tower1->setPosition(Vec2(100, 200));

	tower1->setScale(0.15);

	addChild(tower1);
	

	//************* adds battle game ***********
	auto unit1_normal = Sprite::create("unit1_norma.png");
	//auto start_pressed = Sprite::create("start_pres.png");
	if (unit1_normal == nullptr )
	{
		problemLoading("'start_normal or start_pressed.png'");
	}

	auto units_menu_pos = Vec2(origin.x + 20, origin.y + 5);

	unit1_menu = MenuItemSprite::create(unit1_normal, unit1_normal, CC_CALLBACK_1(BattleScene::unit1_select, this));
	unit1_menu->setPosition(units_menu_pos);
	unit1_menu->setScale(1.0);

	auto units_menu = Menu::create(unit1_menu, /*unit2_menu,/*, license_item, credits_item*/ NULL);
	units_menu->setPosition(units_menu_pos);


	this->addChild(units_menu);

	unit1_normal->setScale(0.5);

	return true;
}

void BattleScene::unit1_select(Ref* sender)
{
	unit1_menu->runAction(Sequence::create(
		ScaleTo::create(0.1f, 1.1f),
		ScaleTo::create(0.1f, 1.1f),
		ScaleTo::create(0.1f, 1.0f),
		CallFunc::create(CC_CALLBACK_0(BattleScene::unit1_select_callback, this)), NULL));
}


void BattleScene::unit1_select_callback()
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
