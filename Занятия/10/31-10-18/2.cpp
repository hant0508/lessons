// Разворот
#include <iostream>
using namespace std;

void f(int n)
{
	int a;
	cin >> a;
	if (n > 1)
		f(n-1);
	cout << a << ' ';
}

int main()
{
	int n;
	cin >> n;
	f(n);
}
