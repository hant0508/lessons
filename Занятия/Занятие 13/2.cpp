#include <iostream>
using namespace std;

int reverse(int n)
{
	int res = 0;
	while (n)
	{
		res *= 10;
		res += n%10;
		n /= 10;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		cout << a;
		if (a == reverse(a))
			cout << ": Yes" << endl;
		else
		   	cout << ": No" << endl;
	}
}
