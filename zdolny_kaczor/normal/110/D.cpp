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
vector <int> lucky;
const int BOUND = 1e9 + 44;
void gen_lucky(LL b) {
	if (b > BOUND) return;
	lucky.push_back((int)b);
	gen_lucky(b * 10 + 4);
	gen_lucky(b * 10 + 7);
}
LL len(PII a) {
	return max(0, a.s - a.f + 1);
}
PII inter(PII a, PII b) {
	return MP(max(a.f, b.f), min(a.s, b.s));
}
LL pro(PII rand, PII in) {
	LL ret = len(inter(in, rand));
	assert(ret >= 0);
	return len(inter(in, rand));
}
int main() {
	gen_lucky(4);
	gen_lucky(7);
	lucky.push_back(BOUND);
	lucky.push_back(-1);
	sort(ALL(lucky));
	int l1, r1, l2, r2, k;
	scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &k);
	LL res = 0;
	PII i1 = MP(l1, r1);
	PII i2 = MP(l2, r2);
	for (int i = 1; i + k < lucky.size(); ++i) {
		PII one = MP(lucky[i - 1] + 1, lucky[i]), two = MP(lucky[i + k - 1], lucky[i + k] - 1);
		res += pro(i1, one) * pro(i2, two) + pro(i1, two) * pro(i2, one) - pro(inter(i1, i2), inter(one, two)) * pro(inter(i1, i2), inter(one, two));
	}
	LL den = len(i1) * len(i2);
	LL num = res;
	debug("%lld %lld\n", num, den);
	printf("%.11Lf\n", (LD)num / len(i1) / len(i2));
}