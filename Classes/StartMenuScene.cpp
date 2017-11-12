#include "StartMenuScene.h"
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
                                origin.y + visibleSize.height - 50 - label->getContentSize().height));

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
	start_game->setPosition(visibleSize.width / 2, 200);
	start_game->setScale(1.0);

	auto menu = Menu::create(start_game/*, license_item, credits_item*/, NULL);
	menu->setPosition(Vec2(origin.x, origin.y-100));
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

void StartMenuScene::startgame_callback()
{
	/*CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	GameLayer::isDie = false;
	auto scene = (LoadingScene::audioloaded) ? HelloWorld::createScene() : LoadingScene::createScene();
	Director::getInstance()->replaceScene(scene);*/
}

void StartMenuScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
