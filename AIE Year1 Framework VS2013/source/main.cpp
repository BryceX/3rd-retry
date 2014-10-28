#include "AIE.h"
#include <iostream>
#include "Globals.h"



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

    

    //Game Loop
	GAMESTATES currentState = MAINMENU;
    do
    {
		switch (currentState)
		{
		case MAINMENU:
		
			if (IsKeyDown(KEY_ENTER))
			{
				currentState = GAMEPLAY;
			}
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
