#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>

#define mp make_pair
#define point pair<int, int> 
#define px first
#define py second
#define INF 100000000
#define EPS 1e-9
#define MOD 1000000007

typedef long long ll;

using namespace std;

int N, K;
ll dp[2001][2001];

ll count(ll prev,  ll len)
{
	if (len == 0)
		return 1;
	
	ll& val = dp[prev][len];
	
	if (val >= 0)
		return val;
	
	val = 0;
	
	for (ll v = prev; v <= N; v += prev)
	{
		val += count(v, len-1);
		val %= MOD;
	}
	
	return val;
}

int main()
{
	scanf("%d%d", &N, &K);
	
	for (int i = 0; i <= 2000; i++)
		for (int j = 0; j <= 2000; j++)
			dp[i][j] = -1;
	
	ll ans = 0;
	for (int i = 1; i <= N; i++)
		ans += count(i, K-1);
	ans %= MOD;
	
	printf("%I64d\n", ans);
}