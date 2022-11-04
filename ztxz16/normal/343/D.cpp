#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

int n, i, a, b, q, m1, m2, tot;
int e[1000005], succ[1000005], last[1000005], sum;
int dfs_Left[1000005], dfs_Right[1000005];
int Left[2000005], Right[2000005], Max[2000005], tag[2000005];

void dfs(int i, int fa);
void Make(int l, int r, int i);
void Work(int l, int r, int i, int v, int kind);

int main()
{
	scanf("%d", &n);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	dfs(1, 0);
	Make(1, n, 1);
	scanf("%d", &q);
	for (i = 1; i <= q; i++)
	{
		scanf("%d %d", &a, &b);
		if (a == 1)
			Work(dfs_Left[b], dfs_Right[b], 1, i, 1);
		else if (a == 2)
			Work(dfs_Left[b], dfs_Left[b], 1, i, 2);
		else
		{
			m1 = 0, Work(dfs_Left[b], dfs_Right[b], 1, i, 3);
			m2 = 0, Work(dfs_Left[b], dfs_Left[b], 1, i, 4);
			if (m1 >= m2)
				printf("0\n");
			else
				printf("1\n");
		}
	}
	
	return 0;
}

void dfs(int i, int fa)
{
	int x;
	dfs_Left[i] = ++tot;
	for (x = last[i]; x != 0; x = succ[x])
	{
		if (e[x] == fa)
			continue;
		dfs(e[x], i);
	}
	
	dfs_Right[i] = tot;
	return;
}

void Make(int l, int r, int i)
{
	int mid = ((l + r) >> 1);
	Left[i] = l, Right[i] = r;
	if (l == r)
		return;
	Make(l, mid, (i << 1));
	Make(mid + 1, r, ((i << 1) | 1));
	return;
}

void Work(int l, int r, int i, int v, int kind)
{
	int lc, rc;
	if (l > Right[i] || r < Left[i])
		return;
	if (l <= Left[i] && r >= Right[i])
	{
		if (kind == 1)
			tag[i] = v;
		else if (kind == 2)
			Max[i] = v;
		else if (kind == 3)
		{
			if (Max[i] > m1)
				m1 = Max[i];
		}
		
		else
			m2 = tag[i];
		return;
	}
	
	lc = (i << 1), rc = (lc | 1);
	if (tag[i] != 0)
	{
		if (tag[i] > tag[lc])
			tag[lc] = tag[i];
		if (tag[i] > tag[rc])
			tag[rc] = tag[i];
		tag[i] = 0;
	}
	
	Work(l, r, lc, v, kind);
	Work(l, r, rc, v, kind);
	if (Max[lc] > Max[rc])
		Max[i] = Max[lc];
	else
		Max[i] = Max[rc];
	return;
}