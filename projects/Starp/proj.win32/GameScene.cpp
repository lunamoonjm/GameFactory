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

	this->setTouchEnabled(true);

	srand((unsigned)time(NULL));

	starList = new list<STAR*>();
	

	human = new Human();
	human->init();
	this->addChild(human);

	c = 1;

	this->schedule(schedule_selector(GameScene::update));
	this->schedule(schedule_selector(GameScene::spawn), 0.3f);

	return true;
}

void GameScene::update(float dt)
{
	CCRect* humanRect = new CCRect(human->getPositionX(), human->getPositionY(),
		human->getTextureRect().getMaxX() - human->getTextureRect().getMinX(),
		human->getTextureRect().getMaxY() - human->getTextureRect().getMinY());

	for(list<STAR*>::iterator iStar = starList->begin(); iStar != starList->end(); ++iStar)
	{
		STAR* star = (*iStar);
		star->setPositionY(star->getPositionY() - star->getSpeed() * dt);

		CCRect* starRect = new CCRect(star->getPositionX(), star->getPositionY(),
			star->getTextureRect().getMaxX() - star->getTextureRect().getMinX(),
			star->getTextureRect().getMaxY() - star->getTextureRect().getMinY());

		if(humanRect->intersectsRect(*starRect) == true)
		{
			this->removeChild(human, false);
		}
	}
	if(c==1)
		human->setPositionX(human->getPositionX() - human->getSpeed() * dt);
	else
		human->setPositionX(human->getPositionX() + human->getSpeed() * dt);

	if(human->getPositionX() < 0)
	{
		human->setPositionX(800);
	}

	if(human->getPositionX() > 800)
	{
		human->setPositionX(0);
	}
}

void GameScene::spawn(float dt)
{
	STAR* star = new STAR();
	star->init();
	this->addChild(star);
	starList->push_back(star);
}

void GameScene::ccTouchesBegan(CCSet *pTouches, CCEvent* event)
{
	CCSetIterator it=pTouches->begin();
	CCTouch* touch=(CCTouch*)(*it);
	CCPoint touchPoint=touch->getLocation();
	c *= -1;
}