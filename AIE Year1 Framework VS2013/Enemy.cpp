#include "Enemy.h"



Enemy::Enemy()
{
}
void Enemy::Draw()
{
	if (isAlive)
	{
		MoveSprite(spriteID, x, y);
		DrawSprite(spriteID);
	}
}
void Enemy::Movement()
{
	y -= Globals::screenHeight*.1*GetDeltaTime();
}
void Enemy::Collision(float a_x, float a_y, float enemy_x, float enemy_y, float a_radius, float enemy_radius)
{
		if ((((a_x - enemy_x)*(a_x - enemy_x)) + ((a_y - enemy_y)*(a_y - enemy_y))) < a_radius + enemy_radius)
		{
			health -= 1;
			if (health <= 0)
			{
				isAlive = false;
			}
		}
}

Enemy::~Enemy()
{
}
