// ОГЭ-2
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int m;
	cin >> m;
	for (int i = 1; i < n; ++i)
	{
		int a;
		cin >> a;
		if (a < m)
			m = a;
	}

	cout << m << endl;

	if (m < -15)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
}
