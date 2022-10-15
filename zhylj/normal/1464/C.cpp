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

int n; ll t, cnt[kN]; char str[kN];

bool Check(ll x) {
	for(ll i = 50; ~i; --i) if((t >> i) & 1) {
		ll res = 1LL << i;
		for(int j = 25; ~j; --j) {
			while(cnt[j] && (1LL << j) <= res) {
				--cnt[j]; res -= (1LL << j);
			}
		}
		if(res) return false;
	}
	return true;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, t);
		scanf("%s", str + 1);
		ll s = 0;
		for(int i = 1; i <= n; ++i) {
			if(i <= n - 2) ++cnt[str[i] - 'a'];
			s += 1LL << (str[i] - 'a');
		}
		t += s;
		if(t < 0 || t % 2 != 0) {
			printf("No\n");
			return 0;
		}
		t >>= 1;
		t -= 1LL << (str[n] - 'a');
		if(t < 0) {
			printf("No\n");
			return 0;
		}
		printf(Check(t) ? "Yes\n" : "No\n");
	} return 0;
}