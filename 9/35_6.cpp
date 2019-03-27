// Определите значение максимального элемента в массиве и его положение
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

	int m = a[0], res = 0;
	for (int i = 1; i < n; ++i)
		if (a[i] > m)
		{
			m = a[i];
			res = i;
		}

	cout << m << ' ' << res << endl;
}
