#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <climits>

#define INF INT_MAX;

using namespace std;
/*A
int main()
{
	ios_base::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	
	int arr[30001];
	for(int i = 0; i < n - 1; i++)
	{
		cin >> arr[i];
	}
	
	int current = 0;
	bool possible = false;
	while(current < t)
	{
		if(current == t - 1)
		{
			possible = true;
			break;
		}
		else
		{
			if(current >= n - 1)
			{
				break;
			}
			else
			{
				current += arr[current];
			}
		}
	}
	if(possible)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}*/
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int arr[301][301];
	int perm[301];
	int index[301];
	
	for(int i = 0; i < n; i++)
	{
		cin >> perm[i];
		index[perm[i] - 1] = i;
	}
	
	/*for(int i = 0; i < n; i++)
	{
		cout << index[i] << " ";
	}
	cout << endl;*/
	
	for(int i = 0; i < n; i++)
	{
		char temp[301];
		cin >> temp;
		for(int j = 0; j < n; j++)
		{
			arr[i][j] = temp[j] - 48;
		}
	}
	
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;*/
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(arr[i][j] == 1)
			{
				for(int k = j + 1; k < n; k++)
				{
					if(arr[i][k] == 1)
					{
						arr[k][j] = 1;
						arr[j][k] = 1;
					}
				}
			}
		}
	}
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}*/
	int ans[301];
	memset(ans, -1, sizeof(ans));
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(ans[j] == -1)
			{
				if(j == index[i])
				{
					ans[j] = i+1;
					break;
				}
				else
				{
					if(arr[index[i]][j] == 1)
					{
						ans[j] = i+1;
						break;
					}
					else
					{
					}
				}
			}
		}
	}
	
	for(int i = 0;i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}