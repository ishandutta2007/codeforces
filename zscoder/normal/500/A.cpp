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
}