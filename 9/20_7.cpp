#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	bool is_prime = true;

	if (a < 3)
		is_prime = false;

	for(int i = 2; i*i <= a; ++i)
	{
		if (a % i == 0)
		{
			is_prime = false;
			break;
		}
	}

	if (is_prime)
		cout << "Простое" << endl;
	else
		cout << "Не простое" << endl;
	
}
