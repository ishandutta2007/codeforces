# include <cstdio>
# include <set>
const int MN = 510;
int a[MN][MN];
int rsum[MN][MN], csum[MN][MN];
int dp[MN][MN][4];
inline int rsumcou(int row, int lbound, int rbound)
{
// 	printf("row %d <%d, %d>\n", row, lbound, rbound);
// 	printf("return %d\n", rsum[row][rbound + 1] - rsum[row][lbound]);
	return rsum[row][rbound + 1] - rsum[row][lbound];
}
inline int csumcou(int col, int lbound, int rbound)
{
// 	printf("col %d <%d, %d>\n", col, lbound, rbound);
// 	printf("return %d\n", csum[rbound + 1][col] - csum[lbound][col]);
	return csum[rbound + 1][col] - csum[lbound][col];
}
const int inf = 8e8 + 88;
int main()
{
	int res = -inf;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < MN; ++i)
		for (int k = 0; k < MN; ++k)
			for (int l = 0; l < 4; ++l)
				dp[i][k][l] = -inf;
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			scanf("%d", &a[i][k]);
	for (int i = 0; i < n; ++i)
	{
		rsum[i][0] = 0;
		for (int k = 0; k < m; ++k)
			rsum[i][k + 1] = rsum[i][k] + a[i][k];
	}
	for (int k = 0; k < m; ++k)
	{
		csum[0][k] = 0;
		for (int i = 0; i < n; ++i)
			csum[i + 1][k] = csum[i][k] + a[i][k];
	}
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			dp[i][k][1] = a[i][k];
	for (int i = 0; i < n - 2; ++i)
		for (int k = 0; k < m - 2; ++k)
		{
			dp[i][k][3] = a[i][k] + a[i][k + 1] + a[i][k + 2] + a[i + 1][k + 2] + a[i + 2][k] + a[i + 2][k + 1] + a[i + 2][k + 2];
			res = std::max(res, dp[i][k][3]);
		}
	for (int l = 5; l <= n; l += 2)
		for (int i = 0; i + l <= n; ++i)
			for (int k = 0; k + l <= m; ++k)
			{
// 				printf("in %d %d deg = %d\n", i, k, l);
				dp[i][k][l % 4] = dp[i + 2][k + 2][l % 4] + rsumcou(i, k, k + l - 1) + rsumcou(i + l - 1, k, k + l - 1) +
				csumcou(k + l - 1, i + 1, i + l - 2) + csumcou(k, i + 2, i + l - 2) + a[i + 2][k + 1];
				res = std::max(res, dp[i][k][l % 4]);
// 				printf("added (%d, %d), (%d, %d)\n", i + 2, k + 1, i + 2, k + 2);
			}
	printf("%d\n", res);
}