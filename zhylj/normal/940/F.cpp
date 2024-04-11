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
	int l, r, t, i;
} Q[N];
pii M[N];
int n, q, B, q_1, q_2, c[N], d[N], val_cnt, ans[N];

int buk[N], buk_cnt[N];
void Add(int x) {
	--buk_cnt[buk[c[x]]];
	++buk[c[x]];
	++buk_cnt[buk[c[x]]];
}
void Rmv(int x) {
	--buk_cnt[buk[c[x]]];
	--buk[c[x]];
	++buk_cnt[buk[c[x]]];
}
void Modify(int L, int R, int t) {
	if(L <= M[t].fi && M[t].fi <= R) {
		Rmv(M[t].fi);
		std::swap(M[t].se, c[M[t].fi]);
		Add(M[t].fi);
	} else std::swap(M[t].se, c[M[t].fi]);
}
int Query() {
	for(int i = 0; ; ++i)
		if(!buk_cnt[i]) return i;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, q); B = ceil(pow(n, 0.66)) + 0.5;
		for(int i = 1; i <= n; ++i) rd(c[i]), d[++val_cnt] = c[i];
		for(int i = 1; i <= q; ++i) {
			int opt, x, y; rd(opt, x, y);
			if(opt == 1) Q[++q_1] = (Ask) { x, y, q_2, q_1 };
			else M[++q_2] = mkp(x, y), d[++val_cnt] = y;
		}
		std::sort(d + 1, d + val_cnt + 1);
		val_cnt = std::unique(d + 1, d + val_cnt + 1) - d - 1;
		for(int i = 1; i <= n; ++i)
			c[i] = std::lower_bound(d + 1, d + val_cnt + 1, c[i]) - d;
		for(int i = 1; i <= q_2; ++i)
			M[i].se = std::lower_bound(d + 1, d + val_cnt + 1, M[i].se) - d;
		buk_cnt[0] = val_cnt + 1;
		std::sort(Q + 1, Q + q_1 + 1, [&](const Ask &x, const Ask &y) {
			return x.l / B != y.l / B ? x.l / B < y.l / B :
				(x.r / B != y.r / B ? x.r / B < y.r / B :
				(x.r / B % 2 == 0 ? x.t > y.t : x.t < y.t)
			);
		});
		for(int i = 1, L = 1, R = 0, t = 0; i <= q_1; ++i) {
			while(L > Q[i].l) Add(--L);
			while(R < Q[i].r) Add(++R);
			while(t < Q[i].t) Modify(L, R, ++t);
			
			while(L < Q[i].l) Rmv(L++);
			while(R > Q[i].r) Rmv(R--);
			while(t > Q[i].t) Modify(L, R, t--);
			ans[Q[i].i] = Query();
		}
		for(int i = 1; i <= q_1; ++i)
			printf("%d\n", ans[i]);
	} return 0;
}