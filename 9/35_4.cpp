// Вычислите произведение элементов массива, значения которых попадают в отрезок [l, r]
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

	int mult = 1;
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; ++i)
		mult *= a[i];

	cout << mult << endl;
}
