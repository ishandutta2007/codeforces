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
#include <cmath>
#define PQ priority_queue
#define OO 2147483647
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define MAX 100000

int FASTBUFFER;

using namespace std;

typedef long long ll;

void dfs(ll i, ll p, ll s);
ll calc(ll Min, ll Max, ll x);

typedef long long ll;

ll n, m, l, r, mo, i, j, ans, now, a, tot, Min, Max, b[14];
ll Hash[MAX + 5];
ll sq[MAX + 5][14];

int main()
{
	for (i = 2; i <= MAX; i++)
	{
		if (Hash[i] == 1)
			continue;
		for (j = i; j <= MAX; j += i)
			sq[j][++sq[j][0]] = i, Hash[j] = 1;
	}
	
	cin >> n >> m >> l >> r >> mo;
	if (l == 1)
		ans += (n + 1) * m % mo;
	ans %= mo;
	for (a = 1; a <= r && a <= n; a++)
	{
		tot = sq[a][0];
		for (j = 1; j <= tot; j++)
			b[j] = sq[a][j];
		if (a > l)
			Min = 0;
		else
			Min = (ll)sqrt(l * l - a * a);
		while (Min * Min + a * a < l * l)
			Min++;
		Max = (ll)sqrt(r * r - a * a) + 5;
		while (Max * Max + a * a > r * r)
			Max--;
		Max = min(Max, m);
		if (Min > Max)
			continue;
		now = 0;
		dfs(1, 1, 0);
		ans += (now * (n - a + 1)) % mo;
		ans %= mo;
	}
	
	cout << ans << endl;
	return 0;
}

void dfs(ll i, ll p, ll s)
{
	if (i > tot)
	{
		if (s)
			now -= calc(Min, Max, p);
		else
			now += calc(Min, Max, p);
		now %= mo;
		while (now < 0)
			now += mo;
		now %= mo;
		return;
	}
	
	dfs(i + 1, p * b[i], 1 - s);
	dfs(i + 1, p, s);
}

ll calc(ll Min, ll Max, ll x)
{
	ll l = Min / x * x, r = Max / x * x;
	ll a, b, c;
	if (Min % x)
		l += x;
	a = (m - r + 1) + (m - r + 1);
	b = (m - l + 1) + (m - l + 1);
	c = (r - l) / x + 1;
	if (l == 0)
		return (a + b) * c / 2 - (m - l + 1);
	else
		return (a + b) * c / 2;
}