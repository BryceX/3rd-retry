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
std::vector<Bullet> bulletvector;
void ShootBullet(int a_x, int a_y);


enum GAMESTATES{
	MAINMENU,
	GAMEPLAY,
	GAMEOVER
};

int main(int argc, char* argv[])
{
	Initialise(800, 800, false, "AIE 2nd Project");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));
	Background mainmenu;
	mainmenu.menuBackground = CreateSprite("./images/mainmenu.png", Globals::screenWidth, Globals::screenHeight*1.0055, true);
	mainmenu.menuBackground2 = CreateSprite("./images/mainmenu.png", Globals::screenWidth, Globals::screenHeight*1.0055, true);

	Player lyn;
	lyn.health = 5;
	lyn.width = Globals::screenWidth*.05;
	lyn.height = Globals::screenHeight*.05;
	lyn.spriteID = CreateSprite("./images/lyn.png", lyn.width, lyn.height, true);
	lyn.x = Globals::screenWidth*.5;
	lyn.y = Globals::screenHeight*.05;
	lyn.SetKey(GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D);
	//lyn.firingKey = 'F';	

	float deltaTime;
	Bullet dagger;
	dagger.width = Globals::screenWidth *.025;
	dagger.height = Globals::screenHeight *.025;

	dagger.gameTime = 0;

	for (int i = 0; i < 50; i++)
	{
		dagger.spriteID = CreateSprite("./images/dagger.png", dagger.width, dagger.height, true);
		bulletvector.push_back(dagger);
	}

	std::vector<Enemy> type1vector;
	Enemy type1;
	type1.health = 1;
	type1.width = Globals::screenWidth*.05;
	type1.height = Globals::screenHeight*.05;
	type1.x = Globals::screenWidth*.5;
	type1.y = Globals::screenHeight;
	for (int i = 0; i < 6; i++)
	{
		type1.y += 40;
		type1.spriteID = CreateSprite("./images/enemy1.png", type1.width, type1.height, true);
		type1vector.push_back(type1);
	}
	//Game Loop
	GAMESTATES currentState = MAINMENU;
	do
	{
		deltaTime =  GetDeltaTime();
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





			if (IsKeyDown(GLFW_KEY_F))
			{
				if (lyn.firingDelay < lyn.timeWhenShot)
				{
					ShootBullet(lyn.x, lyn.y);
					lyn.timeWhenShot = 0;
				}
			}

			for (int i = 0; i < bulletvector.size(); ++i)
			{
				if (bulletvector[i].isAlive)
				{

					bulletvector[i].gameTime += deltaTime;
					bulletvector[i].Movement();
					bulletvector[i].Draw();
				}

			}
				for (int i = 0; i < type1vector.size(); ++i)
				{

					type1vector[i].Movement();
					type1vector[i].Draw();
					lyn.Collision(lyn.x, lyn.y, type1vector[i].x, type1vector[i].y, Globals::screenWidth*.05, Globals::screenWidth*.05);

					if (type1vector[i].health = 0)
					{
						type1vector[i].KilledEnemy();
					}

				}
				lyn.Move(deltaTime);
				lyn.Draw();
				




				break;

		case GAMEOVER:
			break;


			}
			ClearScreen();


		} while (!FrameworkUpdate());
		Shutdown();

		return 0;
	}

void ShootBullet(int a_x, int a_y)
{
	for (int i = 0; i < bulletvector.size(); ++i)
	{
		if (!bulletvector[i].isAlive)
		{
			bulletvector[i].isAlive = true;
			bulletvector[i].Shoot(a_x, a_y);
			return;

		}
	}

}