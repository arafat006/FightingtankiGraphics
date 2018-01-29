# include "iGraphics.h"

int bulletcontrol = 0;
int bulletindx=200, bulletindy = 261;
int tempbulletindx;
int bulletindxlock = 0;
int hide_bullet = 0;

int lifelevel = 4;

int tank1indx = 200, tank1indy = 126;//1

int plane2indx = 470, plane2indy = 500;//2

int dx = 5;

void iDraw()
{
	//place your drawing codes here
	iClear();

	//background picture :::::::::
	iShowBMP2(0, 0, "pic//background2.bmp", -1);
	//life level ::::::::::::
	iShowBMP2(1085, 650, "pic//lifelevel.bmp", -1);

	//plane life :::::::::
	if (lifelevel>0)
	iShowBMP2(1085, 645, "pic//life.bmp", 0);
	if (lifelevel>1)
	iShowBMP2(1110, 645, "pic//life.bmp", 0);
	if (lifelevel>2)
	iShowBMP2(1135, 645, "pic//life.bmp", 0);
	if (lifelevel>3)
	iShowBMP2(1160, 645, "pic//life.bmp", 0);
	//
	//life text ::::::::::::
	iSetColor(0,0,255);
	iText(1040, 665, "LIFE");

	//bullet :::::::::::::
	if (bulletindxlock == 0)
	{
		bulletindx = tank1indx + 57;
	}
	else
	{
		bulletindx = tempbulletindx;
	}

	if (bulletcontrol == 1)
	{
		bulletindy += 5;
	}

	//if (hide_bullet == 1)
	{
		if ((bulletindy > 490) && (hide_bullet == 1))
		{
			bulletindxlock = 0;
			bulletindy = 261;
			bulletcontrol = 0;
			//hide_bullet = 0;
		}
	}
	//else
	{
		if (bulletindy > 700)
		{
			bulletindxlock = 0;
			bulletindy = 261;
			bulletcontrol = 0;
		}
	}
	if (bulletindy)
	{
		iShowBMP2(bulletindx, bulletindy, "pic//bullet.bmp", 0);
	}
	
	iShowBMP2(tank1indx , tank1indy, "pic//tank1(180).bmp", 0);
	
	if (dx > 0)
	{
		iShowBMP2(plane2indx, plane2indy, "pic//plane3.bmp", 0);
	}
	else if (dx < 0)
	{
		iShowBMP2(plane2indx, plane2indy, "pic//plane3.2.bmp", 0);
	}
	//gameover ::::::::::::::::::
	if (lifelevel<1)
	iShowBMP2(200,300, "pic//Gameover.bmp", 0);

	else if (bulletindy > 485)
	{
		bulletindxlock = 0;
	}

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (lifelevel > 0)
		{
			if (bulletindxlock == 0)
			{
				bulletcontrol = 1;
				bulletindxlock = 1;
				tempbulletindx = tank1indx + 57;
			}
		}
		//printf("%d  %d\n", mx, my);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
	//place your code here
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (key == 's')
	{

	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_RIGHT)
	{
		if (1050>tank1indx)
		{
			if(lifelevel > 0)
				tank1indx += 5;
		}
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (0 < tank1indx)
		{
			if (lifelevel>0)
				tank1indx -= 5;
		}
		
	}
	//place your codes for other keys here
}
void planecontrol2()
{

	if (plane2indx > 1040)
	{
		dx = dx* -1;
	}
	if (plane2indx <10)
	{
		dx = dx* -1;
	}

	if (lifelevel > 0)
	{
		plane2indx += dx;
	}
	else
	{
		if (plane2indy>300)
		plane2indy-=5;
	}

}
void bullettouchcontrol()
{
	if (bulletindy>plane2indy - 15)
	{
		if ((bulletindx + 35 > plane2indx) && (bulletindx + 35 < plane2indx + 182))
		{
			hide_bullet = 1;
			lifelevel--;

		}
	}
}
//
int main()
{
	iSetTimer(1,planecontrol2);
	iSetTimer(1,bullettouchcontrol);

	//place your own initialization codes here.
	iInitialize(1243, 700, "Fighter Tank");
	return 0;
}
