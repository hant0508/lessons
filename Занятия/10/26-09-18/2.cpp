// В одном шаге от счастья
#include <iostream>
using namespace std;

bool lucky(int n)
{
	int r = 0, l = 0;

	for (int i = 0; i < 3; ++i)
	{
		r += n % 10;
		n /= 10;
	}

	for (int i = 0; i < 3; ++i)
	{
		l += n % 10;
		n /= 10;
	}

	return l == r;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (lucky(a - 1) || lucky(a + 1))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
