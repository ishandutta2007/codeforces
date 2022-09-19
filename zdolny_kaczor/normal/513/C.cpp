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
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
const int MN = 5;
PII a[MN];
LD p[MN];
const int MV = 1e4 + 44;
PII inter(PII a, PII b) {
	return MP (max(a.f, b.f), min(a.s, b.s));
}
int len(PII a) {
	return max(0, a.s - a.f + 1);
}
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d%d", &a[i].f, &a[i].s);
	}
	LD res = 0;
	FOR(r, 1, MV - 1) {
		FOR(k, 0, n - 1) {
			p[k] = len(inter(MP(r, MV), a[k])) / (LD) len(a[k]);
		}
		FOR(mask, 0, (1 << n) - 1) {
			LD pr = 1;
			FOR(k, 0, n - 1) {
				if (mask & (1 << k)) {
					pr *= p[k];
				}
				else {
					pr *= 1 - p[k];
				}
			}
			if (__builtin_popcount(mask) >= 2)
				res += pr;
		}
	}
	printf("%.9Lf\n", res);
}