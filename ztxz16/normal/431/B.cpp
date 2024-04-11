#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

void dfs(int i);

int i, j, v[16][16], a[16], Hash[16], ans;

int main()
{
	for (i = 1; i <= 5; i++)
		for (j = 1; j <= 5; j++)
			scanf("%d", &v[i][j]);
	ans = 0;
	dfs(1);
	printf("%d\n", ans);
	return 0;
}

void dfs(int i)
{
	if (i > 5)
	{
		int s = v[a[2]][a[3]] + v[a[3]][a[2]] + (v[a[1]][a[5]] + v[a[5]][a[1]]) * 2 + v[a[1]][a[3]] + v[a[3]][a[1]] + (v[a[5]][a[4]] + v[a[4]][a[5]]) * 2;
		ans = max(s, ans);
		return;
	}
	
	int x;
	for (x = 1; x <= 5; x++)
		if (Hash[x] == 0)
		{
			Hash[x] = 1;
			a[i] = x;
			dfs(i + 1);
			Hash[x] = 0;
		}
}