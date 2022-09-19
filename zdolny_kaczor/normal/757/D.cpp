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

#define count asntoehu

const int MN = 76;
	#ifdef DEB
	const int bound = 3;
	#else
	const int bound = 20;
	#endif
const int MOD = 1e9 + 7;
char in[MN];
int dp[1 << bound][MN];
int main() {
	int n;
	scanf("%d%s", &n, in);
	for (int i = 0; i < n; ++i)
		in[i] -= '0';
	for (int i = 0; i <= n; ++i) {
		dp[0][i] = 1;
	}
	LL res = 0;
	for (int pos = n - 1; pos >= 0; --pos) {
		for (int mask = 0; mask < (1 << bound); ++mask) {
			if (in[pos] == 0)
				dp[mask][pos] = dp[mask][pos + 1];
			else {
				int v = 0;
				for (int pos2 = pos; pos2 < n; ++pos2) {
					v = v * 2 + in[pos2];
					if (v > bound)
						break;
					if (mask == 0)
						debug("in range [%d, %d] with %d\n", pos, pos2, v);
					dp[mask | (1 << (v - 1))][pos] += dp[mask][pos2 + 1];
					dp[mask | (1 << (v - 1))][pos] %= MOD;
				}
			}
		}
		for (int k = 1; k <= bound; ++k) {
			res += dp[(1 << k) - 1][pos];
			res %= MOD;
		}
	}
	for (int pos = 0; pos < n; ++pos) {
		debug("pos %d:\n", pos);
		for (int mask = 0; mask < (1 << bound); ++mask) {
			debug("  mask %d => %d\n", mask, dp[mask][pos]);
		}
	}
	printf("%lld\n", res);
}