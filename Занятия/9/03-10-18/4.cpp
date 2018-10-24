// Проверьте, является ли введенное натуральное число степенью тройки
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Введите число: ";
	cin >> n;
	while(n % 3 == 0)
		n /= 3;
	if (n == 1)
		cout << "Cтепень тройки";
	else
		cout << "Не степень тройки";
}
