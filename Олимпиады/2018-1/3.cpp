// Школьный этап олимпиады 2018-2019
// Задача 3. Парад
#include <iostream>
using namespace std;

int main()
{
	int res = 0;
	int n;
	cin >> n;

	// цикл с единицы, а не с нуля; до n включительно
	for (int i = 1; i*i <= n; ++i)
	{
		if (n % (i*i) == 0) // скобки обязательны
			res = i*i;
	}

	cout << res << endl;
}
