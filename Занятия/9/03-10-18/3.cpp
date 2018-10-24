// Напечатайте все делители числа n
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Введите число: ";
	cin >> n;
	for (int i = 1; i <= n; ++i) // начинаем с 1
	{
		if (n % i == 0)
			cout << i << ' ';
	}
}
