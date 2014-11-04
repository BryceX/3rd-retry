#include "Bullet.h"


Bullet::Bullet()
{
	isAlive = false;
}
void Bullet::GetXY(float playerX, float playerY)
{
	this->x = playerX;
	this->y = playerY;
}
void Bullet::Shoot(int a_x, int a_y )
{
	
		x = a_x;
		y = a_y;
		MoveSprite(spriteID, a_x, a_y);
		DrawSprite(spriteID);
}
void Bullet::Collision(float a_x, float a_y, float enemy_x, float enemy_y, float a_radius, float enemy_radius)
{
	if ((((a_x - enemy_x)*(a_x - enemy_x)) + ((a_y - enemy_y)*(a_y - enemy_y))) < a_radius + enemy_radius)
	{
		health -= 1;
		std::cout << "I HIT SOMETYHING";
		if (health < 0)
			isAlive = false;
	}
}
void Bullet::Draw()
{
	DrawSprite(spriteID);
}
void Bullet::Movement()
{
	y += Globals::screenHeight*.3*GetDeltaTime();
	MoveSprite(spriteID, x, y);
	if (y > Globals::screenHeight)
	{
		isAlive = false;
	}
}


Bullet::~Bullet()
{
}
