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
#define ch(o, p) T[o].ch[p]
#define val(o) T[o].val
#define fa(o) T[o].fa
#define siz(o) T[o].siz
#define Root(o) T[t_rt[o]].ch[1]
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e6 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

struct Node {
	int val, siz, fa, ch[2];
} T[N];
int t_rt[N], cnt;
int NewNode(int v, int f) { val(++cnt) = v; fa(cnt) = f; siz(cnt) = 1; return cnt; }
int Pos(int x) { return x == ch(fa(x), 1); }
void Update(int x) { siz(x) = siz(ch(x, 0)) + siz(ch(x, 1)) + 1; }
void Rotate(int x) {
	int y = fa(x), z = fa(y), p = Pos(x);
	if(z) ch(z, Pos(y)) = x;
	fa(x) = z; fa(y) = x; fa(ch(x, p ^ 1)) = y;
	ch(y, p) = ch(x, p ^ 1); ch(x, p ^ 1) = y;
	Update(y); Update(x);
}
void Splay(int x, int to) {
	for(; fa(x) != to; Rotate(x)) {
		if(fa(fa(x)) != to) Rotate(Pos(fa(x)) == Pos(x) ? fa(x) : x);
	}
}
void Build(int &x, int fa, int l, int r, std::vector <int> &v) {
	if(l <= r) {
		int mid = (l + r) >> 1;
		x = NewNode(v[mid - 1], fa); v[mid - 1] = x;
		Build(ch(x, 0), x, l, mid - 1, v);
		Build(ch(x, 1), x, mid + 1, r, v);
		Update(x);
	}
}
int FindKth(int k) {
	int x = Root(0); ++k;
	while(true) {
		int l_siz = siz(ch(x, 0));
		if(k == l_siz + 1) break;
		else if(k <= l_siz) x = ch(x, 0);
		else x = ch(x, 1), k -= l_siz + 1;
	}
	return x;
}
int Rank(int x) {
	Splay(x, t_rt[0]);
	return siz(ch(x, 0));
}
int KPrev(int t, int r) {
	int x = Root(t), ret = 1;
	while(true) {
		if(!val(x)) break;
		int x_rk = Rank(val(x));
		if(x_rk == r) { ret = x; break; }
		else if(x_rk > r) x = ch(x, 0);
		else ret = x, x = ch(x, 1);
	}
	return ret;
}
int KNxt(int t, int r) {
	int x = Root(t), ret = 1;
	while(true) {
		if(!val(x)) break;
		int x_rk = Rank(val(x));
		if(x_rk == r) { ret = x; break; }
		else if(x_rk > r) ret = x, x = ch(x, 0);
		else x = ch(x, 1);
	}
	return ret;
}

int n, A[N];
std::vector <int> a[N];

void Modify(int l, int r) {
	int t = val(FindKth(r)), R;
	Splay(KPrev(t, r - 1), t_rt[t]);
	Splay(KNxt(t, r + 1), Root(t));
	R = ch(ch(Root(t), 1), 0);
	--siz(fa(R)); --siz(fa(fa(R)));
	ch(fa(R), 0) = 0; fa(R) = 0;
	Splay(KPrev(t, l - 1), t_rt[t]);
	Splay(KNxt(t, l), Root(t));
	ch(ch(Root(t), 1), 0) = R; fa(R) = ch(Root(t), 1);
	siz(R) = 1; ++siz(fa(R)); ++siz(fa(fa(R)));
	Splay(FindKth(r - 1), t_rt[0]);
	Splay(FindKth(r + 1), Root(0));
	R = ch(ch(Root(0), 1), 0);
	--siz(fa(R)); --siz(fa(fa(R)));
	ch(fa(R), 0) = 0; fa(R) = 0;
	Splay(FindKth(l - 1), t_rt[0]);
	Splay(FindKth(l), Root(0));
	ch(ch(Root(0), 1), 0) = R; fa(R) = ch(Root(0), 1);
	siz(R) = 1; ++siz(fa(R)); ++siz(fa(fa(R)));
}
int Query(int l, int r, int k) {
	int ret = 0, R = KPrev(k, r), L = KPrev(k, l - 1);
	Splay(R, t_rt[k]);
	ret += siz(ch(Root(k), 0));
	Splay(L, t_rt[k]);
	ret -= siz(ch(Root(k), 0));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 0; i <= n; ++i)
			t_rt[i] = NewNode(0, 0);
		a[0].push_back(0);
		for(int i = 1; i <= n; ++i) {
			rd(A[i]); a[0].push_back(A[i]);
		}
		a[0].push_back(0);
		Build(Root(0), t_rt[0], 1, n + 2, a[0]);
		for(int i = 1; i <= n; ++i) a[i].push_back(a[0][0]);
		for(int i = 1; i <= n; ++i) a[A[i]].push_back(a[0][i]);
		for(int i = 1; i <= n; ++i) {
			a[i].push_back(a[0][n + 1]);
			Build(Root(i), t_rt[i], 1, a[i].size(), a[i]);
		}
		int q; rd(q);
		for(int i = 1, lst_ans = 0; i <= q; ++i) {
			int opt, l, r, k; rd(opt, l, r);
			if(opt == 2) rd(k);
			l = (l + lst_ans - 1) % n + 1;
			r = (r + lst_ans - 1) % n + 1;
			if(l > r) std::swap(l, r);
			k = (k + lst_ans - 1) % n + 1;
			if(opt == 1) Modify(l, r);
			else printf("%d\n", lst_ans = Query(l, r, k));
		}
	} return 0;
}