// Секрет
#include <iostream>
using namespace std;

int main()
{
	string s;
	int g = 0, b = 0;

	while (getline(cin, s))
	{
		cout << s << endl;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'g' || s[i] == 'G') g++;
			if (s[i] == 'b' || s[i] == 'B') b++;
		}
	}

	if (g > b)
		cout << "GOOD" << endl;
	else if (b > g)
		cout << "BAD" << endl;
	else 
		cout << "NEUTRAL" << endl;
}
