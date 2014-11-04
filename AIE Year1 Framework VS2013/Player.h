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
	void Collision(float a_x, float a_y, float enemy_x, float enemy_y, float a_radius, float enemy_radius);
	float upKey;
	float downKey;
	float leftKey;
	float rightKey;
	float GetKey();
	void Draw();


	Player();
	~Player();
};

