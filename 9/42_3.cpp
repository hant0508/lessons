// Проверьте, верно ли расставлены скобки в строке
#include <iostream>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int a = 0;

	bool res = true;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(') ++a;
		else if (s[i] == ')') --a;
		if (a < 0)
		{
			res = false;
			break;
		}
	}

	if (res && a == 0)
		cout << "Скобочная последовательность правильная" << endl;
	else 
		cout << "Скобочная последовательность неправильная" << endl;
}
