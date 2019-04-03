// Проверьте, является ли заданный граф ориентированным
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
	vector<vector<int>> matrix(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int a;
			input >> a;
			matrix[i][j] = a;
		}

	bool directed = true;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (matrix[i][j] != matrix[j][i])
			{
				directed = false;
				break;
			}

	if (directed)
		cout << "Граф ориентированный" << endl;
	else
		cout << "Граф неориентированный" << endl;
}
