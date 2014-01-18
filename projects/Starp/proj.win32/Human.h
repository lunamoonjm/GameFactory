#pragma once

#include "cocos2d.h"
#include "Object.h"

class Human : public Object
{
private:
	int speed;
public:
	virtual bool init();

	void setSpeed(int n) { speed = n; }
	int getSpeed() { return speed; }
};