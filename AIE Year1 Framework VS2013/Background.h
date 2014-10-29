#pragma once
#include "AIE.h"
#include "Globals.h"
class Background
{
public:

	bool IsShowTime;
	int menuTime;
	char * menuText = "Press Enter to Start";
	unsigned int menuBackground;
	unsigned int menuBackground2;

	float menuBackgroundY;
	float menuBackgroundY2;
	void MenuFlash();
	void CreateMainMenuBackground();
	Background();
	~Background();
};

