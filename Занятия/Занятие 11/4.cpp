#include <iostream>
using namespace std;

int main()
{
	string s, w;
	getline(cin, s);
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'x')
			w += "58";
		else 
			w += s[i];
	}
	cout << w << endl;
}
