// Перепись
#include <iostream>
using namespace std;

int main()
{
	int n;
	int res = -1, age = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int a;
		char s;
		cin >> a >> s;
		if (s == 'M' && a > age)
		{
			age = a;
			res = i;
		}
	}

	cout << res << endl;
}
