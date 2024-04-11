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

LL mod = 1e9 + 7;
LL a[21];
#define MOD mod
LL fin[21];
LL powe(LL base, int e) {
	if (e == 0)
		return 1;
	if (e % 2)
		return powe(base, e - 1) * base % mod;
	return powe(base * base % mod, e / 2);
}
LL binom(LL a, int b) {
	debug("binom %lld %d", a, b);
	LL res = 1;
	REP(i, b)
		res = res * ((a - i) % mod) % mod;
	res = res * fin[b] % mod;
	debug("=%lld\n", res);
	return res;
}
int main() {
	int n;
	LL s;
	scanf("%d%lld", &n, &s);
	fin[0] = 1;
	FOR(i, 1, 20)
		fin[i] = powe(i, mod - 2);
	FOR(i, 2, 20) {
		fin[i] *= fin[i - 1];
		fin[i] %= MOD;
	}
	REP(i, n)
		scanf("%lld", a + i);
	LL res = 0;
	REP(mask, (1 << n)) {
		LL left = s;
		REP(k, n)
			if ((1 << k) & mask)
				left -= a[k] + 1;
		debug("left %lld\n", left);
		if (left >= 0) {
			int sign = __builtin_popcount(mask) % 2 ? -1 : 1;
			res = (res + sign * binom(left + n - 1, n - 1)) % mod;
		}
	}
	if (res < 0)
		res += mod;
	printf("%lld\n", res);
}