// Школьный этап олимпиады 2018-2019
// Задача 1. Улица
#include <iostream>
using namespace std;

int main()
{
	// считываем 2 целых числа
	int a, b;
	cin >> a >> b;

	// если А больше В, меняем местами их значения
	if (a > b)
		swap(a, b);
	// теперь В не превосходит А

	// Отдельно рассматриваем ситуацию, когда нам нужно пойти вверх
	// через дорогу по диагонали (например, из 2 в 5)
	if (a % 2 == 0 && b % 2 == 1)
		b++; // из 2 в 5 идти столько же, сколько из 2 в 6

	cout << (b-a)/2 << endl;
}
