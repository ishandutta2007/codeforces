#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
#define OO 2147483647

using namespace std;

multiset <char> ss[105];
int n, i, j, s, t, len, ans1, ans2, Hash[1005], lim[105];
int e[200005], succ[200005], last[200005], val[200005], cost[200005], sum;
int dis[200005], pre[200005], sq[200005];
char str[105], c;

void add(int a, int b, int c, int d);
void spfa();
void work();

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	len = strlen(str + 1);
	for (i = 1; str[i]; i++)
		Hash[str[i]]++;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%s", str + 1);
		for (j = 1; str[j]; j++)
			ss[i].insert(str[j]);
		scanf("%d", &lim[i]);
	}
	
	s = 1, t = 1 + 26 + n + 1, sum = 1;
	for (i = 1; i <= n; i++)
		add(27 + i, t, lim[i], i);
	for (c = 'a'; c <= 'z'; c++)
	{
		if (!Hash[c])
			continue;
		add(s, c - 'a' + 2, Hash[c], 0);
		for (i = 1; i <= n; i++)
			add(c - 'a' + 2, 27 + i, ss[i].count(c), 0);
	}
	
	while (1)
	{
		spfa();
		if (dis[t] == OO)
			break;
		work();
	}
	
	if (ans1 == len)
		printf("%d\n", ans2);
	else
		printf("-1\n");
	return 0;
}

void add(int a, int b, int c, int d)
{
	e[++sum] = b, succ[sum] = last[a], last[a] = sum;
	e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	val[sum - 1] = c;
	cost[sum - 1] = d, cost[sum] = -d;
}

void spfa()
{
	int h, tt, now, x;
	for (i = 1; i <= t; i++)
		dis[i] = OO;
	dis[s] = 0;
	sq[1] = s;
	for (h = tt = 1; h <= tt; h++)
	{
		now = sq[h];
		for (x = last[now]; x != 0; x = succ[x])
			if (val[x] && dis[now] + cost[x] < dis[e[x]])
				dis[e[x]] = dis[now] + cost[x], sq[++tt] = e[x], pre[e[x]] = x;
	}
}

void work()
{
	int now, x = OO;
	for (now = t; now != s; now = e[pre[now] ^ 1])
		x = min(x, val[pre[now]]);
	ans1 += x;
	for (now = t; now != s; now = e[pre[now] ^ 1])
		val[pre[now]] -= x, val[pre[now] ^ 1] += x, ans2 += x * cost[pre[now]];
}