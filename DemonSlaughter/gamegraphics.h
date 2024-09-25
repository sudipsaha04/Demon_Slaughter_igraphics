#ifndef GAMEGRAPHICS_H_INCLUDED
#define GAMEGRAPHICS_H_INCLUDED
#include"savegame.h"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::All Graphics Related Codes Are Here:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void menucode()
{
	
	
	//Main Menu Page
	if (menu)
	{
		
		iShowImage(0, 0, 1500, 650, menuimage);
		
		if (menupress[0])
		iShowImage(654, 490, 170, 100, button[3]);
	
		if (!menupress[0])
		iShowImage(654, 490 ,170, 100, button[2]);
		
		if (!menupress[1])
			iShowImage(654, 390, 170, 100, button[4]);
		if (menupress[1])
			iShowImage(654, 390, 170, 100, button[5]);
		
		if (!menupress[2])
			iShowImage(654, 290, 170, 100, button[8]);
		if (menupress[2])
			iShowImage(654, 290, 170, 100, button[9]);
		
		if (!menupress[3])
			iShowImage(654, 190, 170, 100, button[6]);
		if (menupress[3])
			iShowImage(654, 190, 170, 100, button[7]);

		if (!menupress[4])
			iShowImage(654, 90, 170, 100, button[10]);
		if (menupress[4])
			iShowImage(654, 90, 170, 100, button[11]);
		
	}

	//Instructions Page::
	if (instruction)
	{
		iShowImage(0, 0, 1500, 650, instructionimage);
		//home button
		if (press)
			iShowImage(1450, 600, 48, 48, button[0]);
		if (!press)
			iShowImage(1450, 600, 48, 48, button[1]);
	}
	//Credits Page::
	if (credits)
	{
		iShowImage(0, 0, 1500, 650,creditiimage);
		//home button
		if (press)
			iShowImage(1450, 600, 48, 48, button[0]);
		if (!press)
			iShowImage(1450, 600, 48, 48, button[1]);
	}
	//Options Page::
	if (options)
	{
		iShowImage(0, 0, 1500, 650, background[6]);

		//Load Button::
		if (!menupress[8])
		iShowImage(654, 357, 170, 100, button[15]);
		if (menupress[8])
		iShowImage(654, 357, 170, 100, button[16]);

		//Music Button::
		if (menupress[9])
			iShowImage(654, 257, 170, 100, button[17]);
		if (!menupress[9])
			iShowImage(654, 257, 170, 100, button[18]);
		
		//home button::
		if (press)
			iShowImage(1450, 600, 48, 48, button[0]);
		if (!press)
			iShowImage(1450, 600, 48, 48, button[1]);
		
		//music off:: 
		if (!menupress[10])
			iShowImage(654, 157, 170, 100, button[19]);
		if (menupress[10])
			iShowImage(654, 157, 170, 100, button[20]);
		
	}

	if (loads)
	{
		loadGame();
	}
}
//level1------------------------------------------------------------------------------------------------------------------------------------------------------
void level1code()
{

if (level1)
	{
		//Background::
		iShowImage(0, 0, 1600, 650, background[1]);
		
		
		//home button::
		if (press)
			iShowImage(1450, 600, 48, 48, button[0]);
		
		if (!press)
			iShowImage(1450, 600, 48, 48, button[1]);
		
		
		//save button
		if (menupress[7])
			iShowImage(1450, 500, 48, 48, button[14]);
		
		if (menupress[6])
			iShowImage(1450, 500, 48, 48, button[12]);
		
		if (!menupress[6] && !menupress[7] || savepress)
			iShowImage(1450, 500, 48, 48, button[13]);
		

		//Object::
		iShowImage(cratex, cratey, 39, 40, crate);

		//portal::
		iShowImage(portalx, portaly, 50, 100, portal[portalindex]);

		//Life

		if (lifcounter >= 1)
			iShowImage(10, 610, 60, 42, boylife[0]);
		if (lifcounter >= 2)
			iShowImage(30, 610, 60, 42, boylife[1]);
		if (lifcounter >= 3)
			iShowImage(50, 610, 60, 42, boylife[2]);
		if (lifcounter >= 4)
			iShowImage(70, 610, 60, 42, boylife[3]);
		if (lifcounter >= 5)
			iShowImage(90, 610, 60, 42, boylife[4]);

		//birds::
		iShowImage(birdsx, birdsy, 80, 60, bird[birdindex]);
		iShowImage(birdsx - 50, birdsy  -20, 80, 60, bird[birdindex]);
		iShowImage(birdsx + 50, birdsy - 20, 80, 60, bird[birdindex]);

	



		//Character::

		//Idle::
		if (standy)
			iShowImage(boyx, boyy, 60, 80, stand[boyindex2]);
		
		if (standyback)
			iShowImage(boyx, boyy, 60, 80, standback[boyindex2]);
		
		//Walk::
		if (!standy)
		{
			if (righty)
			{
				iShowImage(boyx, boyy, 60, 80, boy[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standy = true;
				}
			}
		}

		if (!standyback)
		{
			if (lefty)
			{
				iShowImage(boyx, boyy, 60, 80, lefto[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standyback = true;
				}
			}
		}

		/*//Instructions::
		if (rightgo)
		{
			iSetColor(255, 255, 0);
			iText(289, 180, "Hold 'D' To GO Right", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (leftgo)
		{
			iSetColor(255, 0, 0);
			iText(289, 180, "Hold 'A' To GO Left", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (upgo)
		{
			iSetColor(255, 0, 255);
			iText(289, 180, "Press 'W' To Jump", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
		if (catchinginfo == 0 && !leftgo && !rightgo && !upgo)
		{
			iSetColor(0, 255, 255);
			iText(500, 180, "Press 'C' To Interact", GLUT_BITMAP_TIMES_ROMAN_24);
		}*/
	}
}


//level2------------------------------------------------------------------------------------------------------------------------------------------------------
void level2code()
{

	if (level2)
	{
		//Background::
		iShowImage(0, 0, 1600, 650, background[2]);
		
		//home button::
		if (press)
			iShowImage(1450, 600, 48, 48, button[0]);

		if (!press)
			iShowImage(1450, 600, 48, 48, button[1]);


		//save button
		if (menupress[7])
			iShowImage(1450, 500, 48, 48, button[14]);

		if (menupress[6])
			iShowImage(1450, 500, 48, 48, button[12]);

		if (!menupress[6] && !menupress[7] || savepress)
			iShowImage(1450, 500, 48, 48, button[13]);

		
		
		
		

		//Life

		if (lifcounter >= 1)
			iShowImage(10, 610, 60, 42, boylife[0]);
		if (lifcounter >= 2)
			iShowImage(30, 610, 60, 42, boylife[1]);
		if (lifcounter >= 3)
			iShowImage(50, 610, 60, 42, boylife[2]);
		if (lifcounter >= 4)
			iShowImage(70, 610, 60, 42, boylife[3]);
		if (lifcounter >= 5)
			iShowImage(90, 610, 60, 42, boylife[4]);

		//portal::
		iShowImage(portalx, portaly, 50, 100, portal2[portalindex]);
		iShowImage(portalx+1540, portaly-10, 50, 100, portal[portalindex]);
		
		//frog 1::
		
		//idle
		if (frogshow&&rocky>=92)
		iShowImage(frogx, frogy, 80, 72, frog[frogindex]);
		
		//bite
		if (frogbite&&rocky>=92)
		{

			iShowImage(frogx, frogy, 80, 72, bite[biteindex]);
			iSetColor(0, 0, 0);
			iFilledCircle(bit, frogy + 10, 5);
			
		}
		
		
		//frog 2::
		
		//idle
		if (frogshow2 && rocky2 >= 64)
			iShowImage(frogx2, frogy2, 80, 72, frog[frogindex]);
		
		//bite
		if (frogbite2 && rocky2 >= 64)
		{
			iShowImage(frogx2, frogy2, 80, 72, bite[biteindex]);
			iSetColor(0, 0, 0);
			iFilledCircle(bit2, frogy2 + 10, 5);
		}



		//rock1::
		iShowImage(rockx, rocky, 53,55, rock);
		
		//rock2::
		iShowImage(rockx2, rocky2, 53, 55, rock);
		
		
		
		//trigger::
		if (!trigger)
		{
			iShowImage(40, 136, 50, 50, triggers[0]);
			iShowImage(397, 260, 60, 60, chain[0]);
		}

		if (trigger)
		{

			iShowImage(40, 136, 80, 100, triggers[4]);
			iShowImage(397, 260, 60, 60, chain[1]);
		}

		//biting trigger frog1
		if (boyx >= 310 && rocky>=200)
		{
			frogbite = true;
			frogshow = false;
		}
		else
		{
			frogbite = false;
			frogshow = true;
		}

		//biting trigger frog2
		if (boyx >= 850 && rocky2 >= 80&& boyy<=70)
		{
			frogbite2 = true;
			frogshow2 = false;
		}
		else
		{
			frogbite2 = false;
			frogshow2 = true;
		}

		
		
		//Character::::::::::::::::::::::::::::::::::::::::::
		if (standy)
			iShowImage(boyx, boyy, 60, 80, stand[boyindex2]);

		if (standyback)
			iShowImage(boyx, boyy, 60, 80, standback[boyindex2]);
		
		if (!standy)
		{
			if (righty)
			{
				iShowImage(boyx, boyy, 60, 80, boy[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standy = true;
				}
			}
		}
		
		if (!standyback)
		{
			if (lefty)
			{
				iShowImage(boyx, boyy, 60, 80, lefto[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standyback = true;
				}
			}
		}
	}
}


//level3------------------------------------------------------------------------------------------------------------------------------------------------------
void level3code()
{
	if (level3)
	{
		//Background::
		iShowImage(0, 0, 1600, 650, background[3]);

		//home button::
		if (press)
			iShowImage(1450, 600, 48, 48, button[0]);

		if (!press)
			iShowImage(1450, 600, 48, 48, button[1]);


		//save button
		if (menupress[7])
			iShowImage(1450, 500, 48, 48, button[14]);

		if (menupress[6])
			iShowImage(1450, 500, 48, 48, button[12]);

		if (!menupress[6] && !menupress[7] || savepress)
			iShowImage(1450, 500, 48, 48, button[13]);

		
		

		//Life

		if (lifcounter >= 1)
			iShowImage(10, 610, 60, 42, boylife[0]);
		if (lifcounter >= 2)
			iShowImage(30, 610, 60, 42, boylife[1]);
		if (lifcounter >= 3)
			iShowImage(50, 610, 60, 42, boylife[2]);
		if (lifcounter >= 4)
			iShowImage(70, 610, 60, 42, boylife[3]);
		if (lifcounter >= 5)
			iShowImage(90, 610, 60, 42, boylife[4]);
		//portal
		iShowImage(portalx, portaly - 20, 50, 100, portal2[portalindex]);
		iShowImage(portalx + 1540, portaly - 20, 50, 100, portal5[portalindex2]);

		if (angrybirdattack || rockstay)
		{
			iShowImage(rockx5, rocky5, 50, 50, rock);
		}

		if (angrybirdattack)
		{
			iShowImage(angrybirdx, 500, 200, 100, angrybird[angrybirdindex]);

		}
		



		//mushroom trigger
		if (on)
			iShowImage(940, 68, 50, 40, mushroom[0]);
		if (off)
			iShowImage(940, 68, 50, 30, mushroom[1]);

		//Character::
		if (standy)
			iShowImage(boyx, boyy, 60, 80, stand[boyindex2]);
		if (standyback)
			iShowImage(boyx, boyy, 60, 80, standback[boyindex2]);
		if (!standy)
		{
			if (righty)
			{
				iShowImage(boyx, boyy, 60, 80, boy[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standy = true;
				}
			}
		}
		if (!standyback)
		{
			if (lefty)
			{
				iShowImage(boyx, boyy, 60, 80, lefto[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standyback = true;
				}
			}
		}

	
		//Biting tree
		if (boyx >= 600)
			treeshow = true;
		else
			treeshow = false;

		if (treeshow && treealive)
		{
			iShowImage(EatTreex, EatTreey, treewidth, treeheight, Tree[EatTreeindex]);
		}
		else  if (!treeshow&&swordx <= EatTreex&&treealive)
		{
			iShowImage(EatTreex, EatTreey, treewidth, treeheight, Tree[0]);
		}
		//Bitting Tree 2
		if (monstertreestand )
			iShowImage(1170, 70, monstertreewidth, monstertreeheight, monstertrees[monstertreesindex]);
		
		if (monstertreebite )
			iShowImage(1170, 70,monstertreewidth, monstertreeheight, monstertreebites[monstertreebiteindex]);

		//sword
		if (catches&&treealive)
			iShowImage(boyx + 25, boyy + 15, 100, 40, sword[1]);
		else if (!catches&&!swordthrow && !treeshow&&treealive)
			iShowImage(swordx, swordy, 100, 60, sword[0]);
		if (swordthrow&&treealive)
			iShowImage(swordx, swordy, 100, 60, sword[1]);

	}

}




//level4------------------------------------------------------------------------------------------------------------------------------------------------------
void  level4code()
{
	if (level4)
	{
		iShowImage(0, 0, 1600, 650, background[7]);


		if (boyx > 1300)
		{
			standy = false;
			standyback = false;
			jumpy = false;
			down = false;
			catches = false;
			righty = false;
			lefty = false;
			congrats = true;
			congratsanimation = true;
		}

		if (congrats)
		{
			if(congratsanimation)
			iShowImage(500, 400, 600, 200, congratspic[congratsindex]);
		}
		//Character::
		if (standy&&!jumpy&&!down&&!catches)
			iShowImage(boyx, boyy, 60, 80, Tobistand[0]);

		if (standyback&&!jumpy&&!down&&!catches)
			iShowImage(boyx, boyy, 60, 80, Tobistand[1]);

		
		

		

		//Running Aniamtion::
		//Right
		if (!standy&&!catches)
		{
			if (righty&&!jumpy&&!down)
			{
				if (!jumpy)
					iShowImage(boyx, boyy, 60, 80, TobiRun[boyindex]);
				standcounter++;

				if (standcounter >= 2000)
				{
					standcounter = 0;
					boyindex = 0;
					standy = true;
				}
			}
		}

		//Left
		if (!standyback&&!catches)
		{
			if (lefty&&!jumpy&&!down)
			{
				if (!jumpy)
					iShowImage(boyx, boyy, 60, 80, TobiRunback[boyindex3]);
				standcounter++;
				if (standcounter >= 2000)
				{
					standcounter = 0;
					boyindex3 = 0;
					standyback = true;
				}

			}
		}
	}
}

void cutscenescodes()
{
	if (cutscenes[0])
	{
		iShowImage(0, 0, 1500, 650, cutsceneimage[0]);

		iShowImage(900, 10, 600, 50, cutsceneimage[1]);

		iShowImage(250, 300, 1090, 72, intromessages[intromessageindex]);
	}

	if (cutscenes[1])
	{
		iShowImage(0, 0, 1500, 650, cutsceneimage[2]);

		iShowImage(900, 10, 600, 50, cutsceneimage[1]);

		iShowImage(250, 300, 1090, 72, intromessages[intromessageindex]);
	}
}


#endif // GAMEGRAPHICS_H_INCLUDED
