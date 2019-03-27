// Напечатайте все целые числа (квадраты чисел; чётные числа) 0 до n
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Введите число: ";
	cin >> n;
	for (int i = 0; i <= n; ++i)
		cout << i << ' ';
	cout << endl;
	for (int i = 0; i <= n; ++i)
		cout << i*i << ' ';
	cout << endl;
	for (int i = 0; i <= n; i+=2)
		cout << i << ' ';
}
