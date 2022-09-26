#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		if(i% 2 == 0)
		{
			for(int i = 0; i < m; i++)
			{
				cout << "#";
			}
		}
		else if(i % 4 == 1)
		{
			for(int i = 0; i < m - 1; i++)
			{
				cout << ".";
			}
			cout << "#";
		}
		else
		{
			cout << "#";
			for(int i = 0; i < m - 1; i++)
			{
				cout << ".";
			}
		}
		cout << endl;
	}
	return 0;
}