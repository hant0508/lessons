// Определите, сколько из 10 введённых символов являются буквами
#include <iostream>
using namespace std;

int main()
{
	int k = 0;

	for (int i = 0; i < 10; ++i)
	{
		char c;
		cin >> c;
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) k++;
	}

	cout << k << endl;
}
