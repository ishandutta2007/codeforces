# include <cstdio>
# include <set>
# include <cstring>
using namespace std;
const int ML = 5e4 + 44;
const int MN = 2622;
int cou[26];
char text[ML];
int dp[MN][MN];
char ans[MN];
int main()
{
	scanf("%s", text);
	int n = strlen(text);
	for (int i = 0; i < n; ++i)
		cou[text[i] - 'a'] ++;
	for (int i = 0; i < 26; ++i)
		if (cou[i] >= 100)
		{
			for (int k = 0; k < 100; ++k)
				putchar('a' + i);
			printf("\n");
			return 0;
		}
	for (int i = 0; i < n; ++i)
		dp[i][i] = 1;
	for (int len = 1; len < n; ++len)
		for (int pos = 0; pos + len < n; ++pos)
			if (text[pos] == text[pos + len])
				dp[pos][pos + len] = dp[pos + 1][pos + len - 1] + 2;
			else
				dp[pos][pos + len] = max(dp[pos][pos + len - 1], dp[pos + 1][pos + len]);
// 	for (int i = 0; i < n; ++i)
// 		for (int k = i; k < n; ++k)
// 		{
// 			for (int l = i; l <= k; ++l)
// 				putchar(text[l]);
// 			printf(" %d\n", dp[i][k]);
// 		}
	int a = 0, b = n - 1, pos = 0;
	while (a <= b && pos < 50)
	{
		if (text[a] == text[b])
		{
			ans[pos] = text[a];
			a++;
			pos++;
			b--;
		}
		else if (dp[a][b] == dp[a + 1][b])
			a++;
		else
			b--;
	}
	for (int i = 0; i < pos; ++i)
		putchar(ans[i]);
	for (int i = pos - 1 - (min(dp[0][n - 1], 100) % 2); i >= 0; --i)
		putchar(ans[i]);
	putchar(10);
}