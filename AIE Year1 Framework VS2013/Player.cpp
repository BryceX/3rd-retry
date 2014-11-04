#include "Player.h"


Player::Player()
{
	firingDelay = .25f;
	timeWhenShot = 0;
}
void Player::Draw()
{
	MoveSprite(spriteID, x, y);
	DrawSprite(spriteID);
}
void Player::Collision(float a_x, float a_y, float enemy_x, float enemy_y, float a_radius, float enemy_radius)
{
	if ((((a_x - enemy_x)*(a_x - enemy_x)) + ((a_y - enemy_y)*(a_y - enemy_y))) < a_radius + enemy_radius)
	{
		health -= 1;
	}
}
void Player::SetKey(float upKey, float downKey, float leftKey, float rightKey)
{
	this->upKey = upKey;
	this->downKey = downKey;
	this->leftKey = leftKey;
	this->rightKey = rightKey;
}

void Player::Move(float a_deltaTime)
{
	timeWhenShot += a_deltaTime;

	if (IsKeyDown(upKey))
	{
		y += (Globals::screenHeight)*(.2*GetDeltaTime());
		if (y > Globals::screenHeight - height*.5)
		{
			y = Globals::screenHeight - height*.5;
		}
	}
	if (IsKeyDown(downKey))
	{
		y -= (Globals::screenHeight)*(.2*GetDeltaTime());
		if (y < height*.5)
		{
			y = height*.5;
		}
	}
	if (IsKeyDown(leftKey))
	{
		x -= Globals::screenWidth*.3*GetDeltaTime();
		if (x < Globals::screenWidth*.125 + width*.5)
		{
			x = Globals::screenWidth*.125 + width*.5;
		}
	}
	if (IsKeyDown(rightKey))
	{
		x += (Globals::screenWidth)*(.3*GetDeltaTime());
		if (x > Globals::screenWidth*.875 - width*.5)
		{
			x = Globals::screenWidth*.875 - width*.5;
		}
	}
}


Player::~Player()
{
}
