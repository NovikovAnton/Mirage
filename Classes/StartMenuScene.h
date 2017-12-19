#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "BattleScene.h"

USING_NS_CC;

class StartMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	// Колбек на старт игры
	void startgame(cocos2d::Ref* sender, Complexity c);
	void startgame_callback(Complexity c);
    
	// Колбек для выхода из игры
	void exitgame(cocos2d::Ref* sender);
	void exitgame_callback();

    // implement the "static create()" method manually
    CREATE_FUNC(StartMenuScene);

private:
  MenuItemSprite * start_game_easy;
  MenuItemSprite * start_game_hard;
  MenuItemSprite * exit_game;
};

#endif // __HELLOWORLD_SCENE_H__
