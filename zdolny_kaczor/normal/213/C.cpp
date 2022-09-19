# include <cstdio>
# include <set>
using namespace std;
const int MN = 303;
int dp[MN][MN][MN];
int a[MN][MN];
const int inf = 1 << 26;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < n; ++k)
			scanf("%d", &a[i][k]);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < n; ++k)
			for (int l = 0; l < n; ++l)
				dp[i][k][l] = -inf;
	dp[0][0][0] = a[0][0];
	for (int i = 1; i < n; ++i)
	{
		for (int k = 0; k <= i; ++k)
			dp[0][k][i] = dp[0][0][i - 1] + a[0][i];
	}
	for (int i = 1; i < n; ++i)
	{
// 		printf("in %d\n", i);
		for (int k = 0; k < n; ++k)
			for (int l = k; l < n; ++l)
				dp[i][k][l] = dp[i - 1][k][l] + a[i][k] + a[i][l] - (k == l ? a[i][k] : 0);
// 		printf("after phase 1:\n");
// 		for (int k = 0; k < n; ++k)
// 		{
// 			for (int l = 0; l < n; ++l)
// 				if (dp[i][k][l] == -inf)
// 					printf("-----");
// 				else
// 					printf("%4d ", dp[i][k][l]);
// 			printf("\n");
// 		}
		for (int k = 1; k < n; ++k)
			for (int l = k + 1; l < n; ++l)
				dp[i][k][l] = max(dp[i][k][l], dp[i][k - 1][l] + a[i][k]);
// 		printf("after phase 2:\n");
// 		for (int k = 0; k < n; ++k)
// 		{
// 			for (int l = 0; l < n; ++l)
// 				if (dp[i][k][l] == -inf)
// 					printf("-----");
// 				else
// 					printf("%4d ", dp[i][k][l]);
// 				printf("\n");
// 		}
		for (int k = 1; k < n; ++k)
			dp[i][k][k] = max(dp[i][k][k], dp[i][k - 1][k]);
// 		printf("after phase 3:\n");
// 		for (int k = 0; k < n; ++k)
// 		{
// 			for (int l = 0; l < n; ++l)
// 				if (dp[i][k][l] == -inf)
// 					printf("-----");
// 				else
// 					printf("%4d ", dp[i][k][l]);
// 				printf("\n");
// 		}
		for (int k = 1; k < n; ++k)
			dp[i][k][k] = max(dp[i][k][k], dp[i][k - 1][k - 1] + a[i][k]);
		
// 		printf("after phase 4:\n");
// 		for (int k = 0; k < n; ++k)
// 		{
// 			for (int l = 0; l < n; ++l)
// 				if (dp[i][k][l] == -inf)
// 					printf("-----");
// 				else
// 					printf("%4d ", dp[i][k][l]);
// 				printf("\n");
// 		}
		for (int k = 0; k < n; ++k)
			for (int l = k + 1; l < n; ++l)
			{
				dp[i][k][l] = max(dp[i][k][l], dp[i][k][l - 1] + a[i][l]);
			}
// 		printf("after phase 5:\n");
// 		for (int k = 0; k < n; ++k)
// 		{
// 			for (int l = 0; l < n; ++l)
// 				if (dp[i][k][l] == -inf)
// 					printf("-----");
// 				else
// 					printf("%4d ", dp[i][k][l]);
// 				printf("\n");
// 		}
	}
// 	for (int i = 0; i < n; ++i)
// 		for (int k = 0; k < n; ++k)
// 			for (int l = 0; l < n; ++l)
// 				printf("dp[%d][%d][%d] = %d\n", i, k, l, dp[i][k][l]);
	printf("%d\n", dp[n - 1][n - 1][n - 1]);
}