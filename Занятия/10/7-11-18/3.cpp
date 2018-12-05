// Выведите цифры числа слева направо через пробел
#include <iostream>
using namespace std;

void digitsLTR(int n)
{
	if (n > 0)
   	{
		digitsLTR(n/10);
		cout << n % 10 << ' ';
	}
}

int main()
{
	int n;
	cin >> n;
	digitsLTR(n);
}
