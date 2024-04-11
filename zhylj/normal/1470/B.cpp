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
const int kN = 1e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;
const ff kEps = 1e-8;

bool Sq(ll x) {
	ll y = (ll)(sqrt(x) + kEps);
	return y * y == x;
}

ll s[kN]; int p[kN], cnt = 0;
bool flag[kN];
void Sieve() {
	s[1] = 1;
	for(int i = 2; i < kN; ++i) {
		if(!flag[i]) {
			p[++cnt] = i;
			s[i] = i;
		}
		for(int j = 1; j <= cnt && p[j] * i < kN; ++j) {
			flag[i * p[j]] = true; s[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}

int n, q; ll A[kN];
std::map <ll, int> d;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T); Sieve();
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(A[i]);
			ll x = A[i];
			while(x != 1) {
				ll tmp = s[x];
				while(x % tmp == 0) x /= tmp;
				while(A[i] % (tmp * tmp) == 0)
					A[i] /= tmp * tmp;
			}
		}
		d.clear();
		d[1] = 0;
		for(int i = 1; i <= n; ++i) {
			if(!d.count(A[i])) d[A[i]] = 1;
			else ++d[A[i]];
		}
		int ans_0 = 0, ans_1 = 0, cur_tot = 0;
		for(auto i : d) ans_0 = std::max(ans_0, i.se);
		for(auto &i : d) if(i.se % 2 == 0) {
			cur_tot += i.se;
			i.se = 0;
		}
		d[1] += cur_tot;
		for(auto i : d) ans_1 = std::max(ans_1, i.se);
		rd(q);
		while(q--) {
			ll x; rd(x);
			if(!x) printf("%d\n", ans_0);
			else printf("%d\n", ans_1);
		}
	} return 0;
}