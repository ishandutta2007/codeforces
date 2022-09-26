#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <functional>
#include <cstring>

#define INF INT_MAX

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	
	int arr[101];
	int dif[101];
	dif[0] = 0;
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(i > 0)
		{
			dif[i] = arr[i] - arr[i - 1];
		}
	}
	
	
	int min = INF;
	
	for(int i = 1; i < n - 1; i++)
	{
		int maximum = -1;
		for(int j = 0; j < n - 1; j++)
		{
			if(j != i && j != i - 1)
			{
				maximum = max(maximum, dif[j + 1]);
			}
			else if(j == i - 1)
			{
				maximum = max(maximum, dif[j + 1] + dif[j + 2]);
			}
		}
		if(maximum < min)
		{
			min = maximum;
		}
	}
	
	cout << min << endl;
	return 0;
}