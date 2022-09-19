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
LL gcd(LL a, LL b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
vector <LL> divs;
int main() {
	LL a, b;
	scanf("%lld%lld", &a, &b);
	for (LL i = 1; i * i <= a; ++i)
		if (a % i == 0) {
			divs.PB(i);
			if (i * i < a)
				divs.PB(a / i);
		}
	LL ans = 0;
	while (b > 1) {
		LL g = gcd(a, b);
		debug("gcd %lld %lld = %lld\n", a, b, g);
		a /= g;
		b /= g;
		LL step = 1e18;
		for (auto d : divs) {
			if (d != 1 && a % d == 0) {
				mini(step, b % d);
			}
		}
		ans += step;
		b -= step;
	}
	ans += b;
	printf("%lld\n", ans);
}