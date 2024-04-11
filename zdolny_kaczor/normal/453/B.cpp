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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
const int P = 16, R = 59, MN = 111;
int a[MN];
int primes[P] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int divs[R];
PII dp[MN][1 << P];
int main() {
	for (int i = 1; i < R; ++i) {
		for (int j = 0; j < P; ++j)
			if (i % primes[j] == 0) {
				divs[i] |= 1 << j;
			}
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = n - 1; i >= 0; --i) {
		for (int mask = 0; mask < (1 << P); ++mask) {
			dp[i][mask] = MP(1e7, 14);
			for (int v = 1; v < R; ++v) {
				if (((~mask) & divs[v]) == 0)
					mini(dp[i][mask], MP(dp[i + 1][mask & ~divs[v]].f + abs(a[i] - v), v));
			}
		}
	}
	int mask = (1 << P) - 1;
	for (int i = 0; i < n; ++i) {
		debug("mask = %d cost left = %d\n", mask, dp[i][mask].f);
		printf("%d ", dp[i][mask].s);
		mask &=~ divs[dp[i][mask].s];
	}
	printf("\n");
}