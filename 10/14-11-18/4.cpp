// Вычислите сумму каждого столбца матрицы
#include <iostream>
#include <fstream>
#include <vector>
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
	vector<int> s(n);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int a;
			input >> a;
			s[j] += a;
		}
	}

	for (int i = 0; i < n; ++i)
		cout << s[i] << ' ';
}
