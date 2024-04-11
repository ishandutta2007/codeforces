#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP(a, b) make_pair(a, b)
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
#else
#define debug(...)
#define cerr if(0) cerr
#endif
const int MN = 201, MP = 5001;
PII in[MN];
int dp[2][MN][MP];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		LL a;
		scanf("%lld", &a);
		while (a % 2 == 0) {
			in[i].f++;
			a /= 2;
		}
		while (a % 5 == 0) {
			in[i].s++;
			a /= 5;
		}
	}
	for (int i = 0; i < MP; ++i)
		for (int k = 0; k < MN; ++k)
			dp[0][k][i] = - 1e7;
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			for (int b = 0; b < MP; ++b) {
				dp[i % 2][j][b] = dp[(i - 1) % 2][j][b];
				if (j >= 1 && b >= in[i].s) {
					maxi(dp[i % 2][j][b], dp[(i - 1) % 2][j - 1][b - in[i].s] + in[i].f);
				}
			}
	int ans = 0;
	for (int i = 0; i < MP; ++i) {
		maxi(ans, min(i, dp[n % 2][k][i]));
	}
	
	printf("%d\n", ans);
}