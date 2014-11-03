#pragma once
#include "AIE.h"
#include "Globals.h"
class Enemy
{
public:
	unsigned int SpriteID;
	int width;
	int height;
	int x;
	int y;
	int health;
	void Movement();
	void Draw();
	Enemy();
	~Enemy();
};

