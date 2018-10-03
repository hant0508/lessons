// Количество цифр
#include <iostream>
using namespace std;

bool digit(char c) 
{
	return (c >= '0' && c <= '9');
}

int main()
{
	char ch[3];
	cin >> ch[0] >> ch[1] >> ch[2];
	cout << digit(ch[0]) + digit(ch[1]) + digit(ch[2]);
}
