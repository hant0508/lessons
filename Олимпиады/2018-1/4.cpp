// Школьный этап олимпиады 2018-2019
// Задача 4. Парад
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	// если количество кратно четырём, можем обнулить каждую четёрку
	// a - (a+1) - (a+2) + (a+3) == 0
	if (n % 4 == 0)
		for (int i = 0; i < n/4; ++i)
			cout << "+--+";

	else if (n % 4 == 3)
   	{
		// 1 + 2 - 3 == 0, сводим к первому случаю
		cout << "++-";
		for (int i = 0; i < (n-3)/4; ++i)
			cout << "+--+";
	}

	else
		cout << "IMPOSSIBLE" << endl;

}
