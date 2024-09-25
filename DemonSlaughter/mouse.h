#ifndef MOUSE_H_INCLUDED
#define MOUSE_H_INCLUDED
#include<iostream>
using namespace std;

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::All Mouse Related Functionss Are Here:::::::::::::::::::::::::::::::::::::::::::::::::

void mouse(int button,int state,int mx,int my)
{
	//Co-ordinate Printing
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout<< mx << endl << my << endl;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
	//Activating Load Game & Sounds In Options Page
	if (options)
	{
		//Load Button
		if (my >= 357 && my <= 457)
		{

			if (mx >= 654 && mx <= 754)
			{
				if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
				{
					menu = false;
					loads = true;
					instruction = false;
					credits = false;
					options = false;
					level1 = false;
					level2 = false;
					level3 = false;
					level4 = false;
					
					
				}
			}

		}
		//Music On
		if (my >= 257 && my <= 357)
		{

			if (mx >= 654 && mx <= 754)
			{
				if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
				{
					PlaySound("music//game", NULL, SND_LOOP | SND_ASYNC);
				}
			}

		}
		//Music Off
		if (my >= 157 && my <= 257)
		{

			if (mx >= 654 && mx <= 754)
			{
				if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
				{
					PlaySound(0,0,0);
				}
			}

		}
	}
	
	if (!menu)
	{
		//Activating Home button::
		if (my >= 600 && my <= 700)
		{
			if (mx >= 1450 && mx <= 1490)
			{
				if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
				{
					menu        = true;
					credits     = false;
					options     = false;
					instruction = false;

					level1 = false;
					level2 = false;
					level3 = false;
					level4 = false;
					
				}
			}

		}
		//Saving Game Progess
		if (my >= 500 && my <= 550)
		{
			if (mx >= 1450 && mx <= 1490)
			{
				if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
				{
					menupress[7] = true;
					menupress[6] = true;
					savepress = false;
					if (level1)
						saveGame(boyx, boyy, "level1");
					if (level2)
						saveGame(boyx, boyy, "level2");
					if (level3)
						saveGame(boyx, boyy, "level3");
					if (level4)
						saveGame(boyx, boyy, "level4");
				
				}

			}

		}

	}

	//Activating Level 1::
	if (my >= 490 && my <= 590)
	{
		if (mx >= 654 && mx <= 754)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{
				level1  = false;
				level2  = false;
				level3  = false;
				level4  = false;
				
				menu    = false;
				loads   = false;
				options = false;

				//reseting boy position
				boyx = 200;
				boyy = 31;

				//activating cutscenes
				cutscenes[0] = true;
			}
		}

	}
	//Activating Options Page::
	if (my >= 390 && my <= 490)
	{
		if (mx >= 654 && mx <= 754)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{
				level1 = false;
				level2 = false;
				level3 = false;
				level4 = false;

				menu   = false;
				loads  = false;
				options= true;
			}
		}

	}
	//Activating Instructions Page::
	if (my >= 290 && my <= 390)
	{
		if (mx >= 654 && mx <= 754)
		{
			if (menu)
			{

				
				menu        = false;
				loads       = false;
				credits     = false;
				options     = false;
				instruction = true;

				level1 = false;
				level2 = false;
				level3 = false;
				level4 = false;
			
				
			}
		}

	}
	//Credit button
	if (my >= 190 && my <= 290)
	{
		if (mx >= 654 && mx <= 754)
		{
			if (menu)
			{
				
				menu        = false;
				loads       = false;
				options     = false;
				credits     = true;
				instruction = false;
				
				
				level1 = false;
				level2 = false;
				level3 = false;
				level4 = false;
				
			
			}
		}

	}

	//Exiting Game
	if (my >= 90 && my <= 190)
	{
		if (mx >= 654 && mx <= 754)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{
				exit(0);
			}

		}

	}

}

void mousedetect(int mx, int my)
{
	if (options)
	{
		//Load Button Detect::
		if (my >= 357 && my <= 457)
		{

			if (mx >= 654 && mx <= 754)
			{
				menupress[8] = true;
			}
			else
				menupress[8] = false;
		}
		else
			menupress[8] = false;

		//Music Button Detect
		if (my >= 257 && my <= 357)
		{

			if (mx >= 654 && mx <= 754)
			{
				menupress[9] = true;
			}
			else
				menupress[9] = false;
		}
		else
			menupress[9] = false;


		//MusicOff Button Detect
		if (my >= 157 && my <= 257)
		{

			if (mx >= 654 && mx <= 754)
			{
				menupress[10] = true;
			}
			else
				menupress[10] = false;
		}
		else
			menupress[10] = false;
	}
	if (!menu)
	{
		//Home Button
		if (my >= 600 && my <= 700)
		{
			if (mx >= 1450 && mx <= 1490)
			{
				press = true;
			}
			else
				press = false;
		}
		else
			press = false;

		//Save Button
		if (my >= 500 && my <=550)
		{
			if (mx >= 1450 && mx <= 1490)
			{
				menupress[6] = true;
			}
			else
			{
				menupress[6] = false;
				savepress = false;
			}
		}
		else
		{
			menupress[6] = false;
			savepress = false;
		}
	}

	//In Main  Menu Page::::::::::
	//Play Button::
	if (my >= 490 && my <= 590)
	{
		if (mx >= 654 && mx <= 754)
		{
			menupress[0] = true;
		}
		else
			menupress[0] = false;

	}
	else
		menupress[0] = false;

	//Options Button ::
	if (my >= 390 && my <= 490)
	{
		if (mx >= 654 && mx <= 754)
		{
			menupress[1] = true;
		}
		else
		{
			menupress[1] = false;
		}


	}
	else
	{
		menupress[1] = false;
	}


	//Tutorial Button:
	if (my >= 290 && my <= 390)
	{
		if (mx >= 654 && mx <= 754)
		{
			menupress[2] = true;
		}
		else
			menupress[2] = false;

	}
	else
		menupress[2] = false;

	//Credit Button
	if (my >= 190 && my <= 290)
	{
		if (mx >= 654 && mx <= 754)
		{
			menupress[3] = true;
		}
		else
		{
			menupress[3] = false;
		}

	}
	else
	{
		menupress[3] = false;
	}


	//Quit Button
	if (my >= 90 && my <= 190)
	{
		if (mx >= 654 && mx <= 754)
		{
			menupress[4] = true;
		}
		else
		{
			menupress[4] = false;
		}

	}
	else
	{
		menupress[4] = false;
	}

}

#endif // MOUSE_H_INCLUDED
