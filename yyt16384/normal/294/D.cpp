#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;

int n, m, x, y;
bool vis[4*MAXN];

void init()
{
	char ss[10];
	scanf("%d%d%d%d%s", &n, &m, &x, &y, ss);
	if (ss[0] == 'U') x = n - x;
	else --x;
	if (ss[1] == 'L') y = m - y;
	else --y;
}

void solve()
{
	const int DR[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
	long long ans = 1;
	int now = 3;
	int count = 0;
	int hashcnt = 0;
	if (x == 0) now ^= 2;
	if (y == 0) now ^= 1;
	while (true)
	{
		++count;
		if (count == 2 * (n + m))
		{
			printf("-1\n");
			return;
		}
		int kx = (DR[now][0] == 1 ? n - x - 1 : x);
		int ky = (DR[now][1] == 1 ? m - y - 1 : y);
		int k = std::min(kx, ky);
		ans += k;
		x += k * DR[now][0];
		y += k * DR[now][1];
		if ((x == 0 && DR[now][0] == -1) || (x == n - 1 && DR[now][0] == 1)) now ^= 2;
		if ((y == 0 && DR[now][1] == -1) || (y == m - 1 && DR[now][1] == 1)) now ^= 1;

		int hash;
		if (x == 0) hash = y;
		else if (y == m - 1) hash = m - 1 + x;
		else if (x == n - 1) hash = n + 2 * m - 3 - y;
		else if (y == 0) hash = 2 * n + 2 * m - 4 - x;
		if (!vis[hash])
		{
			vis[hash] = true;
			++hashcnt;
			if (hashcnt == n + m - 2)
				break;
		}
	}
	printf("%"LLFORMAT"d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9157.in", "r", stdin);
	freopen("9157.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}