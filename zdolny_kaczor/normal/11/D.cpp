# include <cstdio>
const int MN = 19;
long long dp[MN][1 << MN];
bool graph[MN][MN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	long long res = - m - n;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		graph[a][b] = graph[b][a] = true;
	}
	for (int v = 0; v < n; ++v)
	{
		for (int i = 0; i < n; ++i)
			for (int mask = 0; mask < (1 << n); ++mask)
				dp[i][mask] = 0;
		for (int mask = 0; mask < (1 << n); ++mask)
			dp[v][mask] = 1;
		for (int k = 0; k < n; ++k)
			if (graph[v][k])
				for (int mask = 0; mask < (1 << n); ++mask)
					dp[k][mask] ++;
		for (int mask = 1; mask < (1 << v); ++mask)
			for (int u = 0; u < n; ++u)
			{
				for (int next = 0; next < v; ++next)
					if ((1 << next & mask) && next != u && next != v && graph[u][next])
						dp[u][mask] += dp[next][mask &~ (1 << u)];
			}
		res += dp[v][(1 << v) - 1];
	}
	printf("%I64d\n", res / 2);
}