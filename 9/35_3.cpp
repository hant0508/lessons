// Вычислите среднее арифметическое отрицательных элементов массива
#include <iostream>
using namespace std;

int main()
{
	const int n = 20;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand()%101 - 50;
		cout << a[i] << ' ';
	}
	cout << endl;

	int sum = 0, num = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] < 0)
		{
			sum += a[i];
			num++;
		}

	cout << sum/double(num) << endl;
}
