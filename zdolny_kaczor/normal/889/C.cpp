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
const int mod = 1e9 + 7;
const int MN = 1e6 + 44;
LL dp[MN];
LL fac[MN], fin[MN];
LL powe(LL b, int e) {
	if (e == 0) return 1;
	if (e % 2) return powe(b, e - 1) * b % mod;
	return powe(b * b % mod, e / 2);
}
LL bin(int a, int b) {
	return fac[a] * fin[b] % mod * fin[a - b] % mod;
}
LL inv(int n) {
	return fin[n] * fac[n - 1] % mod;
}
int main() {
	fac[0] = 1;
	FOR(i, 1, MN - 1)
		fac[i] = fac[i - 1] * 1ll * i % mod;
	fin[MN - 1] = powe(fac[MN - 1], mod - 2);
	FORD(i, MN - 2, 0)
		fin[i] = fin[i + 1] * (1ll + i) % mod;
	REP(i, 100)
		assert(fac[i] * fin[i] % mod == 1);
	FOR(i, 1, 100)
		assert(i * inv(i) % mod == 1);
	int n, k;
	scanf("%d%d", &n, &k);
	dp[1] = 1;
	FOR(i, 2, k + 1) {
		dp[i] = 1;
	}
	LL last = k;
	FOR(l, k + 1, n) {
		debug("assign last dp[%d] = %lld\n", l, last);
		dp[l] = last * inv(l - 1) % mod;
		last += dp[l];
		last -= dp[l - k];
		last %= mod;
	}
	FOR(i, 1, n) {
		dp[i] *= fac[i - 1];
		dp[i] %= mod;
	}
	LL ans = fac[n];
	FOR(i, 1, n) {
		ans -= fac[n - i] * dp[i] % mod * bin(n - 1, i - 1) % mod;
	}
	ans %= mod;
	if (ans < 0)
		ans += mod;
	FOR(i, 1, n)
		debug("dp[%d] = %d\n", i, dp[i]);
	printf("%d\n", ans);
	return 0;
}