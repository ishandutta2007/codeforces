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
int lca(int a, int b);
int check(int ans);
void Del(int i);
void Add(int i);
void calc(int ans);

set <int> s;
set <int>::iterator it1, it2;
int n, k, a, b, i, j, l, r, mid, dis[200005], dfn[200005], pos[200005], tot;
int e[200005], succ[200005], last[200005], sum;
int f[200005][21], zl[200005], h, t, Now, x;
long long ans1, ans2, now;

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	dis[1] = 0;
	zl[1] = 1;
	for (h = t = 1; h <= t; h++)
	{
		Now = zl[h];
		for (x = last[Now]; x != 0; x = succ[x])
		{
			if (e[x] == f[Now][0])
				continue;
			f[e[x]][0] = Now, dis[e[x]] = dis[Now] + 1, zl[++t] = e[x];
		}
	}
	
	for (j = 1; j <= 20; j++)
		for (i = 1; i <= n; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	dfs(1);
	l = 1, r = n;
	while (l < r)
	{
		mid = ((l + r + 1) >> 1);
		if (check(mid) == 1)
			l = mid;
		else
			r = mid - 1;
	}
	
	printf("%d\n", l);
	return 0;
}

void dfs(int i)
{
	int x;
	dfn[i] = ++tot, pos[tot] = i;
	for (x = last[i]; x != 0; x = succ[x])
		if (dfn[e[x]] == 0)
			dfs(e[x]);
	return;
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

int check(int ans)
{
	s.clear();
	now = 0;
	ans1 = ans2 = 0;
	for (i = 1; i <= ans; i++)
		Add(i);
	calc(ans);
	if (now + 1 <= k)
		return 1;
	for (i = 2; i + ans - 1 <= n; i++)
	{
		Del(i - 1);
		Add(i + ans - 1);
		calc(ans);
		if (now + 1 <= k)
			return 1;
	}
	
	return 0;
}

void Del(int i)
{
	int Now = dfn[i], succ, next;
	ans1 -= dis[i];
	it1 = s.lower_bound(Now);
	if (it1 == s.begin())
		succ = 0;
	else
		it1--, succ = (*it1);
	it2 = s.upper_bound(Now);
	if (it2 == s.end())
		next = 0;
	else
		next = (*it2);
	if (succ != 0)
		ans2 -= dis[lca(pos[succ], i)];
	if (next != 0)
		ans2 -= dis[lca(pos[next], i)];
	if (succ != 0 && next != 0)
		ans2 += dis[lca(pos[next], pos[succ])];
	s.erase(Now);
}

void Add(int i)
{
	int Now = dfn[i], succ, next;
	ans1 += dis[i];
	it1 = s.lower_bound(Now);
	if (it1 == s.begin())
		succ = 0;
	else
		it1--, succ = (*it1);
	it2 = s.upper_bound(Now);
	if (it2 == s.end())
		next = 0;
	else
		next = (*it2);
	if (succ != 0)
		ans2 += dis[lca(pos[succ], i)];
	if (next != 0)
		ans2 += dis[lca(pos[next], i)];
	if (succ != 0 && next != 0)
		ans2 -= dis[lca(pos[next], pos[succ])];
	s.insert(Now);
}

void calc(int ans)
{
	int dn = dis[lca(pos[*s.begin()], pos[*(--s.end())])];
	now = ans1;
	now -= ans2;
	now -= dn * ans;
	now += dn * (ans - 1);
}