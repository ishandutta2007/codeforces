# include <cstdio>
# include <set>
using namespace std;
const int MP = 9;
const int MN = 7 * 11 * 13;
int primes[MP] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
long long dp[MN][MP + 1];
const long long bound = 1e18 + 1;
long long safemul(long long a, long long b)
{
	if (a * (long double) b > bound)
		return bound;
	else
		return a * b;
}
long long safepow(long long b, int e)
{
	long long res = 1;
	for (int i = 0; i < e; ++i)
		res = safemul(res, b);
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int k = 0; k <= MP; ++k)
			dp[i][k] = bound;
	for (int i = 0; i < MP; ++i)
		dp[1][i] = 1;
	for (int i = 1; i <= n; ++i)
		for (int k = MP - 1; k >= 0; --k)
			for (int l = 1; l <= n; ++l)
				if (i % l == 0)
					dp[i][k] = min(dp[i][k], safemul(dp[i / l][k + 1], safepow(primes[k], l - 1)));
	printf("%I64d\n", dp[n][0]);
}