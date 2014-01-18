#include "STAR.h"
#include <stdlib.h>
#include <time.h>

using namespace cocos2d;

bool STAR::init()
{

	if(!Object::init())
	{
		return false;
	}

	speed = rand()%61+30;

	this->initWithFile("132.png");
	this->setPosition(CCPointMake(rand()%800, 460));

	return true;
}

