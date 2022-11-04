#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, m, i, j, ans, now, need, a, b, Ok[1005][1005];
int e[10005], succ[10005], last[10005], sum;
int Hash[10005], pd[10005], tag;

int dfs(int i, int xx);

int main()
{
	scanf("%d %d", &n, &m);
	need = n + (n - 1) * 2;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		Ok[a][b] = 1;
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
	}
	
	ans = m + need;
	for (i = 1; i <= n; i++)
	{
		now = 0;
		for (j = 1; j <= n; j++)
			if (j != i)
				now += Ok[i][j] + Ok[j][i];
		now += Ok[i][i];
		for (j = 1; j <= n; j++)
			pd[j] = 0;
		for (j = 1; j <= n; j++)
		{
			if (j == i)
				continue;
			tag++;
			now += dfs(j, i);
		}
		
		ans = min(ans, m - now + need - now);
	}
	
	printf("%d\n", ans);
	return 0;
}

int dfs(int i, int xx)
{
	int x, y, temp;
	for (x = last[i]; x != 0; x = succ[x])
	{
		y = e[x];
		if (y == xx || Hash[y] == tag)
			continue;
		Hash[y] = tag;
		temp = pd[y], pd[y] = i;
		if (temp == 0 || dfs(temp, xx))
			return 1;
		pd[y] = temp;
	}
	
	return 0;
}