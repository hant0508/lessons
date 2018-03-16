#include <iostream>
using namespace std;

int main()
{
	int n, M = 0;
	cout << "Введите количество чисел: ";
	cin >> n;
	cout << "Введите числа: ";
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (a > M)
			M = a;
	}
	cout << M << endl;
}
