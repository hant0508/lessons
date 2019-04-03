// Школьный этап олимпиады 2017-2018
// Задача 2. Снова спиннеры
#include <iostream>
using namespace std;

int main()
{
	int m;
	cin >> m;
	int a = 4 * (m % 3); // количество лопастей на четырёхлопастные спиннеры
	int b = m - a; // все остальные - на трёхлопастные
	if (b < 0) // m = 1, 2, 5
		cout << 0 << endl << 0 << endl;
	else
		cout << b/3 << endl << a/4 << endl;
}
