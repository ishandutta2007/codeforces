#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7, Maxn = 500005;
int n, m, S, fa[Maxn], fa2[Maxn], siz[Maxn];
bool flag[Maxn], flag2[Maxn];
long long T = 1;
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	if (a < b) swap(a, b);
	if (a != b)
	{
		fa[a] = b;
		flag[b] |= flag[a];
		siz[b] += siz[a];
	}
}
int get_fa2(int x)
{
	return x == fa2[x] ? x : fa2[x] = get_fa2(fa2[x]);
}
void merge2(int x, int y)
{
	int a = get_fa2(x), b = get_fa2(y);
	fa2[a] = b;
}
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
int k[Maxn], x[Maxn], y[Maxn];
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &k[i]);
		if (k[i] == 2)
		{
			scanf("%d%d", &x[i], &y[i]);
			merge(x[i], y[i]);
		}
		else
		{
			scanf("%d", &x[i]);
			merge(0, x[i]);
		}
	}
	T = fast_pow(2, S = siz[0]);
	for (int i = 1; i <= n; i++)
		if (get_fa(i) == i)
		{
			(T *= fast_pow(2, siz[i] - 1)) %= p;
			S += siz[i] - 1;
		}
	printf("%lld %d\n", T, S);
	for (int i = 1; i <= n; i++) fa2[i] = i;
	for (int i = 1; i <= m; i++)
	{
		if (k[i] == 2 && get_fa2(x[i]) != get_fa2(y[i])) printf("%d ", i), merge2(x[i], y[i]);
		if (k[i] == 1 && get_fa2(0) != get_fa2(x[i])) printf("%d ", i), merge2(0, x[i]);
	}
	return 0;
}