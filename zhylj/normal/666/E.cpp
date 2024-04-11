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
#define tr(x, c) sam[x].tr[c]
#define link(x) sam[x].link
#define len(x) sam[x].len
#define mx(x) seg[x].mx
#define mx_p(x) seg[x].mx_p
#define lc(x) seg[x].lc
#define rc(x) seg[x].rc
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1.2e6 + 5, B = 20, INF = 0x3f3f3f3f;

struct Node {
	int mx, mx_p, lc, rc;
	Node() { mx = 0; mx_p = INF; }
} seg[N * 25];
int o_cnt;
void Update(int x) {
	if(mx(lc(x)) >= mx(rc(x))) {
		mx(x) = mx(lc(x));
		mx_p(x) = mx_p(lc(x));
	} else {
		mx(x) = mx(rc(x));
		mx_p(x) = mx_p(rc(x));
	}
}
void Modify(int &o, int l, int r, int q, int v) {
	if(!o) o = ++o_cnt;
	if(l == r) mx(o) += v, mx_p(o) = l;
	else {
		int mid = (l + r) >> 1;
		if(q <= mid) Modify(lc(o), l, mid, q, v);
		else Modify(rc(o), mid + 1, r, q, v);
		Update(o);
	}
}
pii Max(pii a, pii b) {
	return a.fi != b.fi ? (a.fi > b.fi ? a : b) : (a.se < b.se ? a : b);
}
pii GetMax(int o, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return o ? mkp(mx(o), mx_p(o)) : mkp(0, l);
	else {
		int mid = (l + r) >> 1; pii ret = mkp(0, ql);
		if(ql <= mid) ret = Max(ret, GetMax(lc(o), l, mid, ql, qr));
		if(qr > mid) ret = Max(ret, GetMax(rc(o), mid + 1, r, ql, qr));
		return ret;
	}
}
int Merge(int A, int B, int l, int r) {
	if(!A || !B) return A ^ B;
	else {
		int o = ++o_cnt;
		if(l == r) mx(o) = mx(A) + mx(B), mx_p(o) = l;
		else {
			int mid = (l + r) >> 1;
			lc(o) = Merge(lc(A), lc(B), l, mid);
			rc(o) = Merge(rc(A), rc(B), mid + 1, r);
			Update(o);
		}
		return o;
	}
}

struct State {
	int tr[26], link, len;
} sam[N];
int n_cnt, rt[N];
void InitSAM() { link(0) = -1; }
int Insert(int lst, int c) {
	int np = 0, p = lst;
	if(!tr(p, c)) {
		np = ++n_cnt;
		len(np) = len(p) + 1;
		for(; ~p && !tr(p, c); p = link(p))
			tr(p, c) = np;
	}
	if(p == -1) return link(np) = 0, np;
	else {
		int q = tr(p, c);
		if(len(q) == len(p) + 1)
			return np ? (link(np) = q, np) : q;
		else {
			int nq = ++n_cnt;
			len(nq) = len(p) + 1;
			for(; ~p && tr(p, c) == q; p = link(p))
				tr(p, c) = nq;
			for(int i = 0; i < 26; ++i)
				tr(nq, i) = tr(q, i);
			link(nq) = link(q); link(q) = nq;
			return np ? (link(np) = nq, np) : nq;
		}
	}
}

int m;
void Insert(char s[], int idx) {
	int n = strlen(s + 1);
	for(int i = 1, lst = 0; i <= n; ++i) {
		lst = Insert(lst, s[i] - 'a');
		Modify(rt[lst], 1, m, idx, 1);
	}
}
int fa[N][22], pos[N];
std::vector <int> E[N];
void Dfs(int u) {
	for(int v : E[u]) {
		Dfs(v);
		rt[u] = Merge(rt[u], rt[v], 1, m);
	}
}
void Init() {
	for(int i = 1; i <= n_cnt; ++i) {
		fa[i][0] = link(i);
		E[link(i)].push_back(i);
	}
	for(int i = 1; i < B; ++i)
		for(int j = 0; j <= n_cnt; ++j)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
	Dfs(0);
}
pii Query(int l, int r, int ql, int qr) {
	int u = pos[r];
	for(int i = B - 1; ~i; --i)
		if(len(fa[u][i]) >= r - l + 1)
			u = fa[u][i];
	//if(len(u) < r - l + 1) return mkp(0, ql);
	return GetMax(rt[u], 1, m, ql, qr);
}

char s[N], t[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		InitSAM();
		scanf("%s", s + 1);
		rd(m);
		for(int i = 1; i <= m; ++i) {
			scanf("%s", t + 1);
			Insert(t, i);
		}
		int n = strlen(s + 1);
		for(int i = 1, u = 0; i <= n; ++i) {
			int c = s[i] - 'a';
			/*for(; u && !tr(u, c); u = link(u));
			u = tr(u, c);*/
			u = Insert(u, c);
			pos[i] = u;
		}
		Init();
		int q; rd(q);
		while(q--) {
			int l, r, ql, qr; rd(ql, qr, l, r);
			pii ans = Query(l, r, ql, qr);
			printf("%d %d\n", ans.se, ans.fi);
		}
	} return 0;
}