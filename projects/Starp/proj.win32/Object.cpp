#include "Object.h"

bool Object::init()
{
	if(!CCSprite::init())
	{
		return false;
	}

	return true;
}