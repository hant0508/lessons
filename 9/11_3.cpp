// Вычислить модуль введённого числа
#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	if (a < 0) a = -a;
	cout << a;
}
