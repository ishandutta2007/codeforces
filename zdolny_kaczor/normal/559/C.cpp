# include <cstdio>
# include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
const int MN = 2e5 + 44;
long long fac[MN];
long long fin[MN];
long long pow(int b, int e)
{
	if (e == 0)
		return 1;
	else if (e % 2)
		return pow(b, e - 1) * b % MOD;
	else
	{
		long long h = pow(b, e / 2);
		return h * h % MOD;
	}
}
long long pathcou(pair <int, int> a, pair <int, int> b)
{
	int dx = a.second - b.second, dy = a.first - b.first;
	if (dx >= 0 && dy >= 0)
	{
		long long ret = fac[dx + dy] * fin[dy] % MOD * fin[dx] % MOD;
		return ret;
	}
	else
		return 0;
}
long long inv(int a)
{
	return pow(a, MOD - 2);
}
const int MCOU = 2020;
pair <int, int> all[MCOU];
long long dp[MCOU];
int main()
{
	int n, w, h;
	scanf("%d%d%d", &h, &w, &n);
	fac[0] = 1;
	for (int i = 1; i < MN; ++i)
		fac[i] = fac[i - 1] * i % MOD;
	fin[MN - 1] = inv(fac[MN - 1]);
		
	for (int i = MN - 2; i >= 0; --i)
		fin[i] = fin[i + 1] * (i + 1) % MOD;
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &all[i].first, &all[i].second);
	sort(all, all + n);
	pair <int, int> start = make_pair(1, 1);
	all[n] = make_pair(h, w);
	for (int i = 0; i <= n; ++i)
	{
		dp[i] += pathcou(all[i], start);
		for (int k = 0; k < i; ++k)
			dp[i] -= pathcou(all[i], all[k]) * dp[k] % MOD;
		dp[i] %= MOD;
	}
	if (dp[n] < 0)
		dp[n] += MOD;
	printf("%d\n", (int) dp[n]);
}