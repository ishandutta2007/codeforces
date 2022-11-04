#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> Wait[100005], Rel[100005];
int n, m, i, j, a, b, c, tot, Next[200005];
int e[200005], succ[200005], last[200005], val[200005], sum;
int Now, x, dis[100005];
int zl[5000005], h, t;

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
		val[sum] = val[sum - 1] = c;
	}
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &tot);
		for (j = 1; j <= tot; j++)
			scanf("%d", &x), Wait[i].push_back(x);
		if (tot > 0)
		{
			Next[tot - 1] = x + 1;
			for (j = tot - 2; j >= 0; j--)
				if (Wait[i][j] == Wait[i][j + 1] - 1)
					Next[j] = Next[j + 1];
				else
					Next[j] = Wait[i][j] + 1;
			for (j = 0; j < tot; j++)
				Rel[i].push_back(Next[j]);
		}
	}
	
	for (i = 1; i <= n; i++)
		dis[i] = 2147483647;
	if (Wait[1].size() == 0 || Wait[1][0] != 0)
		dis[1] = 0;
	else
		dis[1] = Rel[1][0];
	zl[1] = 1;
	for (h = t = 1; h <= t; h++)
	{
		Now = zl[h];
		for (x = last[Now]; x != 0; x = succ[x])
		{
			int T, l, r, mid;
			T = dis[Now] + val[x];
			if (e[x] != n)
			{
				l = 0, r = Wait[e[x]].size() - 1;
				while (l < r)
				{
					mid = ((l + r + 1) >> 1);
					if (Wait[e[x]][mid] <= T)
						l = mid;
					else
						r = mid - 1;
				}
			
				if (l == r && Wait[e[x]][l] == T)
					T = Rel[e[x]][l];
			}
			
			if (T < dis[e[x]])
				dis[e[x]] = T, zl[++t] = e[x];
		}
	}
	
	if (dis[n] == 2147483647)
		dis[n] = -1;
	printf("%d\n", dis[n]);
	return 0;
}