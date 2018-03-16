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

	for (int i = 0; i < n-1; i+=2)
	{
		int t = a[i];
		a[i] = a[i+1];
		a[i+1] = t;
	}

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
}
