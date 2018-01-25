// Монетки	
#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		sum += a;
	}

	if (sum < n-sum) cout << sum << endl;
	else cout << n-sum << endl;
}
