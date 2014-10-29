#include "AIE.h"
#include <iostream>
#include "Globals.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"



char menuText1[20] = "AIE 2nd Project";
char menuText2[30] = "Press Enter To Start";


enum GAMESTATES{
	MAINMENU,
	GAMEPLAY,
	GAMEOVER
};

int main( int argc, char* argv[] )
{	
    Initialise(800, 800, false, "AIE 2nd Project");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));
	Background mainmenu;
	mainmenu.menuBackground = CreateSprite("./images/mainmenu.png", Globals::screenWidth, Globals::screenHeight*1.0055, true);
	mainmenu.menuBackground2 = CreateSprite("./images/mainmenu.png", Globals::screenWidth, Globals::screenHeight*1.0055, true);
	
	Player lyn;
	lyn.width = Globals::screenWidth*.05;
	lyn.height = Globals::screenHeight*.05;
	lyn.spriteID = CreateSprite("./images/lyn.png", lyn.width, lyn.height, true);
	lyn.x = Globals::screenWidth*.5;
	lyn.y = Globals::screenHeight*.05;
	//lyn.firingKey = 'F';
	
	
	lyn.SetKey(GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D);
    

    //Game Loop
	GAMESTATES currentState = MAINMENU;
    do
    {
		switch (currentState)
		{
		case MAINMENU:
			
			mainmenu.MenuFlash();
			mainmenu.CreateMainMenuBackground();
			if (IsKeyDown(GLFW_KEY_ENTER))
			{
				currentState = GAMEPLAY;
			}
			
			break;



		case GAMEPLAY:
			lyn.Move();
			lyn.Draw();
			
			break;

		case GAMEOVER:
			break;

			
		}
		ClearScreen();
       

    } while(!FrameworkUpdate());
    Shutdown();

    return 0;
}