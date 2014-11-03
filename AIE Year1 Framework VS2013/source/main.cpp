#include "AIE.h"
#include <iostream>
#include "Globals.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>



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
    
	
	static std::vector<Enemy*> type1;
	for (int i = 0, i < 6, ++i)
	{
		type1.width = Globals::screenWidth*.075;
		type1.height = Globals::screenHeight*.05;
		type1.SpriteID = CreateSprite("./images/enemy1.png", type1.width, type1.height, true);
		type1.x = Globals::screenWidth*.5;
		type1.y = Globals::screenHeight*1.25;
	}
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
			type1.Movement();
			type1.Draw();
			
			break;

		case GAMEOVER:
			break;

			
		}
		ClearScreen();
       

    } while(!FrameworkUpdate());
    Shutdown();

    return 0;
}