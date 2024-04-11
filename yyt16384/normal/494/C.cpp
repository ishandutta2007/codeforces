#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXQ = 5005;

struct Data
{
	int l, r;
	double p;

	friend bool operator<(const Data &x, const Data &y)
	{
		return x.l < y.l || (x.l == y.l && x.r > y.r);
	}
};

int n, q;
int a[MAXN];
Data c[MAXQ];
bool vis[MAXQ];
int minf[MAXQ];
double f[MAXQ][MAXQ];

void init()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d%lf", &c[i].l, &c[i].r, &c[i].p);
		--c[i].l;
	}
	c[q].l = 0;
	c[q].r = n;
	c[q].p = 0;
	++q;
}

void getans(int x)
{
	int l = c[x].l, r = c[x].r;
	double p = c[x].p;

	vis[x] = true;

	static int son[MAXQ][MAXQ];
	static int sonn[MAXQ];

	for (int i = x + 1; i < q && c[i].l < r; ++i)
		if (!vis[i])
		{
			getans(i);
			son[x][sonn[x]++] = i;
		}

	for (int i = l, qq = 0; i < r; ++i)
	{
		if (qq < sonn[x] && c[son[x][qq]].l == i)
		{
			int pp = son[x][qq];
			if (minf[pp] > minf[x]) minf[x] = minf[pp];
			i = c[pp].r - 1;
			++qq;
			continue;
		}
		if (a[i] > minf[x]) minf[x] = a[i];
	}

	f[x][0] = 1;
	for (int i = l, qq = 0; i < r; ++i)
	{
		if (qq < sonn[x] && c[son[x][qq]].l == i)
		{
			int pp = son[x][qq];
			if (minf[x] - minf[pp] <= q)
			{
				double pre1 = 0, pre2 = 0;
				for (int j = 0; j < minf[x] - minf[pp]; ++j)
					pre2 += f[pp][j];
				for (int j = minf[x] - minf[pp]; j <= q; ++j)
				{
					pre1 += f[x][j-(minf[x]-minf[pp])];
					f[x][j-(minf[x]-minf[pp])] = pre1 * f[pp][j] + pre2 * f[x][j-(minf[x]-minf[pp])];
					pre2 += f[pp][j];
				}
			}
			i = c[pp].r - 1;
			++qq;
			continue;
		}
	}

	for (int i = q; i >= 1; --i)
		f[x][i] = f[x][i-1] * p + f[x][i] * (1-p);
	f[x][0] *= 1-p;
}

void solve()
{
	std::sort(c, c + q);
	getans(0);

	double ans = 0;
	for (int i = 0; i <= q; ++i)
		ans += f[0][i] * (minf[0] + i);
	printf("%.12f\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}