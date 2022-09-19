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
const int MN = 11;
#else
const int MN = 1e6 + 44;
#define debug(...)
#define cerr if(0) cerr
#endif
#define cc(x) x.f, x.s
VI in[MN];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		in[x].PB(i);
	}
	LL ans = n * (n + 1ll) / 2ll * MN;
	for (int i = 0; i < MN; ++i) {
		int last = 0;
		for (auto c : in[i]) {
			int len = c - last - 1;
			ans -= len * (len + 1ll) / 2;
			last = c;
		}
		int len = n - last;
		ans -= len * (len + 1ll) / 2;
	}
	debug("%lld\n", ans);
	printf("%.6Lf\n", (ans * 2 - n) / (LD)n / n);
}