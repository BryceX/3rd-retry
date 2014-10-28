#include "Background.h"


Background::Background()
{
}
int menuTime;
bool IsShowTime = true;
char menuText[30] = "Press Enter to Start";
unsigned int menuBackground = CreateSprite("/images/mainmenu.png", Globals::screenWidth, Globals::screenHeight, true);
int menuBackgroundY = Globals::screenHeight*.5;
int menuBackgroundY2 = Globals::screenHeight*1.5;
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
	MoveSprite(menuBackground, Globals::screenWidth*.5, menuBackgroundY*.975);
	DrawSprite(menuBackground);
	MoveSprite(menuBackground2, Globals::screenWidth*.5, menuBackgroundY2*.975);
	DrawSprite(menuBackground);

	menuBackground -= GetDeltaTime()*Globals::screenHeight*.2;
	menuBackground -= GetDeltaTime()*Globals::screenHeight*.2;
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
