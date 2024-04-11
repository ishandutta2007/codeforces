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

typedef long long ll;
typedef double ff;
typedef std::pair<int, int> pii;

const int kN = 1e5 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

ll a[kN], b[kN]; bool s1[kN], s2[kN]; int n, m, k, q;
int main() { int T = 1; rd(T);
	while(T--) {
		memset(s1, false, sizeof(s1));
		memset(s2, false, sizeof(s2));
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= n; ++i) rd(b[i]);
		for(int i = 1; i <= n; ++i) {
			if(a[i] == -1) s1[i] = true;
			if(a[i] == 1) s2[i] = true;
			s1[i] = s1[i - 1] || s1[i];
			s2[i] = s2[i - 1] || s2[i];
		}
		bool flag = true;
		for(int i = n; i; --i) {
			if(b[i] == a[i]) continue;
			if(b[i] < a[i] && s1[i - 1]) continue;
			if(b[i] > a[i] && s2[i - 1]) continue;
			flag = false;
		}
		printf(flag ? "YES\n" : "NO\n");
	} return 0;
}