// Определите, есть ли прямая дорога из города i в город j
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream input ("matrix.txt");

	if (!input)
	{
		cout << "Ошибка загрузки файла" << endl;
		return 0;
	}
	
	int m, n;
	input >> m >> n;

	int res = 0;
	int p, q;
	cin >> p >> q;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int a;
			input >> a;
			if (i == p-1 && j == q-1)
			{
				res += a;
				break;
			}
		}
	}

	if (res)
		cout << "Дорога есть" << endl;
	else
		cout << "Дороги нет" << endl;
}
