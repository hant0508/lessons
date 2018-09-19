// Напечатайте последнюю цифру заданного натурального числа.
#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "Введите число: ";
	cin >> a;
	cout << "Последняя цифра: " << a % 10 << endl;
}
