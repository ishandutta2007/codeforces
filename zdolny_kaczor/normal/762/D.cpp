#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
const int MN = 1e5 + 44;
int a[3][MN];
long long dp[3][MN];
const long long inf = 1e18 + 4652;
int main() {
	int n;
	scanf("%d", &n);
	for (int k = 0; k < 3; ++k)
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[k][i]);
	dp[2][n] = 0;
	dp[1][n] = dp[0][n] = -inf;
	for (int i = n - 1; i >= 0; --i) {
		for (int k = 0; k < 3; ++k)
			dp[k][i] = -inf;
		for (int k = 0; k < 3; ++k)
			for (int l = 0; l < 3; ++l) {
				long long sum = 0;
				for (int m = min(l, k); m <= max(l, k); ++m)
					sum += a[m][i];
				dp[k][i] = max(dp[k][i], dp[l][i + 1] + sum);
			}
		long long s2 = 0;
		for (int k = 0; k < 3; ++k)
			for (int l = 0; l < 2; ++l)
				s2 += a[k][i + l];
		if (i + 2 <= n) {
			dp[0][i] = max(dp[0][i], dp[2][i + 2] + s2);
			dp[2][i] = max(dp[2][i], dp[0][i + 2] + s2);
		}
		for (int k = 0; k < 3; ++k)
			debug("%lld ", dp[k][i]);
		debug("\n");
	}
	printf("%lld\n", dp[0][0]);
}