#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;

struct point
{
	long long x, y;

	friend bool operator <(const point &x, const point &y)
	{
		return x.x < y.x;
	}
};

int n;
point a[MAXN];
int f[MAXN];

int cn;
long long c[MAXN];

void init()
{
	int A, B, C, D;
	scanf("%d", &n);
	scanf("%d/%d", &A, &B);
	scanf("%d/%d", &C, &D);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		long long u = (long long)C * x - (long long)D * y;
		long long v = (long long)B * y - (long long)A * x;
		a[i].x = u;
		a[i].y = v;
	}
	a[n].x = a[n].y = 0;
	++n;
	std::sort(a, a + n);
}

void solve()
{
	c[cn++] = 0;

	int l = 0;
	while (l < n)
	{
		if (a[l].x <= 0)
		{
			++l; continue;
		}

		int r = l;
		while (a[r].x == a[l].x) ++r;

		for (int j = l; j < r; ++j)
			f[j] = std::lower_bound(c, c + cn, a[j].y) - c;

		for (int j = l; j < r; ++j)
			if (f[j] == cn) c[cn++] = a[j].y;
			else if (f[j] != 0 && a[j].y < c[f[j]]) c[f[j]] = a[j].y;

		l = r;
	}

	--cn;
	printf("%d\n", cn);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8770.in", "r", stdin);
	freopen("8770.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}