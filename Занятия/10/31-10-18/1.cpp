// Числа Фибоначчи без рекурсии
#include <iostream>
using namespace std;

unsigned long long fib(int n)
{
	int a = 1, b = 1;
	for (int i = 2; i < n; ++i)
	{
		a = a+b;
		b = a-b;
	}
	return a;
}

int main()
{
	int n;
	cin >> n;
	cout << fib(n);
}
