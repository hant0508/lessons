#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Введите число: ";
	cin >> n;
	for (; n > 0; --n)
		cout << "*";
}
