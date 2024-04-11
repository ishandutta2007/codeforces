#include <cstdio>
#include <cstdlib>
#include <set>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXK = 100005;

int n, m, k;
int x[MAXK];
int y[MAXK];
std::set<int> a[2 * MAXN];
std::set<int> b[2 * MAXN];
int xn, yn;
int dn;

void addblock(int x0, int y0)
{
	a[x0 + y0].insert(x0);
	b[x0 + m + 1 - y0].insert(x0);
}

void init()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%d", &x[i], &y[i]);
		addblock(x[i], y[i]);
	}
	for (int i = 0; i <= n + 1; ++i)
	{
		addblock(i, 0);
		addblock(i, m + 1);
	}
	for (int i = 1; i <= m; ++i)
	{
		addblock(0, i);
		addblock(n + 1, i);
	}
	scanf("%d%d", &xn, &yn);
	char s[5];
	scanf("%s", s);
	if (s[1] == 'E')
		dn |= 1;
	if (s[0] == 'S')
		dn |= 2;
}

void findnext(int x0, int y0, int d, int &x1, int &y1)
{
	std::set<int>::const_iterator it;
	if (d == 0)
	{
		it = b[x0 + m + 1 - y0].lower_bound(x0);
		--it;
		x1 = *it;
		y1 = y0 - x0 + x1;
	}
	else if (d == 1)
	{
		it = a[x0 + y0].lower_bound(x0);
		--it;
		x1 = *it;
		y1 = x0 + y0 - x1;
	}
	else if (d == 2)
	{
		it = a[x0 + y0].lower_bound(x0);
		x1 = *it;
		y1 = x0 + y0 - x1;
	}
	else if (d == 3)
	{
		it = b[x0 + m + 1 - y0].lower_bound(x0);
		x1 = *it;
		y1 = y0 - x0 + x1;
	}
}

bool exists(int x0, int y0)
{
	return a[x0 + y0].find(x0) != a[x0 + y0].end();
}

void solve()
{
	int xx = xn, yy = yn;
	int cnt = 0;
	long long ans = 0;
	while (true)
	{
		int xr, yr;
		findnext(xn, yn, dn, xr, yr);
		int xxl = abs(xx - xn);
		int yyl = abs(yy - yn);
		if (xxl == yyl && xxl <= abs(xr - xn) && (xxl == 0 || ((xx > xn) == (dn & 2) >> 1 && (yy > yn) == (dn & 1))))
		{
			++cnt;
			if (cnt == 3)
			{
				ans += xxl;
				break;
			}
		}
		ans += abs(xr - xn);
		bool v1 = exists(xr - (dn & 2 ? 1 : -1), yr);
		bool v2 = exists(xr, yr - (dn & 1 ? 1 : -1));
		if (v1 && !v2)
		{
			xn = xr;
			yn = yr - (dn & 1 ? 1 : -1);
			dn ^= 1;
		}
		else if (!v1 && v2)
		{
			xn = xr - (dn & 2 ? 1 : -1);
			yn = yr;
			dn ^= 2;
		}
		else
		{
			xn = xr - (dn & 2 ? 1 : -1);
			yn = yr - (dn & 1 ? 1 : -1);
			dn ^= 3;
		}
	}
	printf("%"LLFORMAT"d\n", ans / 2);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("274E.in", "r", stdin);
	freopen("274E.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}