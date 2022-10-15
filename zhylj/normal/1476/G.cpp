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
const int N = 1e5 + 5, B = 2000, INF = 0x3f3f3f3f;

namespace List {

#define val(o) L[o].val
#define cnt(o) L[o].cnt
#define nxt(o) L[o].nxt
#define pre(o) L[o].pre
struct Node {
	int val, cnt, nxt, pre;
} L[N];
int bg, n_cnt;
std::queue <int> p;
int NewNode(int v, int c, int nx, int pr) {
	Node tmp = (Node) { v, c, nx, pr };
	if(!p.empty()) {
		int v = p.front(); p.pop();
		return L[v] = tmp, v;
	}
	return L[++n_cnt] = tmp, n_cnt;
}
void Init() { bg = NewNode(0, INF, 0, 0); }
void Erase(int x) {
	nxt(pre(x)) = nxt(x);
	pre(nxt(x)) = pre(x);
	p.push(x);
}
int MovNxt(int x) {
	int np;
	if(val(nxt(x)) == val(x) + 1) {
		++cnt(nxt(x));
		np = nxt(x);
	} else {
		np = NewNode(val(x) + 1, 1, nxt(x), x);
		pre(nxt(x)) = np;
		nxt(x) = np;
	}
	--cnt(x);
	if(!cnt(x)) Erase(x);
	return np;
}
int MovPre(int x) {
	int np;
	if(val(pre(x)) == val(x) - 1) {
		++cnt(pre(x));
		np = pre(x);
	} else {
		np = NewNode(val(x) - 1, 1, x, pre(x));
		nxt(pre(x)) = np;
		pre(x) = np;
	}
	--cnt(x);
	if(!cnt(x)) Erase(x);
	return np;
}
int Query(int k) {
	int ret = INF, itv_cnt = 0, v;
	for(int i = nxt(bg), j = nxt(bg); i; i = nxt(i)) {
		for(; itv_cnt < k && j; j = nxt(j))
			v = val(j), itv_cnt += cnt(j);
		if(itv_cnt >= k) ret = std::min(ret, v - val(i));
		itv_cnt -= cnt(i);
	}
	return ret;
}

};

struct Ask {
	int k, l, r, t, i;
} Q[N];
pii M[N];
int n, m, q_1, q_2, a[N], ans[N], i_pos[N];
void Add(int x) {
	int v = a[x];
	i_pos[v] = List::MovNxt(i_pos[v]);
}
void Del(int x) {
	int v = a[x];
	i_pos[v] = List::MovPre(i_pos[v]);
}
void Modify(int l, int r, int t) {
	if(l <= M[t].fi && M[t].fi <= r) {
		Del(M[t].fi);
		std::swap(a[M[t].fi], M[t].se);
		Add(M[t].fi);
	} else std::swap(a[M[t].fi], M[t].se);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m); List::Init();
		for(int i = 1; i < N; ++i)
			i_pos[i] = List::bg;
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= m; ++i) {
			int opt, x, y, k; rd(opt, x, y);
			if(opt == 1) {
				rd(k);
				++q_1;
				Q[q_1] = (Ask) { k, x, y, q_2, q_1 };
			} else {
				M[++q_2] = mkp(x, y);
			}
		}
		std::sort(Q + 1, Q + q_1 + 1, [&](const Ask &x, const Ask &y) {
			return x.l / B != y.l / B ? x.l / B < y.l / B :
				(x.r / B != y.r / B ? x.r / B < y.r / B : x.t < y.t);
		});
		for(int i = 1, l = 1, r = 0, t = 0; i <= q_1; ++i) {
			while(l > Q[i].l) Add(--l);
			while(r < Q[i].r) Add(++r);
			while(l < Q[i].l) Del(l++);
			while(r > Q[i].r) Del(r--);
			while(t < Q[i].t) Modify(l, r, ++t);
			while(t > Q[i].t) Modify(l, r, t--);
			ans[Q[i].i] = List::Query(Q[i].k);
		}
		for(int i = 1; i <= q_1; ++i)
			printf("%d\n", ans[i] == INF ? -1 : ans[i]);
	} return 0;
}