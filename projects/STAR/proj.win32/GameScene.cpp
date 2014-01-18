#include <stdlib.h>
#include <time.h>
#include "GameScene.h"
#include "STAR.h"
#include "Human.h"

using namespace cocos2d;

CCScene* GameScene::scene()
{
	CCScene *scene = CCScene::create();

	GameScene *layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!CCLayer::init() )
	{
		return false;
	}

	srand((unsigned)time(NULL));

	starList = new list<STAR*>();
	
	star = new STAR();
	star->init();
	this->addChild(star);

	human = new Human();
	human->init();
	this->addChild(human);

	this->schedule(schedule_selector(GameScene::update));
	this->schedule(schedule_selector(GameScene::spawn), 1.0f);

	return true;
}

void GameScene::update(float dt)
{
	star->setPositionY(star->getPositionY() - star->getSpeed() * dt);
	for(list<STAR*>::iterator iStar = starList->begin(); iStar != starList->end(); ++iStar)
	{
		STAR* star = (*iStar);
		star->setPositionY(star->getPositionY() - star->getSpeed() * dt);
	}
}

void GameScene::spawn(float dt)
{
	STAR* star = new STAR();
	star->init();
	this->addChild(star);
	starList->push_back(star);
}