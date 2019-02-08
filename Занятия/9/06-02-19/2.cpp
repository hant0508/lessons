#include <iostream>
using namespace std;

int main()
{
	int a[10] = {0};
   	int b[10] = {0};
	int c[10], d[10];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char x;
		cin >> x;
		a[x-'0']++;
	}
	for (int i = 0; i < n; ++i)
	{
		char x;
		cin >> x;
		b[x-'0']++;
	}

	for (int i = 0; i < 10; ++i)
	{
		c[i] = a[i];
		d[i] = b[i];
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = i; j < 10; ++j)
		{
			if (a[i] >= b[j])
			{
				a[i] -= b[j];
				b[j] = 0;
			}
			else
			{
				b[j] -= a[i];
				a[i] = 0;
			}
		}
	}

	int p = 0, q = 0;
	for (int i = 0; i < 10; ++i)
		p += a[i];

	for (int i = 0; i < 9; ++i)
	{
		for (int j = i+1; j < 10; ++j)
		{
			if (c[i] >= d[j])
			{
				c[i] -= d[j];
				d[j] = 0;
			}
			else
			{
				d[j] -= c[i];
				c[i] = 0;
			}
		}
	}

	for (int i = 0; i < 10; ++i)
		q += c[i];

	cout << p << endl << n-q << endl;
}
