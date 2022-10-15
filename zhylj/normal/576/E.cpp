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
const int N = 5e5 + 5, M = 50 + 5;

int n, m, K, q, U[N], V[N], col[N], q_e[N], q_c[N], lst[N], ans[N];
std::vector <int> E[N << 2];
void Insert(int o, int l, int r, int ql, int qr, int idx) {
	if(ql <= l && r <= qr) E[o].push_back(idx);
	else {
		int mid = (l + r) >> 1;
		if(ql <= mid) Insert(o << 1, l, mid, ql, qr, idx);
		if(qr > mid) Insert(o << 1 | 1, mid + 1, r, ql, qr, idx);
	}
}

int fa[M * (N << 1)], siz[M * (N << 1)], st[N << 1], top, top_2;
pii st_2[N << 1];
int Find(int x) { return fa[x] == x ? x : Find(fa[x]); }
void Merge(int x, int y) {
	x = Find(x); y = Find(y);
	if(x != y) {
		if(siz[x] > siz[y]) std::swap(x, y);
		fa[x] = y;
		siz[y] += siz[x];
		st[++top] = x;
	}
}
void Undo() {
	int x = st[top], y = fa[x]; --top;
	siz[y] -= siz[x]; fa[x] = x;
}
void Div(int o, int l, int r) {
	int _top = top, _top_2 = top_2;
	for(int i : E[o]) {
		int e = q_e[i], c = q_c[i];
		if(c) {
			Merge(U[e] + (c - 1) * 2 * n, V[e] + (c - 1) * 2 * n + n);
			Merge(U[e] + (c - 1) * 2 * n + n, V[e] + (c - 1) * 2 * n);
			st_2[++top_2] = mkp(e, col[e]);
			col[e] = c;
		}
	}
	if(l == r) {
		int e = q_e[l], c = q_c[l];
		if(Find(U[e] + (c - 1) * 2 * n) == Find(V[e] + (c - 1) * 2 * n)) {
			ans[l] = 0;
			q_c[l] = col[e];
		} else ans[l] = 1;
	} else {
		int mid = (l + r) >> 1;
		Div(o << 1, l, mid);
		Div(o << 1 | 1, mid + 1, r);
	}
	while(top != _top) Undo();
	while(top_2 != _top_2) {
		col[st_2[top_2].fi] = st_2[top_2].se;
		--top_2;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(ans, 0xff, sizeof(ans));
		rd(n, m, K, q);
		for(int i = 1; i <= 2 * n * K; ++i) fa[i] = i, siz[i] = 1;
		for(int i = 1; i <= m; ++i) rd(U[i], V[i]);
		for(int i = 1; i <= q; ++i) {
			int e, c; rd(e, c);
			if(col[e]) Insert(1, 1, q, lst[e] + 1, i, lst[e]);
			col[e] = c; lst[e] = i;
			q_e[i] = e; q_c[i] = c;
		}
		for(int i = 1; i <= m; ++i)
			if(col[i] && lst[i] + 1 <= q) Insert(1, 1, q, lst[i] + 1, q, lst[i]);
		memset(col, 0, sizeof(col));
		Div(1, 1, q);
		for(int i = 1; i <= q; ++i)
			printf(ans[i] ? "YES\n" : "NO\n");
	} return 0;
}