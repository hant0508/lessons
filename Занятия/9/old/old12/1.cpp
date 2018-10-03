// Контроперация
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	while (1)
	{
		int x;
		cin >> x;
		if (x == 0) break;
		v.push_back(x);
	}

	int ma = v[0], mi = v[0];

	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] > ma) ma = v[i];
		if (v[i] < mi) mi = v[i];
	}

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == ma) v[i] = mi;
		cout << v[i] << ' ';
	}
}
