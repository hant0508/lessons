// Вычислите a^20 , использовав не более пяти операций умножения.
#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "Введите число: ";
	cin >> a;
	a = a * a; // 2
	int b = a * a; // 4
	a = b * b; // 8
	a = a * a; // 16
	a = a * b; // 20
	cout << "a^20 равно: " << a << endl;
}
