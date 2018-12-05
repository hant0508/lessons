// Выведите цифры числа справа налево через пробел
#include <iostream>
using namespace std;

void digitsRTL(int n)
{
	if (n > 0)
   	{
		cout << n % 10 << ' ';
		digitsRTL(n/10);
	}
}

int main()
{
	int n;
	cin >> n;
	digitsRTL(n);
}
