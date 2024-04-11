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
#define seg(x) tr[x].L
#define lc(x) tr[x].lc
#define rc(x) tr[x].rc
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 2e5 + 5, kMax = 1e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n;
std::vector <int> E[kN];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}

struct Line {
	ll b, k;
	inline ll Get(int x) const { return k * x + b; }
	Line() { k = 0; b = kInfLL; }
	Line(ll tb, ll tk) : b(tb), k(tk) { }
};
struct Node {
	Line L;
	int lc, rc;
} tr[kN * 40];
int node_cnt = 0;
bool Cmp(const Line &a, const Line &b, int x) { return a.Get(x) < b.Get(x); }
void Insert(int &o, int l, int r, int ql, int qr, Line L) {
	if(!o) o = ++node_cnt;
	int mid = (l + r) >> 1;
	if(l == r) {
		seg(o) = Cmp(seg(o), L, l) ? seg(o) : L;
	} else if(ql <= l && r <= qr) {
		bool flag_l = Cmp(seg(o), L, l),
			flag_mid = Cmp(seg(o), L, mid),
			flag_r = Cmp(seg(o), L, r);
		if(flag_l + flag_mid + flag_r < 2) {
			std::swap(seg(o), L);
			flag_l ^= 1; flag_mid ^= 1; flag_r ^= 1;
		}
		if(!flag_l) Insert(lc(o), l, mid, ql, qr, L);
		else Insert(rc(o), mid + 1, r, ql, qr, L);
	} else {
		if(ql <= mid) Insert(lc(o), l, mid, ql, qr, L);
		if(qr > mid) Insert(rc(o), mid + 1, r, ql, qr, L);
	}
}
Line Query(int o, int l, int r, int p) {
	if(l == r) return seg(o);
	int mid = (l + r) >> 1; Line ret;
	if(p <= mid) ret = Query(lc(o), l, mid, p);
	else ret = Query(rc(o), mid + 1, r, p);
	if(Cmp(seg(o), ret, p)) ret = seg(o);
	return ret;
}
void Merge(int &x, int &y, int l, int r) {
	if(!x || !y) x = x ^ y;
	else {
		int mid = (l + r) >> 1;
		Merge(lc(x), lc(y), l, mid);
		Merge(rc(x), rc(y), mid + 1, r);
		Insert(x, l, r, l, r, seg(y));
	}
}

int fa[kN], rt[kN]; ll A[kN], B[kN], ans[kN];
void Dfs(int u) {
	bool leaf = true;
	for(auto v : E[u]) if(v != fa[u]) {
		fa[v] = u; Dfs(v);
		Merge(rt[u], rt[v], -kMax, kMax);
		leaf = false;
	}
	if(!leaf) {
		Line u_ans = Query(rt[u], -kMax, kMax, A[u]);
		ans[u] = u_ans.Get(A[u]);
	}
	Line u_f(ans[u], B[u]);
	Insert(rt[u], -kMax, kMax, -kMax, kMax, u_f);
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(A[i]);
		for(int i = 1; i <= n; ++i) rd(B[i]);
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
		}
		Dfs(1);
		for(int i = 1; i <= n; ++i)
			printf("%lld ", ans[i]);
		printf("\n");
	} return 0;
}