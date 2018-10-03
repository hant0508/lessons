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

	for (int i = 0; i < n; ++i)
			if (a[i]%2) // здесь не надо писать == 1; остаток от деления в C++ бывает отрицательным
				a[i] = i;

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
}
