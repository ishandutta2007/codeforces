#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <bitset>

using namespace std;
/*A
int main()
{
	int n;
	cin >> n;
	int arr[101][2];
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
		if(arr[i][1] - arr[i][0] >= 2)
		{
			count++;
		}
	}
	cout << count;
	
	return 0;
}*/

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	
	m++;
	
	long long arr[1010];
	long long rarr[1010] = {0};
	
	//int max = 0;
	//int temp = 0;
	
	for(int i = 0; i < m; i++)
	{
		cin >> arr[i];
		/*temp = ceil(log2((double)arr[i]));
		if(temp > max)
		{
			max = temp;
		}*/
	}
	
	
	int count = 0;
	int whilecount = 0;
	int crucial = 0;
	
	while(whilecount < n)
	{
		crucial = arr[m - 1] % 2;
		for(int i = 0; i < m - 1; i++)
		{
			if(arr[i] % 2 != crucial)
			{
				rarr[i]++;
			}
			arr[i] /= 2;
		}
		arr[m - 1] /= 2;
		whilecount++;
		crucial = 0;
	}
	for(int i = 0; i < m - 1; i++)
	{
		if(rarr[i] <= k)
		{
			count++;
		}
	}
	cout << count;
	return 0;
}