#include "StartMenuScene.h"
#include "BattleScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* StartMenuScene::createScene()
{
    return StartMenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartMenuScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// add "StartMenuScene" splash screen"
	auto sprite = Sprite::create("StartMenuScene.jpg");
	if (sprite == nullptr)
	{
		problemLoading("'StartMenuScene.jpg'");
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

    auto label = Label::createWithTTF("Mirage", "fonts/Marker Felt.ttf", 36);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - 35 - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label);
    }

   

	//************* adds start game ***********
	auto start_normal = Sprite::create("start_norma.png");
	auto start_pressed = Sprite::create("start_pres.png");
	if (start_normal == nullptr || start_pressed == nullptr)
	{
		problemLoading("'start_normal or start_pressed.png'");
	}
	start_game = MenuItemSprite::create(start_normal, start_pressed, CC_CALLBACK_1(StartMenuScene::startgame, this));
	start_game->setPosition(visibleSize.width / 2, 300);
	start_game->setScale(1.0);

//************* adds Exit game ***********
	auto exit_normal = Sprite::create("exit_norma.png");
	auto exit_pressed = Sprite::create("exit_pres.png");
	if (exit_normal == nullptr || exit_pressed == nullptr)
	{
		problemLoading("'exit_normal or exit_pressed.png'");
	}

	exit_game = MenuItemSprite::create(exit_normal, exit_pressed, CC_CALLBACK_1(StartMenuScene::exitgame, this));
	exit_game->setPosition(visibleSize.width / 2, 250);
	exit_game->setScale(1.0);

	auto menu = Menu::create(start_game, exit_game/*, license_item, credits_item*/, NULL);
	menu->setPosition(Vec2(origin.x, origin.y - 200));
	this->addChild(menu);

    return true;
}

void StartMenuScene::startgame(Ref* sender)
{
	start_game->runAction(Sequence::create(
		ScaleTo::create(0.1f, 1.1f),
		ScaleTo::create(0.1f, 1.1f),
		ScaleTo::create(0.1f, 1.0f),
		CallFunc::create(CC_CALLBACK_0(StartMenuScene::startgame_callback, this)), NULL));
}

void StartMenuScene::exitgame(Ref* sender)
{
	exit_game->runAction(Sequence::create(
		ScaleTo::create(0.1f, 1.1f),
		ScaleTo::create(0.1f, 1.1f),
		ScaleTo::create(0.1f, 1.0f),
		CallFunc::create(CC_CALLBACK_0(StartMenuScene::exitgame_callback, this)), NULL));
}

void StartMenuScene::startgame_callback()
{
	auto scene = BattleScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void StartMenuScene::exitgame_callback()
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void StartMenuScene::menuCloseCallback(Ref* pSender)
{


    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
