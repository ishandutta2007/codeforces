#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Size 320

using namespace std;

int n, m, i, j, a, b, pos[100005], color[100005];
int e[200005], succ[200005], last[200005], sum;
int Left[200005], Right[200005], s[200005], val[200005], ans[200005], Ans[200005], tot;

struct Query
{
	int l, r, v, tag;
	
	friend bool operator < (Query a, Query b)
	{
		return (pos[a.l] < pos[b.l] || (pos[a.l] == pos[b.l] && a.r < b.r));
	}
}Q[100005];

void dfs(int i, int f);
void add(int val);
void del(int val);

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &color[i]);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	for (i = 1; i <= n; i++)
		pos[i] = pos[i - 1] + (i % Size == 1);
	dfs(1, 0);
	for (i = 1; i <= m; i++)
		scanf("%d %d", &a, &b), Q[i].l = Left[a], Q[i].r = Right[a], Q[i].v = b, Q[i].tag = i;
	sort(Q + 1, Q + m + 1);
	for (i = Q[1].l; i <= Q[1].r; i++)
		add(val[i]);
	for (i = 1; i <= m; i++)
	{
		if (i != 1)
		{
			int l1 = Q[i - 1].l, r1 = Q[i - 1].r, l2 = Q[i].l, r2 = Q[i].r;
			if (l1 < l2)
			{
				for (j = l1; j < l2; j++)
					del(val[j]);
			}
			
			else
			{
				for (j = l2; j < l1; j++)
					add(val[j]);
			}
			
			if (r1 < r2)
			{
				for (j = r1 + 1; j <= r2; j++)
					add(val[j]);
			}
			
			else
			{
				for (j = r2 + 1; j <= r1; j++)
					del(val[j]);
			}
		}
		
		ans[Q[i].tag] = Ans[Q[i].v];
	}
	
	for (i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}

void dfs(int i, int f)
{
	int x;
	Left[i] = ++tot;
	val[tot] = color[i];
	for (x = last[i]; x != 0; x = succ[x])
		if (e[x] != f)
			dfs(e[x], i);
	Right[i] = tot;
}

void add(int val)
{
	s[val]++, Ans[s[val]]++;
}

void del(int val)
{
	Ans[s[val]]--, s[val]--;
}