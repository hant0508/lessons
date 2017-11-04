// Калькулятор
#include <iostream>
using namespace std;

int main()
{
	double a, b;
	char c;
	cin >> a >> c >> b;

	if (c == '+')
		cout << a+b;
	else if (c == '-')
		cout << a-b;
	else if (c == '*')
		cout << a*b;
	else if (c == '/' && b != 0)
		cout << a/b;
	else
		cout << "Ошибка";
}
