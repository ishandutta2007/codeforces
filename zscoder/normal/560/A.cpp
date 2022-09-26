#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int x;
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		if(x == 1)
		{
			ans = -1;
		}
	}
	cout << ans << endl;
	return 0;
}