#include "Player.h"


Player::Player()
{
}
void Player::Draw()
{
	MoveSprite(spriteID, x, y);
	DrawSprite(spriteID);
}
void Player::SetKey(float upKey, float downKey, float leftKey, float rightKey)
{
	this->upKey = upKey;
	this->downKey = downKey;
	this->leftKey = leftKey;
	this->rightKey = rightKey;
}
void Player::Move()
{
	if (IsKeyDown(upKey))
	{
		y += Globals::screenHeight*.2*GetDeltaTime();
		if (y > Globals::screenHeight - height*.5)
		{
			y = Globals::screenHeight - height*.5;
		}
	}
	if (IsKeyDown(downKey))
	{
		y -= height*.2*GetDeltaTime();
		if (y < height*.5)
		{
			y = height*.5;
		}
	}
	if (IsKeyDown(leftKey))
	{
		x -= Globals::screenWidth*.35*GetDeltaTime();
		if (x < Globals::screenWidth*.125 + width*.5)
		{
			x = Globals::screenWidth*.125 + width*.5;
		}
	}
	if (IsKeyDown(rightKey))
	{
		x += Globals::screenWidth*.35*GetDeltaTime();
		if (x > Globals::screenWidth*.875 - width*.5)
		{
			x = Globals::screenWidth*.875 - width*.5;
		}
	}
}


Player::~Player()
{
}
