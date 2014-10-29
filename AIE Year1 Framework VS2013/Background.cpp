#include "Background.h"


Background::Background()
{
}
int menuTime;
bool IsShowTime = true;

int menuBackgroundY = Globals::screenHeight;
int menuBackgroundY2 = Globals::screenHeight;
void Background::MenuFlash()
{

	menuTime += GetDeltaTime();
	if (IsShowTime)
	{
		DrawString(menuText, Globals::screenWidth*.4, Globals::screenHeight*.6);
	}
	if (menuTime <= 1.5)
	{
		IsShowTime = true;
	}
	if (menuTime >= 1.5)
	{
		IsShowTime = false;
	}
	if (menuTime >= 3)
	{
		menuTime = 0;
	}

}

void Background::CreateMainMenuBackground()
{
	MoveSprite(menuBackground, Globals::screenWidth*.5, menuBackgroundY);
	DrawSprite(menuBackground);
	MoveSprite(menuBackground2, Globals::screenWidth*.5, menuBackgroundY2);
	DrawSprite(menuBackground2);

	menuBackgroundY -= GetDeltaTime()*Globals::screenHeight*.02;
	menuBackgroundY2 -= GetDeltaTime()*Globals::screenHeight*.02;
	if (menuBackgroundY <= Globals::screenHeight*-.5)
	{
		menuBackgroundY = Globals::screenHeight*1.5;
	}
	if (menuBackgroundY2 <= Globals::screenHeight*-.5)
	{
		menuBackgroundY2 = Globals::screenHeight*1.5;
	}
}

Background::~Background()
{
}
