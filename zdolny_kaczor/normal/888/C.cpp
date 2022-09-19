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
const int MN = 1e6 + 44;
char in[MN];
VI wh[128];
int main() {
	scanf("%s", in);
	int n = strlen(in);
	REP(i, 128)
		wh[i].PB(0);
	for (int i = 0; in[i]; ++i)
		wh[in[i]].PB(i + 1);
	REP(i, 128)
		wh[i].PB(n + 1);
	int ans = MN;
	REP(i, 128) {
		int far = 0;
		REP(k, siz(wh[i]) - 1) {
			maxi(far, wh[i][k + 1] - wh[i][k]);
		}
		mini(ans, far);
	}
	printf("%d\n", ans);
}