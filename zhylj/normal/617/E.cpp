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
const int N = 1.2e6 + 5;

struct Query {
	int l, r, idx;
} itv[N];
int n, m, k, b_siz, a[N], b[N];
ll cur_ans = 0, ans[N];
void Add(int x) {
	cur_ans += b[x ^ k];
	++b[x];
}
void Rmv(int x) {
	--b[x];
	cur_ans -= b[x ^ k];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, k); b_siz = sqrt(n);
		for(int i = 1; i <= n; ++i) rd(a[i]), a[i] ^= a[i - 1];
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			--u;
			itv[i] = (Query) { u, v, i };
		}
		std::sort(itv + 1, itv + m + 1, [](const Query &x, const Query &y) {
			return x.l / b_siz != y.l / b_siz ? x.l < y.l : (
				(x.l / b_siz) % 2 == 1 ? x.r < y.r : x.r > y.r
			);
		});
		for(int i = 1, l = 0, r = -1; i <= m; ++i) {
			int L = itv[i].l, R = itv[i].r;
			while(r < R) Add(a[++r]);
			while(r > R) Rmv(a[r--]);
			while(l < L) Rmv(a[l++]);
			while(l > L) Add(a[--l]);
			ans[itv[i].idx] = cur_ans;
		}
		for(int i = 1; i <= m; ++i)
			printf("%lld\n", ans[i]);
	} return 0;
}