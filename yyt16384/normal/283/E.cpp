#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXM = 100005;
const int MAXS = 270005;

struct Event
{
	int t;
	int l, r;
};

bool operator<(const Event &x, const Event &y)
{
	return x.t < y.t;
}

int n, m;
int a[MAXN];
int ll[MAXM];
int rr[MAXM];
Event p[2 * MAXM];
int sum[MAXS];
int flag[MAXS];
int deg[MAXN];

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	std::sort(a, a + n);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &ll[i], &rr[i]);
		++rr[i];
		ll[i] = std::lower_bound(a, a + n, ll[i]) - a;
		rr[i] = std::lower_bound(a, a + n, rr[i]) - a;
	}
}

void insert(int now, int l, int r, int ql, int qr)
{
	if (ql == qr)
		return;
	if (ql == l && qr == r)
	{
		sum[now] = r - l - sum[now];
		flag[now] ^= 1;
		return;
	}
	int mid = (l + r) >> 1;
	if (flag[now])
	{
		sum[2 * now + 1] = mid - l - sum[2 * now + 1];
		flag[2 * now + 1] ^= 1;
		sum[2 * now + 2] = r - mid - sum[2 * now + 2];
		flag[2 * now + 2] ^= 1;
		flag[now] = 0;
	}
	if (qr <= mid)
		insert(2 * now + 1, l, mid, ql, qr);
	else if (ql >= mid)
		insert(2 * now + 2, mid, r, ql, qr);
	else
	{
		insert(2 * now + 1, l, mid, ql, mid);
		insert(2 * now + 2, mid, r, mid, qr);
	}
	sum[now] = sum[2 * now + 1] + sum[2 * now + 2];
}

int getsum(int now, int l, int r, int ql, int qr)
{
	if (ql == qr)
		return 0;
	if (ql == l && qr == r)
		return sum[now];
	int mid = (l + r) >> 1;
	if (flag[now])
	{
		sum[2 * now + 1] = mid - l - sum[2 * now + 1];
		flag[2 * now + 1] ^= 1;
		sum[2 * now + 2] = r - mid - sum[2 * now + 2];
		flag[2 * now + 2] ^= 1;
		flag[now] = 0;
	}
	if (qr <= mid)
		return getsum(2 * now + 1, l, mid, ql, qr);
	else if (ql >= mid)
		return getsum(2 * now + 2, mid, r, ql, qr);
	else
		return getsum(2 * now + 1, l, mid, ql, mid) + getsum(2 * now + 2, mid, r, mid, qr);
}

void solve()
{
	for (int i = 0; i < m; ++i)
	{
		p[2 * i].t = ll[i];
		p[2 * i].l = ll[i];
		p[2 * i].r = rr[i];
		p[2 * i + 1].t = rr[i];
		p[2 * i + 1].l = ll[i];
		p[2 * i + 1].r = rr[i];
	}
	std::sort(p, p + 2 * m);
	for (int i = 0, j = 0; i < n; ++i)
	{
		while (j < 2 * m && p[j].t == i)
		{
			insert(0, 0, n, p[j].l, p[j].r);
			++j;
		}
		deg[i] = getsum(0, 0, n, 0, i) + n - i - 1 - getsum(0, 0, n, i + 1, n);
	}
	long long ans = (long long)n * (n - 1) * (n - 2) / 6;
	for (int i = 0; i < n; ++i)
		ans -= (long long)deg[i] * (deg[i] - 1) / 2;
	printf("%"LLFORMAT"d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("283E.in", "r", stdin);
	freopen("283E.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}