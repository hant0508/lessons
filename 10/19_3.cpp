// Проверьте, является ли заданный граф регулярным
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

	bool regular = true;
	bool deg = row[0] + col[0];
	for (int i = 1; i < n; ++i)
		if (row[i] + col[i] != deg)
		{
			regular = false;
			break;
		}

	if (regular)
		cout << "Граф регулярный" << endl;
	else
		cout << "Граф не регулярный" << endl;
}
