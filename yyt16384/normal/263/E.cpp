#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 1005;

int n, m, k;
long long a[MAXN][MAXN];
int sur[MAXN][MAXN];
long long su[MAXN][MAXN];
long long uu[MAXN][MAXN];
long long ul[MAXN][MAXN];
long long ans[MAXN][MAXN];

void input()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%"LLFORMAT"d", &a[i][j]);
}

void get_sur(int l)
{
	for (int i = l - 1; i < n; ++i)
	{
		sur[i][0] = 0;
		for (int j = 0; j < l; ++j)
			sur[i][0] += a[i-j][j];
	}

	for (int i = 1; i <= m - l; ++i)
	{
		sur[n-1][i] = 0;
		for (int j = 0; j < l; ++j)
			sur[n-1][i] += a[n-1-j][i+j];
	}

	for (int i = n - 2; i >= l - 1; --i)
		for (int j = 1; j <= m - l; ++j)
		{
			sur[i][j] = sur[i+1][j-1];
			sur[i][j] -= a[i+1][j-1];
			sur[i][j] += a[i-l+1][j+l-1];
		}
}

void get_uu(int l)
{
	for (int i = 0; i < m; ++i)
	{
		static long long ts[MAXN];
		ts[0] = 0;
		for (int j = 0; j < n; ++j)
			ts[j+1] = ts[j] + a[j][i];
		uu[l-1][i] = 0;
		for (int j = 0; j < l; ++j)
			uu[l-1][i] += a[j][i] * (j+1);
		for (int j = l; j < n; ++j)
		{
			uu[j][i] = uu[j-1][i];
			uu[j][i] -= ts[j] - ts[j-l];
			uu[j][i] += a[j][i] * l;
		}
	}
}

void get_su(int l)
{
	su[l-1][l-1] = 0;
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < l; ++j)
			if (i+j >= l-1)
				su[l-1][l-1] += a[i][j];

	for (int i = l; i < n; ++i)
	{
		su[i][l-1] = su[i-1][l-1];
		su[i][l-1] -= sur[i-1][0];
		for (int j = 0; j < l; ++j)
			su[i][l-1] += a[i][j];
	}

	for (int j = l; j < m; ++j)
	{
		int u = 0;
		for (int i = 0; i < l; ++i)
			u += a[i][j];
		for (int i = l - 1; i < n; ++i)
		{
			su[i][j] = su[i][j-1];
			su[i][j] -= sur[i][j-l];
			su[i][j] += u;
			u -= a[i-l+1][j];
			u += a[i+1][j];
		}
	}
}

void get_ul(int l)
{
	get_sur(l);
	get_su(l);
	get_uu(l);

	ul[l-1][l-1] = 0;
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < l; ++j)
			ul[l-1][l-1] += a[i][j] * std::max(i+j+2-l, 0);

	for (int i = l; i < n; ++i)
	{
		ul[i][l-1] = ul[i-1][l-1];
		ul[i][l-1] -= su[i-1][l-1];
		for (int j = 0; j < l; ++j)
			ul[i][l-1] += a[i][j] * (j+1);
	}

	for (int i = l - 1; i < n; ++i)
		for (int j = l; j < m; ++j)
		{
			ul[i][j] = ul[i][j-1];
			ul[i][j] -= su[i][j-1];
			ul[i][j] += uu[i][j];
		}
}

void add_to_ans(int dx, int dy)
{
	for (int i = k - 1; i <= n - k; ++i)
		for (int j = k - 1; j <= m - k; ++j)
			ans[i][j] += ul[i+dx][j+dy];
}

void rotate_ccw(long long x[MAXN][MAXN])
{
	static long long y[MAXN][MAXN];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			y[m-j-1][i] = x[i][j];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			x[i][j] = y[i][j];
}

void init()
{
	const int D[4] = {0, 1, 2, 1};
	const int DX[4] = {0, -1, -1, 0};
	const int DY[4] = {0, 0, -1, -1};
	for (int i = 0; i < 4; ++i)
	{
		if (k > D[i])
		{
			get_ul(k - D[i]);
			add_to_ans(DX[i], DY[i]);
		}
		rotate_ccw(a);
		rotate_ccw(ans);
		std::swap(n, m);
	}
}

void solve()
{
	long long max = 0;
	for (int i = k - 1; i <= n - k; ++i)
		for (int j = k - 1; j <= m - k; ++j)
			max = std::max(max, ans[i][j]);

	for (int i = k - 1; i <= n - k; ++i)
		for (int j = k - 1; j <= m - k; ++j)
			if (ans[i][j] == max)
			{
				printf("%d %d\n", i + 1, j + 1);
				return;
			}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8738.in", "r", stdin);
	freopen("8738.out", "w", stdout);
#endif

	input();
	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}