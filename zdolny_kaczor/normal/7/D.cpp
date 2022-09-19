# include <cstdio>
# include <cstring>
# include <set>
using namespace std;
const int MN = 5e6 + 44;
const int B = 7531;
const int MOD = 1e9 + 9;
char tab[MN];
int dp[MN];
long long pows[MN];
typedef pair <long long, int> hash_t;
hash_t s(char a)
{
	return make_pair(a, 1);
}
hash_t operator* (hash_t a, hash_t b)
{
	return make_pair((a.first * pows[b.second] + b.first) % MOD, a.second + b.second);
}
const hash_t empty = make_pair(0, 0);
int main()
{
	pows[0] = 1;
	for (int i = 1; i < MN; ++i)
		pows[i] = pows[i - 1] * B % MOD;
	scanf("%s", tab);
	int n = strlen(tab);
	hash_t left = empty, right = empty;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		left = left * s(tab[i]);
		right = s(tab[i]) * right;
		if (i)
		{
			if (left == right)
				dp[i] = dp[(i - 1) / 2] + 1;
			else
				dp[i] = 0;
		}
		else
			dp[i] = 1;
		res += dp[i];
	}
	printf("%d\n", res);
}