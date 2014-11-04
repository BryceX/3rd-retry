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
	void Collision(float a_x, float a_y, float enemy_x, float enemy_y, float a_radius, float enemy_radius);
	bool isAlive = true;
	Enemy();
	~Enemy();
};

