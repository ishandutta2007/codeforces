# include <cstdio>
const int MN = 4e5 + 44;
int dp[MN][2];
const int mod = 1e9 + 7;
int main()
{
	int r, g;
	scanf("%d%d", &r, &g);
	int h;
	for (h = 0; (h + 1) * (h + 2) / 2 <= r + g; ++h)
		;
// 	printf("h = %d\n", h);
	dp[0][0] = 1;
	for (int i = 1; i <= h; ++i)
		for (int k = 0; k <= i * (i + 1) / 2; ++k)
			dp[k][i % 2] = (dp[k][(i - 1) % 2] + (k >= i ? dp[k - i][(i - 1) % 2] : 0)) % mod;
	int res = 0;
	for (int i = r; h * (h + 1) / 2 - i <= g && i >= 0; --i)
	{
// 		printf("include %d - %d\n", i, h * (h + 1) / 2 - i);
		res = (res + dp[i][h % 2]) % mod;
	}
	printf("%d\n", res);
}