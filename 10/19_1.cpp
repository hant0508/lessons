// Найдите степени всех вершин графа
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream input ("m.txt");

	if (!input)
	{
		cout << "Ошибка загрузки файла" << endl;
		return 0;
	}

	int n;
	input >> n;
	vector<int> row(n);
	vector<int> col(n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int a;
			input >> a;
			row[i] += a;
			col[j] += a;
		}

	for (int i = 0; i < n; ++i)
		cout << i << ": " << row[i] + col[i] << endl;
}
