// Напечатайте все числа от 1 до n
#include <iostream>
using namespace std;

void f(int n)
{
	if (n > 1)
		f(n-1);
	cout << n << ' ';
}

int main()
{
	int n;
	cin >> n;
	f(n);
}
