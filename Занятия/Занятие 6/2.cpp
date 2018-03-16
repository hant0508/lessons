// Демо ОГЭ 2018
#include <iostream>
using namespace std;

int main()
{
	int n, M = 30000;
	cin >> n; // Не пишем cout << "Ввведите число"
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (M > a && a % 10 == 4)
			M = a;
	}
	cout << M << endl;
}
