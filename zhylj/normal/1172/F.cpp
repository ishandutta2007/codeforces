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
const int N = 1e6 + 5, B_1 = 1024, B_2 = 65536;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
ll s[N], a[N], p;
ll S(int l, int r) { return s[r] - s[l - 1]; }

ll f_1[N / B_1 + 5][B_1 + 5],
	f_2[N / B_2 + 5][B_2 + 5],
	g[B_2 + 5];
void Div1(int L, int R, ll *f) {
	if(L == R) f[1] = p - a[L];
	else {
		int mid = (L + R) >> 1; ll *f_r = f + mid - L + 1;
		Div1(L, mid, f); Div1(mid + 1, R, f_r);
		for(int i = 1, j = 0, k = 0; i <= R - L + 1; ++i) {
			while(j + k < i) {
				for(; k < R - mid &&
					(j == mid - L + 1 || f_r[k + 1] - S(L, mid) + j * p < f[j + 1])
					&& j + k < i; ++k);
				if(j + k < i) ++j;
			}
			g[i] = std::max(j == 0 ? -INF : f[j], (k == 0 ? -INF : f_r[k]) - S(L, mid) + j * p);
		}
		for(int i = 1; i <= R - L + 1; ++i) f[i] = g[i];
	}
}
void Div2(int L, int R, ll *f) {
	if(L / B_1 == R / B_1) {
		//printf("%d %d\n", L / B_1, (L - 1) / B_1);
		for(int i = 1; i <= R - L + 1; ++i)
			f[i] = f_1[L / B_1][i];
	} else {
		int mid = (L + R) >> 1; ll *f_r = f + mid - L + 1;
		Div2(L, mid, f); Div2(mid + 1, R, f_r);
		for(int i = 1, j = 0, k = 0; i <= R - L + 1; ++i) {
			while(j + k < i) {
				for(; k < R - mid &&
					(j == mid - L + 1 || f_r[k + 1] - S(L, mid) + j * p < f[j + 1])
					&& j + k < i; ++k);
				if(j + k < i) ++j;
			}
			g[i] = std::max(j == 0 ? -INF : f[j], (k == 0 ? -INF : f_r[k]) - S(L, mid) + j * p);
		}
		for(int i = 1; i <= R - L + 1; ++i) f[i] = g[i];
	}
}
void Init() {
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for(int i = 1; i < n / B_1; ++i) {
		int L = std::max(i * B_1, 1),
			R = std::min((i + 1) * B_1 - 1, n);
		Div1(L, R, f_1[i]);
	}
	for(int i = 1; i < n / B_2; ++i) {
		int L = std::max(i * B_2, 0),
			R = std::min((i + 1) * B_2 - 1, n);
		Div2(L, R, f_2[i]);
	}
}

ll Query(int l, int r) {
	ll cur = 0;
	if(l / B_1 == r / B_1) {
		for(int i = l; i <= r; ++i) {
			cur += a[i];
			cur -= cur >= p ? p : 0;
		}
		return cur;
	}
	for(int i = l; i < (l / B_1 + 1) * B_1; ++i) {
		cur += a[i];
		cur -= cur >= p ? p : 0;
	}
	if(l / B_2 == r / B_2) {
		for(int i = l / B_1 + 1; i < r / B_1; ++i) {
			int x = std::upper_bound(f_1[i] + 1, f_1[i] + B_1 + 1, cur) - f_1[i] - 1;
			cur += S(i * B_1, (i + 1) * B_1 - 1) - x * p;
		}
	} else {
		for(int i = l / B_1 + 1; i < (l / B_2 + 1) * (B_2 / B_1); ++i) {
			int x = std::upper_bound(f_1[i] + 1, f_1[i] + B_1 + 1, cur) - f_1[i] - 1;
			cur += S(i * B_1, (i + 1) * B_1 - 1) - x * p;
		}
		for(int i = l / B_2 + 1; i < r / B_2; ++i) {
			int x = std::upper_bound(f_2[i] + 1, f_2[i] + B_2 + 1, cur) - f_2[i] - 1;
			cur += S(i * B_2, (i + 1) * B_2 - 1) - x * p;
		}
		for(int i = (r / B_2) * (B_2 / B_1); i < r / B_1; ++i) {
			int x = std::upper_bound(f_1[i] + 1, f_1[i] + B_1 + 1, cur) - f_1[i] - 1;
			cur += S(i * B_1, (i + 1) * B_1 - 1) - x * p;
		}
	}
	for(int i = (r / B_1) * B_1; i <= r; ++i) {
		cur += a[i];
		cur -= cur >= p ? p : 0;
	}
	return cur;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, p);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		Init();
		for(int i = 1; i <= m; ++i) {
			int l, r; rd(l, r);
			printf("%lld\n", Query(l, r));
		}
	} return 0;
}