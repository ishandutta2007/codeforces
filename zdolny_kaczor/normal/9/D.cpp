# include <cstdio>
const int MN = 36;
long long dp[MN][MN]; //number of trees with $0 nodes and height not more than $1
int main()
{
	int n, h;
	scanf("%d%d", &n, &h);
	for (int i = 0; i < MN; ++i)
		dp[0][i] = 1;
	for (int cou = 1; cou < MN; ++cou)
		for (int hei = 1; hei < MN; ++hei)
			for (int l = 0; l < cou; ++l)
				dp[cou][hei] += dp[l][hei - 1] * dp[cou - l - 1][hei - 1];
	printf("%I64d\n", dp[n][n] - dp[n][h - 1]);
}