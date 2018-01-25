// Автобусная экскурсия
#include <iostream>
using namespace std;

int main()
{
	bool crash = false;
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		if (a <= 437)
		{
			crash = true;
			k = i;
			break;
		}
	}

	if (crash) cout << "Crash " << k << endl;
	else cout << "No crash" << endl;
}
