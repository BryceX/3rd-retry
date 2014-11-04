#pragma once
#include "AIE.h"
#include "Globals.h"
class Enemy
{
public:
	unsigned int spriteID;
	float width;
	float height;
	float x;
	float y;
	int health;
	void Movement();
	void Draw();
	void Collision();
	Enemy();
	~Enemy();
};

