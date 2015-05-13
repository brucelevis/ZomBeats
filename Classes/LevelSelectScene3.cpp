#include "LevelSelectScene2.h"
#include "LevelSelectScene3.h"
#include "LevelSelectScene4.h"
#include "GameController.h"
#include "MainMenuScene.h"
#include "ProgressScene.h"
#include "View.h"
USING_NS_CC;
using namespace cocos2d;

LevelSelectScene3::LevelSelectScene3()
{
}


LevelSelectScene3 ::~LevelSelectScene3()
{
}

Scene* LevelSelectScene3::createScene()
{
	auto scene = Scene::create();
	auto layer = LevelSelectScene3::create();
	scene->addChild(layer);

	return scene;

}

bool LevelSelectScene3::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->setScale(visibleSize.height / VIEW_HEIGHT);
	auto backgroundSprite = Sprite::create("textures/level_selection_bg.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	backgroundSprite->setScale(LEVEL_BACKGROUND_SCALE);
	this->addChild(backgroundSprite);


	auto backDirButton = MenuItemImage::create("textures/back_dir.png", "textures/back_dir.png", CC_CALLBACK_1(LevelSelectScene3::GoToPrevLevelScene, this));
	backDirButton->setPosition(Point(visibleSize.width / 2 + origin.x - LEVEL_BUTTON_HORIZONTAL_OFFSET*0.5, visibleSize.height / 2 + origin.y - LEVEL_BUTTON_VERTICAL_OFFSET));
	backDirButton->setScale(DIRECTION_BUTTON_SCALE);

	auto forwardDirButton = MenuItemImage::create("textures/forward_dir.png", "textures/forward_dir.png", CC_CALLBACK_1(LevelSelectScene3::GoToNextLevelScene, this));
	forwardDirButton->setPosition(Point(visibleSize.width / 2 + origin.x + LEVEL_BUTTON_HORIZONTAL_OFFSET*0.5, visibleSize.height / 2 + origin.y - LEVEL_BUTTON_VERTICAL_OFFSET));
	forwardDirButton->setScale(DIRECTION_BUTTON_SCALE);


	auto backButton = MenuItemImage::create("textures/back_button.png", "textures/back_button_clicked.png", CC_CALLBACK_1(LevelSelectScene3::GoToMainMenuScene, this));
	backButton->setPosition(Point(visibleSize.width / 2 + origin.x + LEVEL_BUTTON_HORIZONTAL_OFFSET*1.7, visibleSize.height / 2 + origin.y + LEVEL_BUTTON_VERTICAL_OFFSET*1.25));
	backButton->setScale(BACK_BUTTON_SCALE);

	auto menu = Menu::create(backDirButton, forwardDirButton, backButton, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	return true;
}

/*
auto progressScene = ProgressScene::createScene();
//Director::getInstance()->replaceScene(TransitionFade::create(LEVEL_MENU_TRANSITION_TIME, progressScene));
Director::getInstance()->replaceScene(progressScene);
*/

void LevelSelectScene3::GoToGameScene(cocos2d::Ref *sender, int level)
{
	ProgressScene::createLayer(level);
	auto progressScene = ProgressScene::createScene();
	Director::getInstance()->replaceScene(progressScene);

}

void LevelSelectScene3::GoToPrevLevelScene(cocos2d::Ref *sender)
{
	auto scene = LevelSelectScene2::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(LEVEL_MENU_TRANSITION_TIME, scene));

}

void LevelSelectScene3::GoToNextLevelScene(cocos2d::Ref *sender)
{
	auto scene = LevelSelectScene4::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(LEVEL_MENU_TRANSITION_TIME, scene));

}



void LevelSelectScene3::GoToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(LEVEL_MENU_TRANSITION_TIME, scene));
}