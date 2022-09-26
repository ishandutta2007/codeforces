#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	int i, j, count2 = 4;
	//bool count = false;
	
	int m, n;
	cin >> n >> m;
	int array[n][m];
	
	for(i = 0 ; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			cin >> array[i][j];
		}
	}
	
	for(i = 0; i < m; i++)
	{
		if(array[0][i] == 1 || array[n - 1][i] == 1)
		{
			count2 = 2;
			break;
		}
	}
	
	if(count2 == 4)
	{
		for(i = 1; i < n; i++)
		{
			if(array[i][m - 1] == 1 || array[i][0] == 1)
			{
				count2 = 2;
				break;
			}
		}
	}
	
	cout << count2;
	return 0;
}