#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <ll, bool> pii;
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int p[kN], cnt = 0; bool flag[kN];
void Sieve() {
	for(int i = 2; i < kN; ++i) {
		if(!flag[i]) p[++cnt] = i;
		for(int j = 1; j <= cnt && i * p[j] < kN; ++j) {
			flag[i * p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
}

int Phi(int x) {
	int ret = x;
	for(int i = 1; (ll)p[i] * p[i] <= x; ++i) if(x % p[i] == 0) {
		ret = ret / p[i] * (p[i] - 1);
		while(x % p[i] == 0) x /= p[i];
	}
	if(x != 1) ret = ret / x * (x - 1);
	return ret;
}

ll Mod(ll x, ll p) {
	return x >= p ? x % p + p : x % p;
}
ll QPow(ll a, ll b, ll p) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = Mod(bas * bas, p)) if(b & 1) ret = Mod(ret * bas, p);
	return ret;
}

int n, m, mod[kN], A[kN];

ll Query(int l, int r, int p) {
	//std::cout << l << " " << r << " " << p << std::endl;
	if(l == r || mod[p] == 1) return Mod(A[l], mod[p]);
	return QPow(A[l], Query(l + 1, r, p + 1), mod[p]);
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m); Sieve();
		for(int i = 1; i <= n; ++i) rd(A[i]);
		mod[0] = m;
		for(int i = 1; i <= 70; ++i) mod[i] = Phi(mod[i - 1]);
		int q; rd(q);
		while(q--) {
			int l, r; rd(l, r);
			printf("%lld\n", Query(l, r, 0) % m);
		}
	} return 0;
}