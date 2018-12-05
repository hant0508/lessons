// Выведите все нечётные элементы последовательности (0 - признак конца)
#include <iostream>
using namespace std;

void oddElements()
{
	int a;
	cin >> a;
	if (a % 2)
		cout << a << ' ';
	if (a)
		oddElements();
}

int main()
{
	oddElements();
}
