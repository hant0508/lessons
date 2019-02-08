#include <iostream>
#include <glcanvas.hpp>
using namespace std;
using namespace cnv;

int width = 600, height = 600;

enum Direction{LEFT, UP, RIGHT, DOWN};

class Food
{
public:
	int x;
	int y;
	int r;
	color_t c;

	Food(): respawn(){}

	void respawn()
	{	
		r(10);
	   	x(rand()%(width-r));
	   	y(rand()%(height-r));
	   	c(hexcolor(255,0,0)); 
	}

	void draw()
	{
		circle_fill(x, y, r, c);
	}
};

struct Part
{
	int x, y;
};

class Snake
{
	int x, y;
	Direction d;
	vector<Part> body;
	int size;
	color_t c;

public:
	Snake(): x(width/2-size/2), y(height/2-size/2), d(RIGHT), size(20), c(hexcolor(180,150,0)){} 

	void draw()
	{
		rect_fill(x,y,x+size,y+size,c);
		for(int i = 0; i < body.size(); ++i)
			rect_fill(body[i].x,body[i].y,body[i].x+size,body[i].y+size,c);
	}

	void move()
	{
		x+=((d==RIGHT)-(d==LEFT));
		y+=((d==DOWN)-(d==UP));
	}

	void turn(Direction dir)
	{
		d = dir;
		cout << dir << endl;
	}

	Direction get_d()
	{
		return d;
	}
// Not done
	void eat(Food& ciomi)
	{
		if(((x >= ciomi.x-r && x <= ciomi.x+r)&&(y >= ciomi.y-r && y <= ciomi.y+r))||
		((x >= ciomi.x-r && x <= ciomi.x+r)&&(y+size >= ciomi.y-r && y+size <= ciomi.y+r))||
		{

			body.push_back();
		}
	}

	void grow()
	{

	}


	
};

Snake pete;
Food ciomi;

void display();
void tick(int);
void keyboard(int key, int mx, int my);
void key(unsigned char key, int mx, int my);

int main()
{
	window(width, height);

	glutDisplayFunc(display);
	glutTimerFunc(1, tick, 1);
	glutSpecialFunc(keyboard);
	glutKeyboardFunc(key);
	glutMainLoop();
}

void display()
{
	clear(255,255,255,255);

	ciomi.draw();
	pete.draw();

	glutSwapBuffers();
}


void tick(int)
{
	pete.move();
	if()

	glutPostRedisplay();
	glutTimerFunc(10, tick, 1);
}

void keyboard(int key, int mx, int my)
{
	switch(key)
	{
		case GLUT_KEY_LEFT  : if(pete.get_d() != RIGHT) pete.turn(LEFT); break; 
		case GLUT_KEY_UP    : if(pete.get_d() != DOWN) pete.turn(UP); break; 
		case GLUT_KEY_RIGHT : if(pete.get_d() != LEFT) pete.turn(RIGHT); break; 
		case GLUT_KEY_DOWN  : if(pete.get_d() != UP) pete.turn(DOWN); break; 
	}
	glutPostRedisplay();
}

void key(unsigned char key, int mx, int my)
{
	if(key == 27) 
		exit(EXIT_SUCCESS);
}


