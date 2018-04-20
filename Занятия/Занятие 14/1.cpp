// Унарная систем счисления
#include <iostream>
using namespace std;

void translate(int n)
{
	if (n < 0)
	{
		cout << '-';
		n = -n;
	}

	while (n--)
		cout << '|' << ' ';
	cout << endl;
}

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	translate(x);
	translate(y);
	translate(z);
}
