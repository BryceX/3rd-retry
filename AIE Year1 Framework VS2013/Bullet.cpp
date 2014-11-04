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
		std::cout << "imshhooting gaiz";
	
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
