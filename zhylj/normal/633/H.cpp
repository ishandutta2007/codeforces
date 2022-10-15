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
const int N = 3e4 + 5, MAX = 1e9;

int M, f[N];

#define vec(o, p) tr[o].vec[p]
#define siz(o) tr[o].siz
#define lc(o) tr[o].lc
#define rc(o) tr[o].rc

struct Node {
	int vec[2], siz, lc, rc;
} tr[N * 40];
int n_cnt, rt;
void Update(int o) {
	siz(o) = siz(lc(o)) + siz(rc(o));
	int ls = siz(lc(o));
	if(!ls) {
		vec(o, 0) = vec(rc(o), 0);
		vec(o, 1) = vec(rc(o), 1);
		return;
	}
	vec(o, 0) = (vec(lc(o), 0) + 1LL * f[ls + 1] * vec(rc(o), 0) + 1LL * f[ls] * vec(rc(o), 1)) % M;
	vec(o, 1) = (vec(lc(o), 1) + 1LL * f[ls] * vec(rc(o), 0) + 1LL * f[ls - 1] * vec(rc(o), 1)) % M;
}
void Insert(int &o, int l, int r, int v, bool flag) {
	if(!o) o = ++n_cnt;
	if(l == r) {
		if(flag) { vec(o, 0) = v % M; vec(o, 1) = 0; siz(o) = 1; }
		else { vec(o, 0) = vec(o, 1) = siz(o) = 0; }
	} else {
		int mid = (l + r) >> 1;
		if(v <= mid) Insert(lc(o), l, mid, v, flag);
		else Insert(rc(o), mid + 1, r, v, flag);
		Update(o);
	}
}

std::map <int, int> buk;
void Add(int v) {
	if(!buk[v]) Insert(rt, 0, MAX, v, true);
	++buk[v];
}
void Rmv(int v) {
	--buk[v];
	if(!buk[v]) Insert(rt, 0, MAX, v, false);
}

struct Ask {
	int l, r, idx;
} Q[N];
int n, q, B, a[N], ans[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, M); B = sqrt(n);
		f[1] = f[2] = 1 % M;
		for(int i = 3; i < N; ++i)
			f[i] = (f[i - 1] + f[i - 2]) % M;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			buk[a[i]] = 0;
		}
		rd(q);
		for(int i = 1; i <= q; ++i) {
			int l, r; rd(l, r);
			Q[i] = (Ask) { l, r, i };
		}
		std::sort(Q + 1, Q + q + 1, [&](const Ask &x, const Ask &y) {
			return x.l / B != y.l / B ? x.l / B < y.l / B :
				(x.l / B % 2 == 0 ? x.r < y.r : x.r > y.r);
		});
		for(int i = 1, l = 1, r = 0; i <= q; ++i) {
			while(l > Q[i].l) Add(a[--l]);
			while(r < Q[i].r) Add(a[++r]);
			while(l < Q[i].l) Rmv(a[l++]);
			while(r > Q[i].r) Rmv(a[r--]);
			ans[Q[i].idx] = vec(rt, 0) % M;
		}
		for(int i = 1; i <= q; ++i)
			printf("%d\n", ans[i]);
	} return 0;
}