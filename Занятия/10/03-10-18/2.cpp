// Школьный этап олимпиады 2014-2015
// 2. Манхэттен
#include <iostream>
using namespace std;

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int dx = max(x1 - x2, x2 - x1);
	int dy = max(y1 - y2, y2 - y1);

	for (int i = 0; i < dx; ++i)
	{
		if (x1 < x2)
			cout << 'E';
		else
			cout << 'W';
	}

	for (int i = 0; i < dy; ++i)
	{
		if (y1 < y2)
			cout << 'N';
		else
			cout << 'S';
	}
}
