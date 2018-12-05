// Определите, сколько в графе петель
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

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int a;
			input >> a;
			if (i == j)
			{
				res += a;
			}
		}
	}

	cout << res << endl;
}
