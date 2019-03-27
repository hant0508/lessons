// Определите, каких букв в строке больше: маленьких или больших
#include <iostream>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int a = 0, b = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'a' && s[i] <= 'z') a++;
		if (s[i] >= 'A' && s[i] <= 'Z') b++;
	}
	
	if (a < b)
		cout << "Маленьких меньше" << endl;
	else if (a > b)
		cout << "Маленьких больше" << endl;
	else
		cout << "Поровну" << endl;
}
