#include <bits/stdc++.h>
#define N 256101
#define gcd __gcd
using namespace std;

typedef long long ll;
const ll INF = 0x188434861e654c51ll;

int n;
ll __scx_t[N], *a = __scx_t, _a[N];
ll k, L, R, M;

inline void add(ll &x, const ll y) {(x += y) >= INF ? x = INF : 0;}

int brute_force(){
	int T, i;
	for(T = 1; ; ++T){
		for(i = 2; i <= n; ++i) add(a[i], a[i - 1]);
		if(a[n] >= k) return printf("%d\n", T), 0;
	}
	return -1;
}

ll C(ll n, ll m){
	if(m << 1 > n) m = n - m;
	ll i, d, e, res = 1;
	for(i = 1; i <= m; ++i){
		// res = res * (n - i + 1) / i;
		d = gcd(res, i);
		res /= d; e = (n - i + 1) * d / i;
		res <= INF / e ? res *= e : (res = INF);
	}
	return res;
}

bool test(ll T){
	int i; ll coe, res = 0;
	for(--T, i = 1; i <= n; ++i)
		if(a[i]) (coe = C(n - i + T, n - i)) <= _a[i] ? add(res, a[i] * coe) : void(res = INF);
	return res >= k;
}

int main(){
	int i;
	scanf("%d%lld", &n, &k);
	for(i = 1; i <= n; ++i)
		if(scanf("%lld", a + i), a[i] >= k) return putchar(48), putchar(10), 0;
	for(; !a[1]; ++a, --n);
	if(n >= 20) return brute_force();
	for(i = 1; i <= n; ++i) a[i] ? _a[i] = INF / a[i] : 0;
	for(L = 1, R = k; L < R; )
		test(M = L + R >> 1) ? R = M : (L = M + 1);
	printf("%lld\n", R);
	return 0;
}