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
const int N = 5e5 + 5, INF = 0x3f3f3f3f;

int n;

#define mx(o) seg[o].mx
#define h_mx(o) seg[o].h_mx
#define tag(o) seg[o].tag
#define h_tag(o) seg[o].h_tag
struct SegT {
	struct Node {
		int mx, h_mx, tag, h_tag;
	} seg[N << 3];
	void Upd(int o) {
		mx(o) = std::max(mx(o << 1), mx(o << 1 | 1));
		h_mx(o) = std::max(h_mx(o << 1), h_mx(o << 1 | 1));
	}
	void AddTag(int o, int t, int h) {
		h_mx(o) = std::max(h_mx(o), mx(o) + h);
		h_tag(o) = std::max(h_tag(o), tag(o) + h);
		tag(o) += t; mx(o) += t;
	}
	void PushTag(int o) {
		if(tag(o) || h_tag(o)) {
			AddTag(o << 1, tag(o), h_tag(o));
			AddTag(o << 1 | 1, tag(o), h_tag(o));
			tag(o) = h_tag(o) = 0;
		}
	}
	void Modify(int o, int l, int r, int ql, int qr, int v) {
		if(ql <= l && r <= qr) AddTag(o, v, v);
		else {
			int mid = (l + r) >> 1;
			PushTag(o);
			if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
			if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
			Upd(o);
		}
	}
	int Query(int o, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return h_mx(o);
		int mid = (l + r) >> 1, ret = 0;
		PushTag(o);
		if(ql <= mid) ret = std::max(ret, Query(o << 1, l, mid, ql, qr));
		if(qr > mid) ret = std::max(ret, Query(o << 1 | 1, mid + 1, r, ql, qr));
		return ret;
	}
	void Output(int o, int l, int r) {
		if(l == r) printf("%d ", mx(o));
		else {
			int mid = (l + r) >> 1;
			PushTag(o);
			Output(o << 1, l, mid);
			Output(o << 1 | 1, mid + 1, r);
		}
	}
	void Add(int x, int v) {
		if(x) Modify(1, 1, n, 1, x, v);
	}
	void AddPoint(int x, int v) {
		if(x) Modify(1, 1, n, x, x, v);
	}
} A, B;

int dg[N], ans[N], h_1[N], h_2[N], f[N], g[N];
std::vector <int> E[N];
void Add(int u, int v) {
	++dg[u]; ++dg[v];
	E[u].push_back(v);
	E[v].push_back(u);
}

void Dfs(int u, int p) {
	for(int v : E[u]) if(v != p) {
		Dfs(v, u);
		f[u] = std::max(f[u], f[v] + 1);
	}
}
void Dfs2(int u, int p) {
	int mx = -INF;
	for(int v : E[u]) if(v != p) {
		g[v] = std::max(g[u] + 1, mx + 2);
		mx = std::max(mx, f[v]);
	}
	std::reverse(E[u].begin(), E[u].end());
	mx = -INF;
	for(int v : E[u]) if(v != p) {
		g[v] = std::max(g[v], mx + 2);
		mx = std::max(mx, f[v]);
	}
	std::reverse(E[u].begin(), E[u].end());
	for(int v : E[u]) if(v != p)
		Dfs2(v, u);
}

void Dfs3(int u, int p) {
	A.Add(g[u], 1);
	B.Add(g[u], 1);
	for(int v : E[u]) if(v != p) {
		A.Add(f[v] + 1, 1);
		B.Add(f[v] + 1, 1);
	}
	A.AddPoint(g[u] + 1, 1);
	A.AddPoint(g[u] + 1, -1);
	for(int v : E[u]) if(v != p) {
		A.AddPoint(f[v] + 2, 1);
		A.AddPoint(f[v] + 2, -1);
		B.Add(f[v] + 1, -1);
		for(int w : E[v]) if(w != u)
			B.Add(f[w] + 1, 1);
		for(int w : E[v]) if(w != u)
			B.Add(f[w] + 1, -1);
		B.Add(f[v] + 1, 1);
	}
	A.Add(g[u], -1);
	B.Add(g[u], -1);
	for(int v : E[u]) if(v != p) {
		A.Add(f[v] + 1, -1);
		B.Add(f[v] + 1, -1);
	}
	for(int v : E[u]) if(v != p) {
		Dfs3(v, u);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) ans[i] = 1;
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
			ans[1] = std::max({ ans[1], dg[u] + 1, dg[v] + 1 });
		}
		Dfs(1, 0);
		Dfs2(1, 0);
		Dfs3(1, 0);
		int p = 0;
		for(int i = 1; i <= n; ++i)
			p = std::max(p, f[i] + g[i]);
		for(int i = 1; i <= n; ++i) {
			h_1[i] = B.Query(1, 1, n, i, i);
			h_2[i] = A.Query(1, 1, n, i, i);
		}
		for(int i = 1; i <= n; ++i) {
			if(i % 2 == 0)
				ans[i] = std::max(ans[i], h_1[i / 2]);
			else if(i > 1)
				ans[i] = std::max(ans[i], h_2[(i + 1) / 2]);
			if(i <= p) ans[i] = std::max(ans[i], 2);
			printf("%d ", ans[i]);
		}
		printf("\n");
	} return 0;
}