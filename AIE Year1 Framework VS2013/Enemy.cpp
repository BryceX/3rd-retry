#include "Enemy.h"



Enemy::Enemy()
{
}
void Enemy::Draw()
{
	MoveSprite(spriteID, x, y);
	DrawSprite(spriteID);
}
void Enemy::Movement()
{
	y -= Globals::screenHeight*.1*GetDeltaTime();
}

Enemy::~Enemy()
{
}
