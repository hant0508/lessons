// Налоги
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
	while (1)
    {
        int x;
        cin >> x;
		if (x == -1) break;
        v.push_back(x);
    }
 
    int m = 0, pos = 1;
    for (int i = 0; i < v.size(); ++i)
    {
        int x;
        cin >> x;
        v[i] *= x;
        if (v[i] > m)
        {
            m = v[i];
            pos = i + 1;
        }
    }
 
    cout << pos << endl;
}
