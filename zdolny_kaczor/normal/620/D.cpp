#include<bits/stdc++.h>
using namespace std;
#define PII pair<LL,LL>
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
#define VPII vector< pair <LL, LL> > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define VLL vector <LL>
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#define cerr if(0) cerr
#endif
PII closest(const VLL &a, const VLL &b) {
	if (a.empty() || b.empty())
		return make_pair((LL)1e18, (LL) 1e18);
	debug("find closest:\n  ");
	for (auto aa : a)
		debug("%lld ", aa);
	debug("\n  ");
	for (auto bb : b)
		debug("%lld ", bb);
	debug("\n");
	PII ans = MP(a[0], b.back());
	for (int i = 0, j = siz(b) - 1; i < siz(a) && j >= 0; ) {
		if (abs(a[i] + b[j]) < abs(ans.first + ans.second))
			ans = MP(a[i], b[j]);
		if (a[i] + b[j] > 0)
			j--;
		else
			i++;
	}
	debug("found %lld %lld\n", ans.f, ans.s);
	return ans;
}
const int MN = 2e3 + 44;
int a[MN], b[MN];
LL sum(int a[MN], int n) {
	LL s = 0;
	REP(i, n)
		s += a[i];
	debug("return %lld\n", s);
	return s;
}
VLL pairs(int a[MN], int n, int mul) {
	LL s = sum(a, n);
	VLL ans;
	for (int i = 0; i < n; ++i)
		for (int k = i + 1; k < n; ++k)
			ans.PB(mul * (s - 2ll * a[i] - 2ll * a[k]));
	sort(ALL(ans));
	return ans;
}
int find_one(int a[MN], int n, LL val) {
	debug("find one %d\n", val);
	LL s = sum(a, n);
	REP(i, n)
		if (s - 2ll * a[i] == val)
			return i + 1;
	assert(false);
}
PII find_two(int a[MN], int n, LL val) {
	LL s = sum(a, n);
	REP(i, n)
		FOR(j, i + 1, n - 1)
			if (val == s - 2ll * a[i] - 2ll * a[j])
				return make_pair(i + 1, j + 1);
	printf("dupa blada\n");
	return make_pair(7, 7);
}
VLL singletons(int a[MN], int n, int mul) {
	LL s = sum(a, n);
	VLL ans;
	REP(i, n)
		ans.PB(mul * (s - 2ll * a[i]));
	sort(ALL(ans));
	return ans;
}
int main() {
	int n, m;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", a + i);
	scanf("%d", &m);
	REP(i, m)
		scanf("%d", b + i);
	PII one = closest(singletons(a, n, 1), singletons(b, m, -1));
	PII two = closest(pairs(a, n, 1), pairs(b, m, -1));
	debug("make non\n");
	PII non = make_pair(sum(a, n), -sum(b, m));
	debug("size=%d\n", sizeof(non));
	LL opt = min(abs(one.f + one.s), min(abs(two.f + two.s), abs(non.f + non.s)));
	printf("%lld\n", opt);
	debug("compared %lld %lld %lld\n", abs(one.f + one.s), abs(two.f + two.s), abs(non.f + non.s));
	if (opt == abs(one.f + one.s)) {
		printf("1\n%d %d\n", find_one(a, n, one.f), find_one(b, m, -one.s));
	}
	else if (opt == abs(two.f + two.s)) {
		PII aa = find_two(a, n, two.f), bb = find_two(b, m, -two.s);
		printf("2\n%lld %lld\n%lld %lld\n", aa.f, bb.f, aa.s, bb.s);
	}
	else {
		printf("0\n");
	}
}//