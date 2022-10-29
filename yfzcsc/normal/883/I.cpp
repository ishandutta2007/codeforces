#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 300005;

int n, m, a[MAXN], f[MAXN], g[MAXN];

inline bool Chk(int d)
{
	f[0] = g[0] = 1;
	for (int i = 1, j = 1; i <= n; i ++)
	{
		while (a[i] - a[j] > d)
			j ++;
		if (i >= m && g[i - m] - (j == 1 ? 0 : g[j - 2]) > 0)
			f[i] = 1;
		else
			f[i] = 0;
		g[i] = g[i - 1] + f[i];
	}
	return f[n];
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	sort(a + 1, a + n + 1);
	int l = 0, r = a[n], ret = 0;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (Chk(mid))
			ret = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	return printf("%d\n", ret), 0;
}