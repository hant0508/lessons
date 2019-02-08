#include <iostream>
using namespace std;

int main()
{
	int arr[3] = {0, 1, 2};
	int n, x;
	cin >> n >> x;
	n %= 6;
	for (int i = 0; i < n; ++i)
		swap(arr[i%2], arr[i%2+1]);
	cout << arr[x] << endl;
}
