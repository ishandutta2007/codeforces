#include<bits/stdc++.h>
#undef DEB
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
#define count santohe
const int LOG = 16;
const int MN = 1 << LOG;
const int MK = 52;
int a[MN];
int dp[MK][MN];
int count[MN];
int cOu = 0;
void insert(int x) {
	debug("ins %d\n", x);
	if (x > 0) {
		if (count[x] == 0)
			cOu++;
		count[x]++;
	}
}
void rem(int x) {
	debug("rem %d\n", x);
	if (x > 0) {
		count[x]--;
		if (count[x] == 0)
			cOu--;
	}
}
int cou() {
	debug("cou = %d\n", cOu);
	return cOu;
}
void reset() {
	debug("reset\n");
	for (int i = 0; i < MN; ++i)
		count[i] = 0;
	cOu = 0;
}
void run(int source[MN], int dest[MN]) {
	static int bound[MN];
	bound[0] = -1;
	for (int i = LOG - 1; i >= 0; --i) {
		debug("new try\n");
		int step = (1 << i);
		int from = MN - (1 << i);
		for (int k = MN - (1 << i); k >= 0; k--) {
			debug("in k = %d from = %d\n", k, from);
			if (from > k && dest[from] < source[k] + cou()) {
				dest[from] = source[k] + cou();
				bound[from] = k;
				debug("update bound[%d] = %d, dest[%d] = %d\n", from, bound[from], from, dest[from]);
			}
			while (bound[from - step] == k) {
				debug("mass erase\n");
				for (int j = from; j > from - 2 * step; --j)
					rem(a[j]);
				from -= 2 * step;
				if (from > k && dest[from] < source[k] + cou()) {
					debug("update\n");
					dest[from] = source[k] + cou();
					bound[from] = k;
				}
			}
			insert(a[k]);
		}
		reset();
	}
	for (int i = 1; i < MN; ++i)
		debug("dp[%d] = %d\n", i, dest[i]);
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i <= k; ++i) {
		run(dp[i - 1], dp[i]);
	}
	printf("%d\n", dp[k][MN - 1]);
}