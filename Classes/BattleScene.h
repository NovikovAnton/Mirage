#pragma once

#include "cocos2d.h"

USING_NS_CC;

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

	void unit1_select(Ref* sender);
	void unit1_select_callback();


private:
	CC_SYNTHESIZE(cocos2d::ProgressTimer*, hpView, HPView);
	CC_SYNTHESIZE(int, score, Score)
		CC_SYNTHESIZE(cocos2d::LabelAtlas*, scoreLabel, ScoreLabel);
	void increaseScore(float dt);
	void ShowGameOver(Ref* pObj);

	MenuItemSprite * unit1_menu;

};
