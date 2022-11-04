#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, k, i, x, j;
vector <int> v[100005];

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", &x), v[x].push_back(i);
	if (v[0].size() != 1)
	{
		printf("-1\n");
		return 0;
	}
	
	if (v[1].size() > k)
	{
		printf("-1\n");
		return 0;
	}
	
	for (i = 2; i < n; i++)
	{
		if ((long long)v[i - 1].size() * (k - 1) < v[i].size())
		{
			printf("-1\n");
			return 0;
		}
	}
	
	printf("%d\n", n - 1);
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < v[i].size(); j++)
			printf("%d %d\n", v[i][j], v[i - 1][j % v[i - 1].size()]);
	}
	
	return 0;
}