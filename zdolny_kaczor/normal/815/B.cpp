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
const int MOD = 1e9 + 7;
const int MN = 2e5 + 44;
LL fac[MN], fin[MN];
LL pow(LL b, int e) {
	if (e == 0)
		return 1;
	if (e & 1)
		return pow(b, e - 1) * b % MOD;
	return pow(b * b % MOD, e / 2);
}
LL a[MN];
LL bin(int a, int b) {
	debug("bin %d %d = %lld\n", a, b, fac[a] * fin[b] % MOD * fin[a - b] % MOD);
	return fac[a] * fin[b] % MOD * fin[a - b] % MOD;
}
int main() {
	fac[0] = 1;
	for (int i = 1; i < MN; ++i)
		fac[i] = fac[i - 1] * i % MOD;
	fin[MN - 1] = pow(fac[MN - 1], MOD - 2);
	for (int i = MN - 2; i >= 0; --i)
		fin[i] = fin[i + 1] * (i + 1) % MOD;
	assert(fin[0] == 1);
	assert(fin[1410] * fac[1410] % MOD == 1);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	if (n == 1) {
		printf("%lld\n", a[0]);
		return 0;
	}
	int mul = 1;
	if (n % 2 || mul == -1) {
		for (int i = 0; i < n - 1; ++i) {
			a[i] += mul * a[i + 1];
			mul *= -1;
		}
		n--;
	}
	LL ans = 0;
	int c = 1 - n % 4 / 2;
	for (int i = 0; i < n; ++i)
		ans += bin(n / 2 - 1, i / 2) * a[i] * (1 - i * c % 2 * 2) % MOD;
	ans %= MOD;
	if (ans < 0)
		ans += MOD;
	printf("%lld\n", ans);	
}