// Запишите матрицу, умноженную на 2, в файл "out.txt"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream input ("matrix.txt");
	ofstream out ("out.txt");

	if (!input | !out)
	{
		cout << "Ошибка загрузки файла" << endl;
		return 0;
	}
	
	int m, n;
	input >> m >> n;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int a;
			input >> a;
			out << a*2 << ' ';
		}
		out << endl;
	}
}
