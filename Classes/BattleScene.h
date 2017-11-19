#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

struct Unit {
	Sprite* sprite;
	int hp;
};

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

	void unit1_select_callback();
	
	void unit2_select_callback();

	void unit3_select_callback();

	void unit4_select_callback();

	void unit5_select_callback();

	void unit6_select_callback();

	void unit7_select_callback();

	void unit8_select_callback();

	void unit9_select_callback();

	void unit10_select_callback();

private:
	CC_SYNTHESIZE(cocos2d::ProgressTimer*, hpView, HPView);
	CC_SYNTHESIZE(int, score, Score)
		CC_SYNTHESIZE(cocos2d::LabelAtlas*, scoreLabel, ScoreLabel);
	void increaseScore(float dt);
	void ShowGameOver(Ref* pObj);

	void updateGame(float dt);

	ui::Button * button_unit1;
	ui::Button * button_unit2;
	ui::Button * button_unit3;
	ui::Button * button_unit4;
	ui::Button * button_unit5;
	MenuItemSprite * unit6_menu;
	MenuItemSprite * unit7_menu;
	MenuItemSprite * unit8_menu;
	MenuItemSprite * unit9_menu;
	MenuItemSprite * unit10_menu;

	std::vector<Unit> units_player;
	std::vector<Unit> units_computer;

};

//void unit1_select(Ref* sender, ui::Widget::TouchEventType type);
