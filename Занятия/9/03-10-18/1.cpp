// Напечатайте n звёздочек, не вводя дополнительную переменную
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Введите число: ";
	cin >> n;
	for (; n > 0; --n) // можно ещё проще: while(n--)
		cout << "*";
}
