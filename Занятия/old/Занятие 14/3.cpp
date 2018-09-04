// Суммы цифр
#include <iostream>
using namespace std;

int sum(int n)
{
	int res = 0;
	while (n)
	{
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	int s = n;

	while (1)
	{
		int x = sum(n);
		s += x;
		if (n == x) break;
		n = x;
	}
	
	cout << s << endl;
}
