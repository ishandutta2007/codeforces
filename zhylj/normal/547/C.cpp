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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int p[kN], tot; bool flag[kN], in_shlf[kN];
ll mu[kN], a[kN], cnt[kN], ans = 0;
void Sieve() {
	memset(flag, true, sizeof(flag));
	mu[1] = 1;
	for(int i = 2; i < kN; ++i) {
		if(flag[i]) {
			p[++tot] = i;
			mu[i] = -1;
		}
		for(int j = 1; j <= tot && i * p[j] < kN; ++j) {
			flag[i * p[j]] = false;
			if(i % p[j] == 0) { mu[i * p[j]] = 0; break; }
			else mu[i * p[j]] = -mu[i];
		}
	}
}
void Add(ll x) {
	for(ll i = 1; i * i <= x; ++i) if(x % i == 0) {
		ans += mu[i] * cnt[i];
		++cnt[i];
		if(i * i != x) {
			ans += mu[x / i] * cnt[x / i];
			++cnt[x / i];
		}
	}
}
void Del(ll x) {
	for(ll i = 1; i * i <= x; ++i) if(x % i == 0) {
		--cnt[i];
		ans -= mu[i] * cnt[i];
		if(i * i != x) {
			--cnt[x / i];
			ans -= mu[x / i] * cnt[x / i];
		}
	}
}

int n, q;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, q); Sieve();
		for(int i = 1; i <= n; ++i) rd(a[i]);
		while(q--) {
			int x; rd(x);
			if(!in_shlf[x]) Add(a[x]);
			else Del(a[x]);
			in_shlf[x] = !in_shlf[x];
			printf("%lld\n", ans);
		}
	} return 0;
}