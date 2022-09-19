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
#else
#define debug(...)
#define cerr if(0) cerr
#endif
#define cc(x) x.f, x.s
#define next ascroesacr
const int MN = 2e5 + 44;
pair <int, PII> in[MN * 2];
bool red[MN];
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		int l, r;
		scanf("%d%d", &l, &r);
		in[i] = MP(l, MP(i, 1));
		in[i + n] = MP(r + 1, MP(i, -1));
	}
	sort(in, in + n * 2);
	int cou = 0, ksor = 0;
	for (int i = 0; i < n * 2; ++i) {
		cou += in[i].s.s;
		ksor ^= in[i].s.f;
		debug("cou = %d, ksor = %d\n", cou, ksor);
		if ((i + 1 == n * 2 || in[i].f != in[i + 1].f) && cou == 1) {
			red[ksor] = true;
			debug("ban\n");
		}
	}
	for (int i = 0; i < n; ++i)
		if (!red[i]) {
			printf("%d\n", i + 1);
			return 0;
		}
	printf("-1");
}