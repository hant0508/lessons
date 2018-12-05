// Выведите все элементы последовательности с нечётными номерами (0 - признак конца)
#include <iostream>
using namespace std;

void oddPositions()
{
	int a;
	cin >> a;
	cout << a << ' ';
	cin >> a;
	if (a)
		oddPositions();
}

int main()
{
	oddPositions();
}
