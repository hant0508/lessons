// Сумма простых чисел
#include <iostream>
using namespace std;

bool prime(int n)
{
	if (n < 2) // 1 - не простое число
		return 0;
	if (n < 4)
		return 1;

	for (int i = 2; i*i <= n; ++i)
		if (n % i == 0)
			return 0;

	return 1;
}

int main()
{
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (prime(a))
			sum += a;
	}

	cout << sum << endl;
	if (prime(sum))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
