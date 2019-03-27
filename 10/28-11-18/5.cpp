// Определите, сколько в графе изолированных вершин вершин
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
	vector<int> row(m);
	vector<int> col(n);

	int res = 0;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int a;
			input >> a;
			row[i] += a;
			col[j] += a;
		}
	}

	for (int i = 0; i < n; ++i) // имеет смысл только при n == m
	{
		if (row[i] + col[i] == 0)
			res++;
	}

	cout << res << endl;
}
