#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 15;
const int MOD = 1000000007;

int n, m, k, usek;
bool nosol;
int a[MAXN][MAXN];
int sum[MAXN];
unsigned used[MAXN][MAXN];
int map[MAXN];
bool mapped[MAXN];
int ans;

void init()
{
	scanf("%d%d%d", &n, &m, &k);

	if (n + m - 1 > k)
	{
		nosol = true;
		return;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &a[i][j]);
			--a[i][j];
		}

	bool fl[MAXN] = {false};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] != -1)
				fl[a[i][j]] = true;
	usek = 0;
	for (int i = 0; i < k; ++i)
		if (fl[i])
			++usek;
}

void search(int x, int y, int cnt)
{
	if (x == n)
	{
		ans = (ans + sum[cnt]) % MOD;
		return;
	}

	int nx = x, ny = y + 1;
	if (ny == m) ++nx, ny = 0;

	used[x][y] = 0;
	if (x > 0) used[x][y] |= used[x-1][y];
	if (y > 0) used[x][y] |= used[x][y-1];

	if (a[x][y] == -1)
	{
		for (int i = 0; i <= cnt && i < k; ++i)
			if (!((used[x][y] >> i) & 1))
			{
				used[x][y] |= 1U << i;
				search(nx, ny, std::max(cnt, i + 1));
				used[x][y] &= ~(1U << i);
			}
	}
	else
	{
		if (map[a[x][y]] != -1)
		{
			if (!((used[x][y] >> map[a[x][y]]) & 1))
			{
				used[x][y] |= 1U << map[a[x][y]];
				search(nx, ny, cnt);
				used[x][y] &= ~(1U << map[a[x][y]]);
			}
		}
		else
		{
			for (int i = 0; i <= cnt && i < k; ++i)
				if (!mapped[i] && !((used[x][y] >> i) & 1))
				{
					used[x][y] |= 1U << i;
					map[a[x][y]] = i;
					mapped[i] = true;
					search(nx, ny, std::max(cnt, i + 1));
					used[x][y] &= ~(1U << i);
					map[a[x][y]] = -1;
					mapped[i] = false;
				}
		}
	}
}

void solve()
{
	if (nosol)
	{
		printf("0\n");
		return;
	}
	memset(map, -1, sizeof(map));
	memset(mapped, 0, sizeof(mapped));
	sum[usek] = 1;
	for (int i = usek; i < k; ++i)
		sum[i+1] = (long long)sum[i] * (k - i) % MOD;
	search(0, 0, 0);
	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9189.in", "r", stdin);
	freopen("9189.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}