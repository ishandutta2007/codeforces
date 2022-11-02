#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif
const int MAXN = 1005;
const int MAXL = 35;
const int MOD = 1000000009;
int n, l;
long long f[2][MAXL][MAXL][MAXL][2];
void init()
{
	scanf("%d%d", &n, &l);
}
void solve()
{
	int nx, ny, nz, np;
	long long ss;
	f[0][1][1][1][1] = 4;
	for (int i = 1; i < n; ++i)
	{
		for (int x = 0; x <= l; ++x)
			for (int y = 0; y <= l; ++y)
				for (int z = 0; z <= l; ++z)
					for (int p = 0; p < 2; ++p)
						if ((ss = f[(i + 1) & 1][x][y][z][p]))
						{
							f[(i + 1) & 1][x][y][z][p] = 0;
							ss %= MOD;
							nx = (x == l ? l : x + 1);
							ny = (y == l ? l : y + 1);
							nz = (z == l ? l : z + 1);
							np = (p ? 1 : l);
							f[i & 1][ny][nz][np][x < l] += ss;
							f[i & 1][nx][nz][np][y < l] += ss;
							f[i & 1][nx][ny][np][z < l] += ss;
							f[i & 1][nx][ny][nz][p] += ss;
						}
	}
	long long ans = 0;
	for (int x = 0; x <= l; ++x)
		for (int y = 0; y <= l; ++y)
			for (int z = 0; z <= l; ++z)
				for (int p = 0; p < 2; ++p)
					if (p || x < l || y < l || z < l)
						ans += f[(n - 1) & 1][x][y][z][p];
	ans %= MOD;
	printf("%"LLFORMAT"d\n", ans);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("8756.in", "r", stdin);
	freopen("8756.out", "w", stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}