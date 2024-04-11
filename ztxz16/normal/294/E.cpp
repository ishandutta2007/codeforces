#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll n, i, a, b, c;
ll e[100005], succ[100005], last[100005], val[100005], size[100005], sum;
ll Ans, S1, S2, Min, xx, an, A, Now;

void dfs(ll i, ll f, ll s);
void dfs2(ll i, ll f, ll v);

int main()
{
	scanf("%I64d", &n);
	for (i = 1; i < n; i++)
	{
		scanf("%I64d %I64d %I64d", &a, &b, &c);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
		val[sum] = val[sum - 1] = c;
	}
	
	for (i = 1; i < sum; i += 2)
	{
		if (i == 11)
			i = 11;
		Ans = S1 = S2 = Min = 0;
		dfs(e[i], e[i + 1], 0);
		Now = size[e[i]];
		xx = Min;
		dfs2(e[i], e[i + 1], 0);
		S1 = Min;
		
		Min = 0;
		dfs(e[i + 1], e[i], 0);
		Now = size[e[i + 1]];
		xx = Min;
		dfs2(e[i + 1], e[i], 0);
		S2 = Min;
		
		an = Ans + (S1 * size[e[i + 1]]) + (S2 * size[e[i]]) + val[i] * size[e[i]] * size[e[i + 1]];
		if (i == 1 || an < A)
			A = an;
	}
	
	printf("%I64d\n", A);
	return 0;
}

void dfs(ll i, ll f, ll s)
{
	ll x;
	size[i] = 1;
	Min += s;
	for (x = last[i]; x != 0; x = succ[x])
	{
		if (e[x] == f)
			continue;
		dfs(e[x], i, s + val[x]);
		size[i] += size[e[x]];
	}
	
	return;
}

void dfs2(ll i, ll f, ll v)
{
	ll x;
	Ans += (v * size[i] * (Now - size[i]));
	xx -= (size[i] * v);
	xx += ((Now - size[i]) * v);
	if (xx < Min)
		Min = xx;
	for (x = last[i]; x != 0; x = succ[x])
	{
		if (e[x] == f)
			continue;
		dfs2(e[x], i, val[x]);
	}
	
	xx += (size[i] * v);
	xx -= ((Now - size[i]) * v);
	return;
}