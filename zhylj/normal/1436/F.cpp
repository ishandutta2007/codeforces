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
typedef std::pair <int, int> pii;
const int kN = 1e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	if(b < 0) { a = QPow(a, kMod - 2); b = -b; }
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int p[kN], mu[kN], cnt = 0;
bool is_p[kN];
void Sieve() {
	memset(is_p, true, sizeof(is_p));
	mu[1] = 1; is_p[1] = false;
	for(int i = 2; i < kN; ++i) {
		if(is_p[i]) {
			p[++cnt] = i;
			mu[i] = -1;
		}
		for(int j = 1; j <= cnt && i * p[j] < kN; ++j) {
			is_p[i * p[j]] = false;
			if(i % p[j] == 0) { mu[i * p[j]] = 0; break; }
			mu[i * p[j]] = -mu[i];
		}
	}
}

int n; ll c1[kN], c2[kN], siz[kN];

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	Sieve();
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i)  {
			ll x, freq; rd(x, freq);
			for(ll j = 1; j * j <= x; ++j) if(x % j == 0) {
				siz[j] += freq;
				c1[j] = (c1[j] + x * freq) % kMod;
				c2[j] = (c2[j] + x * x % kMod * freq) % kMod;
				if(j * j != x) {
					siz[x / j] += freq;
					c1[x / j] = (c1[x / j] + x * freq) % kMod;
					c2[x / j] = (c2[x / j] + x * x % kMod * freq) % kMod;
				}
			}
		}
		ll ans = 0;
		for(int i = 1; i < kN; ++i) if(siz[i] > 1) {
			ans = (ans + mu[i] * (
					(c1[i] * c1[i] % kMod - c2[i]) % kMod *
						((QPow(2, siz[i] - 2) + (siz[i] - 2) % kMod * QPow(2, siz[i] - 3) % kMod) % kMod) % kMod
					+ c2[i] *
						((siz[i] - 1) % kMod * QPow(2, siz[i] - 2) % kMod) % kMod
				) % kMod + kMod) % kMod;
		}
		printf("%lld\n", ans);
	} return 0;
}