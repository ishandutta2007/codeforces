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

int n, m, k, now, i, j, x, a, b, c, kk;
int f[505][505], top, color;
int type[100005], belong[100005], dfn[100005], low[100005], s[100005], Hash[100005], tot;
int e[300005], succ[300005], last[300005], val[300005], sum;

void dfs(int i);

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	now = 0;
	for (i = 1; i <= k; i++)
		for (j = 1; j <= k; j++)
			if (i == j)
				f[i][j] = 0;
			else
				f[i][j] = 1000000001;
		
	for (i = 1; i <= k; i++)
	{
		scanf("%d", &x);
		for (j = now + 1; j <= now + x; j++)
			type[j] = i;
		now += x;
	}
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum, val[sum] = c;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum, val[sum] = c;
		if (type[a] != type[b])
		{
			a = type[a], b = type[b];
			f[a][b] = min(f[a][b], c);
			f[b][a] = min(f[b][a], c);
		}
	}
	
	for (i = 1; i <= n; i++)
		if (dfn[i] == 0)
			dfs(i);
	for (i = 2; i <= n; i++)
	{
		if (type[i] == type[i - 1] && belong[i] != belong[i - 1])
		{
			printf("No\n");
			return 0;
		}
	}
	
	for (kk = 1; kk <= k; kk++)
		for (i = 1; i <= k; i++)
			for (j = 1; j <= k; j++)
				f[i][j] = min(f[i][j], f[i][kk] + f[kk][j]);
	printf("Yes\n");
	for (i = 1; i <= k; i++)
		for (j = 1; j <= k; j++)
		{
			if (f[i][j] == 1000000001)
				f[i][j] = -1;
			if (j == k)
				printf("%d\n", f[i][j]);
			else
				printf("%d ", f[i][j]);
		}
		
	return 0;
}

void dfs(int i)
{
	int x, y;
	dfn[i] = low[i] = ++tot;
	Hash[i] = 1;
	s[++top] = i;
	for (x = last[i]; x != 0; x = succ[x])
	{
		if (val[x] > 0)
			continue;
		y = e[x];
		if (dfn[y] == 0)
			dfs(y), low[i] = min(low[i], low[y]);
		else if (Hash[y] == 1)
			low[i] = min(low[i], dfn[y]);
	}
	
	if (dfn[i] == low[i])
	{
		color++;
		while (s[top] != i)
			belong[s[top]] = color, Hash[s[top]] = 0, top--;
		belong[s[top]] = color, Hash[s[top]] = 0, top--;
	}
}