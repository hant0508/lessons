// Счастливый билет
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int a = n % 10 + (n/10) % 10 + (n/100) % 10;
	n /= 1000;
	int b = n % 10 + (n/10) % 10 + (n/100) % 10;

	if (a == b)
		cout << "YES";
	else
		cout << "NO";
}
