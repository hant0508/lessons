// Школьный этап олимпиады 2018-2019
// Задача 5. Клад
#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int x = 0, y = 0, n = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9') // формируем число
			n = n*10 + s[i] - '0'; // ord('0')
		else
		{ // перемещаемся 
			if (s[i] == 'N')
				y += n;
			if (s[i] == 'S')
				y -= n;
			if (s[i] == 'E')
				x += n;
			if (s[i] == 'W')
				x -= n;
			n = 0;
		}
	}

	if (x > 0)
		cout << x << 'E';
	else if (x < 0)
		cout << -x << 'W';
	if (y > 0)
		cout << y << 'N';
	else if (y < 0)
		cout << -y << 'S';
}
