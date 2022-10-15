#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5;

int n, m, c, X[N], P[N], d[N]; ll s[N], t[N], f[N], pre[N], suf[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		c = 0;
		rd(n, m);
		for(int i = 1; i <= n; ++i) 
			s[i] = t[i] = f[i] = X[i] = P[i] = 0;
		for(int i = 1; i <= n; ++i) {
			rd(X[i], P[i]);
			d[++c] = X[i];
		}
		std::sort(d + 1, d + c + 1);
		c = std::unique(d + 1, d + c + 1) - d - 1;
		for(int i = 0; i <= c + 1; ++i)
			pre[i] = suf[i] = -1e18;
		for(int i = 1; i <= n; ++i) {
			int l = std::lower_bound(d + 1, d + c + 1, X[i] - P[i]) - d,
				r = std::upper_bound(d + 1, d + c + 1, X[i] + P[i]) - d - 1,
				x;
			X[i] = std::lower_bound(d + 1, d + c + 1, X[i]) - d;
			x = X[i];
			s[l] += P[i] - d[x]; ++t[l];
			s[x + 1] += 2 * d[x]; t[x + 1] -= 2;
			s[r + 1] -= P[i] + d[x]; ++t[r + 1];
		}
		for(int i = 1; i <= c; ++i) {
			s[i] += s[i - 1];
			t[i] += t[i - 1];
		}
		for(int i = 1; i <= c; ++i) {
			f[i] = s[i] + t[i] * d[i];
			if(f[i] > m) {
				ll k = f[i] - m;
				pre[i] = std::max(pre[i], k + d[i]);
				suf[i] = std::max(suf[i], k - d[i]);
			}
		}
		for(int i = c; i; --i)
			pre[i] = std::max(pre[i + 1], pre[i]);
		for(int i = 1; i <= c; ++i)
			suf[i] = std::max(suf[i - 1], suf[i]);
		for(int i = 1; i <= n; ++i) {
			if(P[i] - d[X[i]] >= suf[X[i]] && P[i] + d[X[i]] >= pre[X[i]])
				printf("1");
			else printf("0");
		}
		printf("\n");
	} return 0;
}