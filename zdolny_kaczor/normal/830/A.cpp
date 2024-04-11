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
const int MN = 2e3 + 44;
int a[MN];
int b[MN];
int adif(int x, int y) {
	return abs(x - y);
}
int main() {
	int n, k, p;
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < k; ++i)
		scanf("%d", b + i);
	sort(a, a + n);
	sort(b, b + k);
	int ans = 2e9;
	for (int r = 0; r + n <= k; ++r) {
		int dist = 0;
		for (int i = 0; i < n; ++i)
			maxi(dist, adif(a[i], b[i + r]) + adif(b[i + r], p));
		mini(ans, dist);
	}
	printf("%d\n", ans);
}