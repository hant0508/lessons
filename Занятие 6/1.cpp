#include <iostream>
using namespace std;

int main()
{
	int n, a = 0;
	cout << "Введите число: ";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		a += i + i + 1;
		cout << a << ' ';
	}
}
