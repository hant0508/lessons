// Подсчёт букв
#include <iostream>
using namespace std;

bool letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main()
{
	char ch[3];
	cin >> ch[0] >> ch[1] >> ch[2];
	cout << letter(ch[0]) + letter(ch[1]) + letter(ch[2]);
}
