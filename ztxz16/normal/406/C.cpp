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

int n, m, a, b, i, s, tot, du[100005], dis[200005], father[200005];
int e[200005], succ[200005], last[200005], sum;
int Hash[200005], sq[200005];
vector <int> sur[200005];
pair <int, pair <int, int> > ans[200005];

void dfs(int i);
void work(int s);

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		du[a]++, du[b]++;
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	for (i = 1; i <= n; i++)
	{
		if (Hash[i])
			continue;
		s = 0;
		dfs(i);
		if ((s / 2) & 1)
		{
			printf("No solution\n");
			return 0;
		}
		
		work(i);
	}
	
	for (i = 1; i <= m / 2; i++)
		printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
	return 0;
}

void dfs(int i)
{
	if (Hash[i])
		return;
	s += du[i], Hash[i] = 1;
	for (int x = last[i]; x; x = succ[x])
		dfs(e[x]);
}

void work(int s)
{
	int h, t, now, x, i, j;
	dis[s] = 1, sq[1] = s;
	for (h = t = 1; h <= t; h++)
	{
		now = sq[h];
		for (x = last[now]; x; x = succ[x])
			if (!dis[e[x]])
				dis[e[x]] = dis[now] + 1, sq[++t] = e[x], father[e[x]] = now;
	}
	
	for (i = t; i >= 1; i--)
	{
		now = sq[i];
		for (x = last[now]; x; x = succ[x])
			if (dis[e[x]] < dis[now] - 1 || (dis[e[x]] == dis[now] && e[x] < now) || (dis[e[x]] == dis[now] - 1 && e[x] != father[now]))
				sur[now].push_back(e[x]);
		x = sur[now].size();
		for (j = 0; j + 1 < x; j += 2)
			ans[++tot] = make_pair(sur[now][j], make_pair(now, sur[now][j + 1]));
		if (x & 1)
			ans[++tot] = make_pair(sur[now][x - 1], make_pair(now, father[now]));
		else
			sur[father[now]].push_back(now);
	}
}