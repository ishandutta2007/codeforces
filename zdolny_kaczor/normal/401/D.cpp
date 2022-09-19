# include <cstdio>
const int ML = 18;
const int MM = 110;
long long dp[1 << ML][MM];
int pow[ML];
int dig[ML];
int popcount(int x)
{
	int res = 0;
	while (x)
	{
		x &= ~(x & -x);
		res ++;
	}
	return res;
}
int main()
{
	long long n;
	int m;
	scanf("%I64d%d", &n, &m);
	pow[0] = 1;
	for (int i = 1; i < ML; ++i)
		pow[i] = pow[i - 1] * 10 % m;
	int len = 0;
	while (n)
	{
		dig[len] = n % 10;
		len ++;
		n /= 10;
	}
	dp[0][0] = 1;
	for (int mask = 1; mask < (1 << len); ++mask)
		for (int pos = 0; pos < len; ++pos)
			for (int r = 0; r < m; ++r)
				if (mask != (1 << len) - 1 || dig[pos] != 0)
					if (mask & (1 << pos))
						dp[mask][(r + dig [pos] * pow[popcount(mask) - 1]) % m] += dp[mask & ~(1 << pos)][r];
	long long res = dp[(1 << len) - 1][0];
	for (int d = 0; d <= 9; ++d)
	{
		int amo = 0;
		for (int i = 0; i < len; ++i)
			if (dig[i] == d)
				amo ++;
		for (int i = 2; i <= amo; ++i)
			res /= i;
	}
	printf("%I64d\n", res);
}