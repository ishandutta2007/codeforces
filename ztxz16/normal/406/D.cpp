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
#define eps 1e-9

int FASTBUFFER;

using namespace std;

int n, i, j, h, t, m, Now, x, top, a, b, xx[100005], s[200005];
int e[200005], succ[200005], last[200005], sum;
int f[200005][22];
int dis[200005], sq[200005];
long long yy[100005];

void add(int a, int b);
int lca(int a, int b);

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %I64d", &xx[i], &yy[i]);
	s[++top] = n;
	for (i = n - 1; i >= 1; i--)
	{
		while (top > 1 && (long double)yy[i] + (long double)(yy[s[top - 1]] - yy[i]) / (long double)(xx[s[top - 1]] - xx[i]) * (long double)(xx[s[top]] - xx[i]) - yy[s[top]] > eps)
			top--;
		add(s[top], i);
		s[++top] = i;
	}
	
	dis[n] = 1;
	sq[1] = n;
	for (h = t = 1; h <= t; h++)
	{
		Now = sq[h];
		for (x = last[Now]; x != 0; x = succ[x])
		{
			if (e[x] == f[Now][0])
				continue;
			f[e[x]][0] = Now, dis[e[x]] = dis[Now] + 1, sq[++t] = e[x];
		}
	}
	
	for (j = 1; j <= 20; j++)
		for (i = 1; i <= n; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
		scanf("%d %d", &a, &b), printf("%d\n", lca(a, b));
	return 0;
}

void add(int a, int b)
{
	//printf("%d %d\n", a, b);
	e[++sum] = b, succ[sum] = last[a], last[a] = sum;
	e[++sum] = a, succ[sum] = last[b], last[b] = sum;
}

int lca(int a, int b)
{
	int i;
	if (dis[a] < dis[b])
		swap(a, b);
	for (i = 20; i >= 0; i--)
		if (dis[f[a][i]] >= dis[b])
			a = f[a][i];
	for (i = 20; i >= 0; i--)
		if (f[a][i] != f[b][i])
			a = f[a][i], b = f[b][i];
	if (a == b)
		return a;
	return f[a][0];
}