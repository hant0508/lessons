// Сумма цифр
#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	int a1 = a/100;
	int a2 = (a/10) % 10;
	int a3 = a % 10;
	cout << a1 + a2 + a3;
}
