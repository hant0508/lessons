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

	int M = a[0], m = a[0], Mpos = 0, mpos = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > M)
		{
			M = a[i];
			Mpos = i;
		}
		if (a[i] < m)
		{
			m = a[i];
			mpos = i;
		}
	}

	a[Mpos] = m;
	a[mpos] = M;

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
}
