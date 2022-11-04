#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int i, int f, int id);

int n, i, a, b, t1, t2;
int e[200005], succ[200005], last[200005], sum;
pair <int, int> s1[200005], s2[200005];

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	dfs(1, 0, 0);
	printf("%d\n", t1);
	for (i = 1; i <= t1; i++)
		printf("%d %d %d\n", 2, s1[i].first, s1[i].second);
	for (i = 1; i <= t2; i++)
		printf("%d %d\n", s2[i].first, s2[i].second);
	return 0;
}

void dfs(int i, int f, int id)
{
	int x, now = id;
	for (x = last[i]; x; x = succ[x])
	{
		if (e[x] == f)
			continue;
		s1[++t1] = make_pair(i, e[x]);
		if (now)
			s2[++t2] = make_pair(now, t1), now = t1;
		else
			now = t1;
		dfs(e[x], i, t1);
	}
}