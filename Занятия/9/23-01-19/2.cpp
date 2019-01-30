// Асфальт под дождём
#include <iostream>
using namespace std;

int main()
{
	double l, d, t, v1, v2;
	cin >> l >> d >> t >> v1 >> v2;
	double t1 = d/v1;
	double t2 = (d + t*v2)/(v1 + v2);
	cout << min(t1, t2) + l/v1 << endl;
}
