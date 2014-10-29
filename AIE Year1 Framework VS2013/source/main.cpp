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
	mainmenu.menuBackground = CreateSprite("./images/mainmenu.png", Globals::screenWidth, Globals::screenHeight, true);
	mainmenu.menuBackground2 = CreateSprite("./images/mainmenu.png", Globals::screenWidth, Globals::screenHeight, true);
	

    

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
			ClearScreen();
			break;



		case GAMEPLAY:
			
			break;

		case GAMEOVER:
			break;


		}
		
       

    } while(!FrameworkUpdate());
    Shutdown();

    return 0;
}