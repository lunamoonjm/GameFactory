#pragma once

#include "cocos2d.h"
#include "STAR.h"
#include <list>
#include "Human.h"

using namespace std;

class GameScene : public cocos2d::CCLayer
{
private:
	list<STAR*> *starList;
	Human* human;
	int c;

public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	void update(float dt);

	void spawn(float dt);

	CREATE_FUNC(GameScene);

	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent* event);
};