// Вычислите сумму элементов массива
#include <iostream>
using namespace std;

int main()
{
	const int n = 20;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand()%101 - 50;
		cout << a[i] << ' ';
	}
	cout << endl;

	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i];

	cout << sum << endl;
}
