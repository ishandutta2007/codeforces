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
int main() {
	int c1, c2, x, y;
	scanf("%d%d%d%d", &c1, &c2, &x, &y);
	LL low = 0, high = 1e13, ans = 0;
	while (low <= high) {
		LL med = (low + high) / 2;
		if (med - med / x / y >= c1 + c2 && med - med / x >= c1 && med - med / y >= c2) {
			ans = med;
			high = med - 1;
		}
		else {
			low = med + 1;
		}
	}
	printf("%lld\n", ans);
}