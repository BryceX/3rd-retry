#pragma once
#include "AIE.h"
#include "Globals.h"
class Background
{
public:

	bool IsShowTime;
	int menuTime;
	char menuText[30];
	unsigned int menuBackground;
	unsigned int menuBackground2;
	int menuBackgroundY;
	int menuBackgroundY2;
	void MenuFlash();
	void CreateMainMenuBackground();
	Background();
	~Background();
};

