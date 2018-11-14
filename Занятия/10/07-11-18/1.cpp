// Сумма цифр числа
#include <iostream>
using namespace std;

int sum(int n)
{
	if (n > 9)
		return n%10 + sum(n/10);
	else
		return n;
}

int main()
{
	int n;
	cin >> n;
	cout << sum(n) << endl;
}
