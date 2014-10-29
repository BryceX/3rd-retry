#pragma once
#include "AIE.h"
#include "Globals.h"
class Player
{
public:
	unsigned int spriteID;
	int width;
	int height;
	int x;
	int y;
	int health;
	void Move();
	void SetKey(float upKey, float downKey, float leftKey, float rightKey);
	float upKey;
	float downKey;
	float leftKey;
	float rightKey;
	float GetKey();
	void Draw();
	void Shoot();


	Player();
	~Player();
};

