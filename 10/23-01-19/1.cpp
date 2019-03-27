#include <iostream>
#include "glcanvas.hpp"
using namespace std;
using namespace cnv;

void draw()
{
	// очистка экрана (цвет фона)
	clear(255, 255, 255);
	// окружность и круг (координаты центра и радиус)
	circle(100, 100, 20);
	circle_fill(240, 175, 25);
	// прямоугольники (координаты двух углов)
	rect(120, 150, 200, 450);
	rect_fill(500, 300, 520, 320);
	// отрезки (координаты концов)
	line(40, 40, 80, 80);
	line(80, 80, 20, 80);
	line(20, 80, 40, 40);
	// вывод текста
	position(300, 300);
	text_out << "Hello, world!";
	// вывод содержимого буфера в окно
	glutSwapBuffers();
}

int main()
{
	srand(time(0));
	window();
	glutDisplayFunc(draw);
	glutMainLoop();
}
