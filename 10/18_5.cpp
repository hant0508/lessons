// Определите, сколько в графе петель
#include <iostream>
#include <fstream>
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

	int res = 0;

	for (int i = 0; i < n; ++i)
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
