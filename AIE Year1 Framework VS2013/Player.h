#pragma once
#include "AIE.h"
#include "Globals.h"
#include "Enemy.h"
#include "Bullet.h"
class Player
{
public:
	unsigned int spriteID;
	float width;
	float height;
	float x;
	float y;
	int health;
	float timeWhenShot;
	float firingDelay;
	void Move(float a_deltaTime);
	void SetKey(float upKey, float downKey, float leftKey, float rightKey);
	void Collision();
	float upKey;
	float downKey;
	float leftKey;
	float rightKey;
	float GetKey();
	void Draw();


	Player();
	~Player();
};

