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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, q, siz[N]; ll d[N];
std::vector <pii> E[N];
void Add(int u, int v, int w) {
	E[u].push_back(mkp(v, w));
}
void GetDep(int u) {
	siz[u] = 1;
	for(auto i : E[u]) {
		int v = i.fi, w = i.se;
		d[v] = d[u] + w;
		GetDep(v); siz[u] += siz[v];
	}
}

ll seg[N << 3], tag[N << 3];
void Update(int o) {
	seg[o] = std::min(seg[o << 1], seg[o << 1 | 1]);
}
void PushTag(int o) {
	if(tag[o]) {
		seg[o << 1] += tag[o]; tag[o << 1] += tag[o];
		seg[o << 1 | 1] += tag[o]; tag[o << 1 | 1] += tag[o];
		tag[o] = 0;
	}
}
void Build(int o, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid);
		Build(o << 1 | 1, mid + 1, r);
		Update(o);
	} else seg[o] = siz[l] > 1 ? InfLL : d[l];
}
void Modify(int o, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr) seg[o] += v, tag[o] += v;
	else {
		int mid = (l + r) >> 1;
		PushTag(o);
		if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
		Update(o);
	}
}
ll Query(int o, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return seg[o];
	int mid = (l + r) >> 1; ll ret = InfLL;
	PushTag(o);
	if(ql <= mid) ret = std::min(ret, Query(o << 1, l, mid, ql, qr));
	if(qr > mid) ret = std::min(ret, Query(o << 1 | 1, mid + 1, r, ql, qr));
	return ret;
}

struct Req {
	int l, r, idx;
}; std::vector <Req> req[N];
ll ans[N];
void Dfs(int u) {
	for(auto i : req[u]) {
		int l = i.l, r = i.r, idx = i.idx;
		ans[idx] = Query(1, 1, n, l, r);
	}
	for(auto i : E[u]) {
		int v = i.fi, w = i.se;
		Modify(1, 1, n, 1, n, w);
		Modify(1, 1, n, v, v + siz[v] - 1, -2 * w);
		Dfs(v);
		Modify(1, 1, n, 1, n, -w);
		Modify(1, 1, n, v, v + siz[v] - 1, 2 * w);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, q);
		for(int i = 1; i < n; ++i) {
			int v, w; rd(v, w);
			Add(v, i + 1, w);
		}
		for(int i = 1; i <= n; ++i)
			std::sort(E[i].begin(), E[i].end());
		GetDep(1);
		for(int i = 1; i <= q; ++i) {
			int v, l, r; rd(v, l, r);
			req[v].push_back((Req) { l, r, i });
		}
		Build(1, 1, n);
		Dfs(1);
		for(int i = 1; i <= q; ++i) {
			printf("%lld\n", ans[i]);
		}
	} return 0;
}