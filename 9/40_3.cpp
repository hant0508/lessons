// Если введённый символ является строчной буквой латинского алфавита, переведите его в верхний регистр
#include <iostream>
using namespace std;

int main()
{
	char c;
	cin >> c;

	if (c >= 'a' && c <= 'z')
		c += 'A'-'a';

	cout << c << endl;
}
