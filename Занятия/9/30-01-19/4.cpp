// Замените нулями все элементы массива, являющиеся делителями максимального элемента.
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

	int m = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

	for (int i = 0; i < n; i++)
		if (m % a[i] == 0)
			a[i] = 0;

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
}
