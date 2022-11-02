#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXS = 370005;

struct Point
{
	int x, y;
};

bool operator<(const Point &x, const Point &y)
{
	return x.x < y.x;
}

struct Data
{
	int a[9];
	int x1, x2;
	int y1, y2;
};

struct Query
{
	int x, y;
	int sum;
	int id;

	Query() {}
	Query(int x_, int y_, int sum_, int id_) :
		x(x_), y(y_), sum(sum_), id(id_) {}
};

bool operator<(const Query &x, const Query &y)
{
	return x.x < y.x;
}

int n, mx, my;
Point a[MAXN];
int c[9];
int rx[MAXN];
int ry[MAXN];
int sumx[MAXN];
int sumy[MAXN];
Data b[MAXS];
int bn;
Query req[MAXS * 4];
int rn;
bool ok[MAXS];
int s[MAXN];

void input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].x, &a[i].y);
	for (int i = 0; i < 9; ++i)
		scanf("%d", &c[i]);
}

void check_add(int *p)
{
	int sumup    = p[0] + p[1] + p[2];
	int sumdown  = p[6] + p[7] + p[8];
	int sumleft  = p[0] + p[3] + p[6];
	int sumright = p[2] + p[5] + p[8];

	int x1 = std::lower_bound(sumx, sumx + mx, sumup) - sumx;
	int x2 = std::lower_bound(sumx, sumx + mx, n - sumdown) - sumx;
	int y1 = std::lower_bound(sumy, sumy + my, sumleft) - sumy;
	int y2 = std::lower_bound(sumy, sumy + my, n - sumright) - sumy;

	if (!(sumx[x1] == sumup && sumx[x2] == n - sumdown &&
				sumy[y1] == sumleft && sumy[y2] == n - sumright))
		return;

	memcpy(b[bn].a, p, sizeof(b[bn].a));
	b[bn].x1 = x1;
	b[bn].x2 = x2;
	b[bn].y1 = y1;
	b[bn].y2 = y2;

	int sumx1y1 = p[0];
	int sumx1y2 = p[0] + p[1];
	int sumx2y1 = p[0] + p[3];
	int sumx2y2 = p[0] + p[1] + p[3] + p[4];
	req[rn++] = Query(x1, y1, sumx1y1, bn);
	req[rn++] = Query(x1, y2, sumx1y2, bn);
	req[rn++] = Query(x2, y1, sumx2y1, bn);
	req[rn++] = Query(x2, y2, sumx2y2, bn);

	++bn;
}

void search(int x)
{
	static int now[9];
	static bool vis[9];
	if (x == 9)
	{
		check_add(now);
		return;
	}
	for (int i = 0; i < 9; ++i)
		if (!vis[i])
		{
			vis[i] = true;
			now[x] = c[i];
			search(x + 1);
			vis[i] = false;
		}
}

void init()
{
	for (int i = 0; i < n; ++i)
		rx[i] = a[i].x;
	std::sort(rx, rx + n);
	mx = std::unique(rx, rx + n) - rx;
	for (int i = 0; i < n; ++i)
		a[i].x = std::lower_bound(rx, rx + mx, a[i].x) - rx;

	for (int i = 0; i < n; ++i)
		ry[i] = a[i].y;
	std::sort(ry, ry + n);
	my = std::unique(ry, ry + n) - ry;
	for (int i = 0; i < n; ++i)
		a[i].y = std::lower_bound(ry, ry + my, a[i].y) - ry;

	for (int i = 0; i < n; ++i)
		++sumx[a[i].x];
	for (int i = 1; i < mx; ++i)
		sumx[i] += sumx[i - 1];

	for (int i = 0; i < n; ++i)
		++sumy[a[i].y];
	for (int i = 1; i < my; ++i)
		sumy[i] += sumy[i - 1];

	search(0);
}

void insert(int x, int y)
{
	++x;
	while (x <= my)
	{
		s[x] += y;
		x += x & -x;
	}
}

int getsum(int x)
{
	int sum = 0;
	++x;
	while (x)
	{
		sum += s[x];
		x -= x & -x;
	}
	return sum;
}

void solve()
{
	for (int i = 0; i < bn; ++i)
		ok[i] = true;
	std::sort(req, req + rn);
	std::sort(a, a + n);
	for (int i = 0, j = 0; i < rn; ++i)
	{
		while (j < n && a[j].x <= req[i].x)
		{
			insert(a[j].y, 1);
			++j;
		}
		int sum = getsum(req[i].y);
		if (sum != req[i].sum)
			ok[req[i].id] = false;
	}
	for (int i = 0; i < bn; ++i)
		if (ok[i])
		{
			printf("%f %f\n", rx[b[i].x1] + 0.5, rx[b[i].x2] + 0.5);
			printf("%f %f\n", ry[b[i].y1] + 0.5, ry[b[i].y2] + 0.5);
			return;
		}
	printf("-1\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("260E.in", "r", stdin);
	freopen("260E.out", "w", stdout);
#endif

	input();
	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}