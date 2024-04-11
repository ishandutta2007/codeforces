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
int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
LL cei(LL a, int b) {
	debug("cei %lld / %d = %lld\n", a, b, (a + b - 1) / b);
	return (a + b - 1) / b;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int p, q, pd, qd;
		scanf("%d%d%d%d", &p, &q, &pd, &qd);
		if (pd == qd) {
			if (p == q)
				printf("0\n");
			else
				printf("-1\n");
		}
		else if (pd == 0) {
			if (p == 0)
				printf("0\n");
			else
				printf("-1\n");
		}
		else {
			int g = gcd(pd, qd);
			pd /= g;
			qd /= g;
			LL goal = max(cei(p * (long long)qd, pd), cei((q - p) * (LL)qd, (qd - pd)));
			maxi(goal, 0ll);
			maxi(goal, (LL) q);
			debug("mini = %lld\n", goal);
			goal = cei(goal, qd) * qd;
			debug("ans=%lld\n", goal - q);
			printf("%lld\n", goal - q);
		}
	}
}