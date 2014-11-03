#include "Enemy.h"



Enemy::Enemy()
{
}
void Enemy::Draw()
{
	MoveSprite(SpriteID, x, y);
	DrawSprite(SpriteID);
}
void Enemy::Movement()
{
	y -= Globals::screenHeight*.05*GetDeltaTime();
}

Enemy::~Enemy()
{
}
