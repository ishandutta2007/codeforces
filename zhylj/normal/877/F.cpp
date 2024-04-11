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

struct Ask {
	int l, r, idx;
} Q[N];
int n, k, B, c; ll a[N], d[N], ans[N], cur_ans;

int buk[N], pos[N], l_pos[N], r_pos[N];
void AddL(int i) {
	cur_ans += buk[r_pos[i]];
	++buk[pos[i]];
}
void RmvL(int i) {
	--buk[pos[i]];
	cur_ans -= buk[r_pos[i]];
}
void AddR(int i) {
	cur_ans += buk[l_pos[i]];
	++buk[pos[i]];
}
void RmvR(int i) {
	--buk[pos[i]];
	cur_ans -= buk[l_pos[i]];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k); B = ceil(sqrt(n));
		for(int i = 1; i <= n; ++i) {
			int t; rd(t);
			a[i] = (t == 1 ? 1 : -1);
		}
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			a[i] *= x;
		}
		for(int i = 1; i <= n; ++i)
			a[i] += a[i - 1];
		for(int i = 0; i <= n; ++i) {
			d[++c] = a[i];
			d[++c] = a[i] + k;
			d[++c] = a[i] - k;
		}
		std::sort(d, d + c + 1);
		c = std::unique(d, d + c + 1) - d - 1;
		for(int i = 0; i <= n; ++i) {
			pos[i] = std::lower_bound(d, d + c + 1, a[i]) - d;
			l_pos[i] = std::lower_bound(d, d + c + 1, a[i] - k) - d;
			r_pos[i] = std::lower_bound(d, d + c + 1, a[i] + k) - d;
		}
		int q; rd(q);
		for(int i = 1; i <= q; ++i)  {
			int l, r; rd(l, r);
			Q[i] = (Ask) { l - 1, r, i };
		}
		std::sort(Q + 1, Q + q + 1, [](const Ask &x, const Ask &y) {
			return x.l / B != y.l / B ? x.l / B < y.l / B :
				(x.l / B % 2 == 0 ? x.r < y.r : x.r > y.r);
		});
		buk[pos[0]] = 1;
		for(int i = 1, L = 0, R = 0; i <= q; ++i) {
			while(R < Q[i].r) AddR(++R);
			while(L > Q[i].l) AddL(--L);
			while(L < Q[i].l) RmvL(L++);
			while(R > Q[i].r) RmvR(R--);
			ans[Q[i].idx] = cur_ans;
		}
		for(int i = 1; i <= q; ++i)
			printf("%lld\n", ans[i]);
	} return 0;
}