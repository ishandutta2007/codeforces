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
#define EB emplace_back
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
const bool debug = 
#ifdef DEB
true;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
false;
#define debug(...)
#define cerr if(0) cout
#endif
#define cc(x) x.f, x.s
#define here() debug("LINE: %d\n", __LINE__)
const int MN = 1e5 + 44;
int a[MN];
int main() {
	int n;
	LL k;
	scanf("%d%lld", &n, &k);
	REP(i, n)
		scanf("%d", a + i);
	sort(a, a + n);
	LL sum = 0;
	int last = 0;
	PII ans = MP(0, 0);
	REP(i, n) {
		sum += (i - last) * 1ll * (a[i] - (i ? a[i - 1] : 0));
		while (sum > k) {
			sum -= (a[i] - a[last]);
			last++;
		}
		debug("i = %d sum = %lld last = %d\n", i, sum, last);
		maxi(ans, MP(i - last + 1, -a[i]));
	}
	printf("%d %d\n", ans.f, -ans.s);
}