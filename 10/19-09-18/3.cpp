// Cуммы цифр
#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
	int s = 0;
	while (n)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main()
{
	int n;
	cin >> n;
	int res = n;
	int pr = n;
	while (1)
	{
		n = sumOfDigits(n);
		res += n;
		if (n == pr)
			break;
		pr = n;
	}

	cout << res << endl;
}
