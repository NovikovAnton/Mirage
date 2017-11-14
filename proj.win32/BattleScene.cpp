#include "BattleScene.h"
#include "BattleScene.h"


// version ported to win32 by meir yanovich email : meiry242@gmail.com

USING_NS_CC;

BattleScene::~BattleScene()
{
	//NotificationCenter::getInstance()->destroyInstance();
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
	//if (!Layer::init())
	//{
	//	return false;
	//}
	//this->score = 0;
	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//Point origin = Director::getInstance()->getVisibleOrigin();
	//

	////Score
	//auto rightTopUI = Sprite::createWithSpriteFrameName("right_top_ui.png");
	//rightTopUI->setAnchorPoint(Point(1, 1));
	//rightTopUI->setPosition(origin + Point(visibleSize));
	//this->addChild(rightTopUI);

	////the menuitem to show score
	//scoreLabel = LabelAtlas::create("0", "score_right_top.png", 23, 28, '0');
	//scoreLabel->setAnchorPoint(Point(1, 0.5));
	//scoreLabel->setPosition(visibleSize.width - 40, visibleSize.height - 45);
	//this->addChild(scoreLabel);

	//this->schedule(schedule_selector(BattleScene::increaseScore), (float)1 / 10);
	////this->addChild(scoreLabel);

	//NotificationCenter::getInstance()->destroyInstance();
	//NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(BattleScene::ShowGameOver), "ShowGameOver", NULL);

	return true;
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

void BattleScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}