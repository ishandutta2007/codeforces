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

int n, m, k, i, j, kk, ans, s, a[105][105];

void dfs(int i, int s);

int main()
{
	scanf("%d %d %d", &n, &m, &kk);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	ans = kk + 1;
	if (n > kk)
	{
		for (i = 1; i <= n; i++)
		{
			s = 0;
			for (j = 1; j <= n; j++)
			{
				if (i == j)
					continue;
				int s1 = 0, s2 = 0;
				for (k = 1; k <= m; k++)
					if (a[i][k] == a[j][k])
						s1++;
					else
						s2++;
				s += min(s1, s2);
			}
			
			ans = min(ans, s);
		}		
	}
	
	else
		dfs(1, 0);
	
	if (ans > kk)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}

void dfs(int i, int s)
{
	int x, y;
	if (i > n)
	{
		for (x = 2; x <= m; x++)
		{
			int s1 = 0, s2 = 0;
			for (y = 1; y <= n; y++)
				if (a[y][x] == a[y][1])
					s1++;
				else
					s2++;
			s += min(s1, s2);
		}
		
		ans = min(ans, s);
		return;
	}
	
	dfs(i + 1, s);
	a[i][1] ^= 1;
	dfs(i + 1, s + 1);
	a[i][1] ^= 1;
}