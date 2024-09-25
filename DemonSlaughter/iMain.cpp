#include "iGraphics.h"
#include "bitmap_loader.h"
#include "variables.h"
#include"gamegraphics.h"
#include"keyboard.h"
#include"animation.h"
#include"ImageLoad.h"
#include"savegame.h"
#include"mouse.h"
#include"stdio.h"

void iDraw()
{
	iClear();
	menucode();
	level1code();
	level2code();
	level3code();
    level4code();
    cutscenescodes();

}
void iMouseMove(int mx, int my)
{
	
}
void iMouse(int button, int state, int mx, int my)
{
	printf("%d %d", mx, my);
	mouse(button, state, mx, my);
}
void iKeyboard(unsigned char key)
{
	masterkey(key);

}
void iPassiveMouse(int mx, int my)
{
	mousedetect(mx, my);
}
void iSpecialKeyboard(unsigned char key)
{
	specialkey(key);
}
int main()
{
	iSetTimer(50,jumper);
	iSetTimer(200, standanimation);
	iSetTimer(100, portalanimation);
	iSetTimer(140, birdanimation);
	iSetTimer(500, cutsceneanmation);
	

	iInitialize(1500, 650, "Demon Slaughter");
	ImageLoad();
	iStart();
	return 0;
}
