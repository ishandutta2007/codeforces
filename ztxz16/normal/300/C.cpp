#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define mo 1000000007
#define ll long long

using namespace std;

ll a, b, n, i, x, y, Now, Ans, f[1000005];
ll list[1005], tot;

void dfs(ll i, ll s, ll x);
ll sumi(ll a, ll b);

int main()
{
	scanf("%I64d %I64d %I64d", &a, &b, &n);
	f[0] = 1;
	for (i = 1; i <= n; i++)
		f[i] = f[i - 1] * i % mo;
	dfs(1, 0, 1);
	for (i = 1; i <= tot; i++)
	{
		if ((list[i] - a * n) % (b - a) != 0)
			continue;
		y = (list[i] - a * n) / (b - a);
		x = n - y;
		if (x < 0 || y < 0)
			continue;
		Now = f[n];
		Now *= sumi(f[x], mo - 2);
		Now %= mo;
		Now *= sumi(f[y], mo - 2);
		Now %= mo;
		Ans += Now;
		Ans %= mo;
	}
	
	printf("%I64d\n", Ans);
	return 0;
}

void dfs(ll i, ll s, ll x)
{
	if (i > 8)
		return;
	if (i > 1)
		list[++tot] = s;
	dfs(i + 1, s + a * x, x * 10);
	dfs(i + 1, s + b * x, x * 10);
	return;
}

ll sumi(ll a, ll b)
{
	ll ret = 1, c = a, i;
	for (i = 1; i <= b; (i <<= 1))
	{
		if ((b & i) > 0)
			ret *= c, ret %= mo;
		c *= c, c %= mo;
	}
	
	return ret;
}