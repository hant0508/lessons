// ОГЭ-3
#include <iostream>
using namespace std;

int main()
{
	int s = 0;
	while (1)
	{
		int a;
		cin >> a;
		if (a == 0)
			break;

		if (a > 9 && a < 100 & a % 8 == 0)
			s += a;
	}

	cout << s << endl;
}
