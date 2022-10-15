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
const int kN = 2e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, a[kN], st[kN], cnt[kN], top = 0; ll ans = 0;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		int mx = 0, mx_cnt = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			a[i + n] = a[i];
			if(a[i] > a[mx]) mx = i;
		}
		for(int i = mx; i < n + mx; ++i) {
			while(top && a[st[top]] < a[i]) ans += cnt[top], cnt[top--] = 0;
			if(a[st[top]] != a[i]) {
				if(top) ++ans;
				st[++top] = i; cnt[top] = 1;
			} else {
				if(top) ans += cnt[top];
				if(top - 1 > 0) ++ans;
				++cnt[top];
			}
			//printf("%d %lld\n", a[i], ans);
		}
		while(top > 2 || (cnt[1] > 1 && top > 1)) ans += cnt[top--];
		printf("%lld\n", ans);
	} return 0;
}