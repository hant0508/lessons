// Определить, является ли введённое число чётным
#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	if (a % 2) // аналогично (a % 2 != 0)
		cout << "Нечётное";
	else
		cout << "Чётное";
}
