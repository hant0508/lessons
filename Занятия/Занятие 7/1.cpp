// Задача 3 "Не про спиннеры", школьный этап ВОШ 2017/18
#include <iostream>
using namespace std;

int main()
{
	long long x, y;
	cin >> x >> y;
	cout << x*(x+1)/2 * (1+y)*y/2;
}
