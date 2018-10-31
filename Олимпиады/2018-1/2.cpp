// Школьный этап олимпиады 2018-2019
// Задача 2. Надёжное крепление
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (b <= a && a <= c || c <= a && a <= b) // A между B и С
			cout << a << endl;
	if (a <= b && b <= c || c <= b && b <= a) // B между A и C
			cout << b << endl;
	if (a <= c && c <= b || b <= c && c <= a) // C между A и B
			cout << c << endl;
}
