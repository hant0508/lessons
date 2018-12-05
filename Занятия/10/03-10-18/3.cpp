// Школьный этап олимпиады 2014-2015
// 3. Пятница, 13-е
#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int month = 1;

	for(;month <= n && k != 5; ++month)
		k = (k + 30) % 7;

	if (month > n)
		cout << 0 << endl;
	else
		cout << (1 + (n - month) / 7) << endl;
}
