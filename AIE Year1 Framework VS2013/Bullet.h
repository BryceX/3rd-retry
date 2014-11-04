#pragma once
#include "AIE.h"
#include "Globals.h"
#include "Enemy.h"
#include "Player.h"
class Bullet
{
public:
	unsigned int spriteID;
	float x;
	float y;
	float width;
	float height;
	bool isAlive;
	void Movement();
	void Draw();
	void Shoot(int a_x, int a_y);
	void Collision();
	void GetXY(float playerX, float playerY);
	float gameTime;

	
	Bullet();
	~Bullet();
};

