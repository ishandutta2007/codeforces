#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll n, i, a, b, h, t, xx;
ll zl[100005], v[100005], tag[100005], father[100005];
ll e[200005], last[200005], succ[200005], sum;
ll Ans, Now, x, xxx[100005], yy[100005];

void dfs(ll i, ll fa);

int main()
{
	scanf("%I64d", &n);
	for (i = 1; i < n; i++)
	{
		scanf("%I64d %I64d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	for (i = 1; i <= n; i++)
		scanf("%I64d", &v[i]);
	dfs(1, 0);
	printf("%I64d\n", xxx[1] + yy[1]);
	return 0;
}

void dfs(ll i, ll fa)
{
	ll x;
	for (x = last[i]; x != 0; x = succ[x])
	{
		if (fa == e[x])
			continue;
		dfs(e[x], i);
		if (xxx[e[x]] > xxx[i])
			xxx[i] = xxx[e[x]];
		if (yy[e[x]] > yy[i])
			yy[i] = yy[e[x]];
	}
	
	if (xxx[i] - yy[i] + v[i] > 0)
		yy[i] = xxx[i] + v[i];
	else
		xxx[i] = yy[i] - v[i];
	return;
}