//Maciej Houbowicz
#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
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
#ifdef D
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;
const int MN = 1e6 + 44;
int cou[MN];
int a[MN];
#define query pair <pair <long long, int>, pair <int, int> >
pair <pair <long long, int>, pair <int, int> > queries[MN];
LL sum = 0;
int edits = 0;
void add(int x) {
    edits++;
	sum += x * (cou[x] * 2LL + 1);
	cou[x]++;
}
void rem(int x) {
    edits++;
	cou[x]--;
	sum -= x * (cou[x] * 2LL + 1);
}
LL ans[MN];
const int SQ = 1.2e3;
int order = 22;
long long nr(int x, int y, int deg)
{
	if (deg == 0)
		return 0;
	else
	{
		int side = 1 << (deg - 1);
		long long cou = 1LL << (2 * deg - 2);
		if (x < side && y < side)
			return nr(y, x, deg - 1);
		else if (x < side && y >= side)
			return cou + nr(x, y - side, deg - 1);
		else if (x >= side && y >= side)
			return cou * 2 + nr(x - side, y - side, deg - 1);
		else
			return cou * 3 + nr(side - y - 1, 2 * side - x - 1, deg - 1);
	}
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		queries[i] = MP(MP(nr(l, r, order), i), MP(l, r));
	}
	sort(queries, queries + q);
	for (int i = queries[0].s.f; i <= queries[0].s.s; ++i) {
		add(a[i]);
	}
	ans[queries[0].f.s] = sum;
	for (int i = 1; i < q; ++i) {
	    if (queries[i].s.f > queries[i - 1].s.s || queries[i].s.s < queries[i - 1].s.f) {
	        for (int k = queries[i - 1].s.f; k <= queries[i - 1].s.s; ++k)
	            rem(a[k]);
	        for (int k = queries[i].s.f; k <= queries[i].s.s; ++k)
	            add(a[k]);
	    }
	    else {
    		debug("%d - %d\n", queries[i].s.f, queries[i].s.s);
    		if (queries[i - 1].s.f > queries[i].s.f) {
    			for (int k = queries[i - 1].s.f - 1; k >= queries[i].s.f; --k) {
    				debug("add %d\n", k);
    				add(a[k]);
    			}
    		}
    		else {
    			for (int k = queries[i].s.f - 1; k >= queries[i - 1].s.f; --k) {
    				debug("rem %d\n", k);
    				rem(a[k]);
    			}
    		}
    		if (queries[i - 1].s.s > queries[i].s.s) {
    			for (int k = queries[i].s.s + 1; k <= queries[i - 1].s.s; ++k) {
    				debug("rem %d\n", k);
    				rem(a[k]);
    			}
    		}
    		else {
    			for (int k = queries[i - 1].s.s + 1; k <= queries[i].s.s; ++k) {
    				debug("add %d\n", k);
    				add(a[k]);
    			}
    		}
	    }
		ans[queries[i].f.s] = sum;
	}
	assert(edits <= 8e7);
	for (int i = 0; i < q; ++i ){
		printf("%lld\n", ans[i]);
	}
}