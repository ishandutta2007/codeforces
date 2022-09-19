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
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", a + i);
	VI lens;
	FOR(i, 1, n) {
		if (a[i] == 0) continue;
		int wh = i, len = 0;
		do {
			len++;
			int t = wh;
			wh = a[wh];
			a[t] = 0;
		}
		while (wh != i);
		lens.PB(len);
	}
	sort(ALL(lens));
	LL sum = 0;
	for (auto c : lens)
		sum += c * 1ll * c;
	if (siz(lens) > 1) {
		reverse(ALL(lens));
		sum += lens[0] * 2ll * lens[1];
	}
	printf("%lld\n", sum);
}