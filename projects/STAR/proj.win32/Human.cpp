#include "Human.h"

using namespace cocos2d;

bool Human::init()
{
	if(!Object::init())
	{
		return false;
	}
	this->initWithFile("123.png");
	this->setPosition(CCPointMake(400, 40));

	return true;
	
}