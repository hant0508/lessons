#include <iostream>
#include "../../../tmp/glcanvas.hpp"
using namespace std;
using namespace cnv;

int W = 640, H = 480;
bool PAUSED = false;

// typedef unsigned int color_t;
void triangle(float x1, float y1, float x2, float y2, float x3, float y3, color_t c = 0x000000ff)
{
	line(x1, y1, x2, y2, c);
	line(x2, y2, x3, y3, c);
	line(x3, y3, x1, y1, c);
}

void triangle_fill(float x1, float y1, float x2, float y2, float x3, float y3, color_t c=0x000000ff)
{
	glBegin(GL_TRIANGLE_FAN);
		color(c);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
	glEnd();
}

color_t randcolor(int op)
{
	return hexcolor(rand()%256, rand()%256, rand()%256, op);
}

void key(unsigned char key, int mx, int my)
{
	switch(key)
	{
		case 27: // Esc
			exit(0);
		case 13: // Enter
			PAUSED = !PAUSED;
	}
}

class Triangle
{
	public:
		int x1, y1, x2, y2, x3, y3;
		int alpha;
		int delay;
		int speed;
		bool fading = false;
		color_t col;

		Triangle()
		{
			randcoords();
		}

		void randcoords()
		{
			x1 = rand()%(W-100)+50;
			y1 = rand()%(H-100)+50;	
			x2 = x1+rand()%101-50;
			y2 = y1+rand()%101-50;
			x3 = x1+rand()%101-50;
			y3 = y1+rand()%101-50;
			col = randcolor(0);
			alpha = 0;
			delay = rand()%500;
			speed = rand()%5+1;
		}

		void opacity()
		{
			if(delay)
			{
				delay--;
				return;
			}

			if(alpha >= 255)
			   	fading = true;
			else if(alpha <= 0 && fading)
			{
				fading = false;
				randcoords();
			}

			if(fading)
			{
				alpha -= speed;
				if(alpha > 0)
					col-=speed;
			}
			else
			{
				alpha += speed;
				if(alpha < 255)
					col += speed;
			}
		}
};

const int COUNT = 512;
Triangle figures[COUNT];

void draw()
{
	clear(255, 255, 255);

	for(int i = 0; i < COUNT; i++)
		triangle_fill(figures[i].x1, figures[i].y1, figures[i].x2, figures[i].y2, figures[i].x3, figures[i].y3, figures[i].col);

	glutSwapBuffers();
}

void tick(int)
{
	if (!PAUSED)
		for(int i = 0; i < COUNT; i++)
			figures[i].opacity();

	glutPostRedisplay();
	glutTimerFunc(10, tick, 1);
}

int main()
{
	srand(time(0));
	window(W, H);
	glutDisplayFunc(draw);
	glutKeyboardFunc(key);
	tick(0);
	glutMainLoop();
}
