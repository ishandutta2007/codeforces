# include <cstdio>
# include <algorithm>
# define pow poiuaeoi
# define hash asoauesntahoeint
# define rank aoeusnth
using namespace std;
const int M = 1e9 + 7;
const int B = 7539;
const int MN = 5020;
long long hash[MN];
long long pow[MN];
char word[MN];
bool equal(int i, int k, int len)
{
	return ((hash[i + len] - hash[i]) * pow[k] - (hash[k + len] - hash[k]) * pow[i]) % M == 0;
}
bool cmp(pair <int, int> a, pair <int, int> b)
{
	int i = a.first, k = b.first;
	int l1 = a.second, l2 = b.second;
	int low = 0, high = min(l1, l2), ans = 0;
	while (low <= high)
	{
		int med = (low + high) / 2;
		if (equal(i, k, med))
		{
			ans = med;
			low = med + 1;
		}
		else
			high = med - 1;
	}
	if (ans == l2)
		return true;
	else if (ans == l1)
		return false;
	else
		return word[i + ans] < word[k + ans];
}
int rank[MN];
pair <int, int> suf[MN];
void show(int pos, int len)
{
	for (int i = 0; i < len; ++i)
		printf("%c", word[i + pos]);
}
bool cmp2(int i, int k, int len)
{
// 	show (i, len);
// 	printf(" ");
// 	show (k, len);
	int ret = !equal(i, k, len) && rank[i] < rank[k];
// 	printf(" return %d\n", ret);
	return ret;
}
int dp[MN][MN]; // pozycja pocztkowa, minimalna dugo pierwszego
int main()
{
	int n;
	scanf("%d%s", &n, word);
	pow[0] = 1;
	for (int i = 1; i < MN; ++i)
		pow[i] = pow[i - 1] * B % M;
	for (int i = 1; i <= n; ++i)
		hash[i] = (hash[i - 1] + word[i - 1] * pow[i - 1]) % M;
	for (int i = 0; i < n; ++i)
		suf[i] = make_pair(i, n - i);
	sort(suf, suf + n, cmp);
// 	for (int i = 0; i < n; ++i)
// 	{
// 		for (int k = suf[i].first; k < suf[i].first + suf[i].second; ++k)
// 			putchar(word[k]);
// 		printf("\n");
// 	}
	for (int i = 0; i < n; ++i)
		rank[suf[i].first] = i;
	for (int i = 1; i <= n; ++i)
		dp[n][i] = 1;
	for (int pos = n - 1; pos >= 0; --pos)
		if (word[pos] != '0')
		{
			dp[pos][n - pos] = 1;
			for (int len = n - pos - 1; len >= 1; --len)
			{
				dp[pos][len] = dp[pos][len + 1];
				if (pos + len * 2 <= n && cmp2(pos, pos + len, len))
					dp[pos][len] += dp[pos + len][len];
				else
					dp[pos][len] += dp[pos + len][len + 1];
				dp[pos][len] %= M;
			}
		}
	printf("%d\n", dp[0][1]);
}