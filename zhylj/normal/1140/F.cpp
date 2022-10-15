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
const int N = 6e5 + 5, M = 3e5;

std::vector <pii> E[N << 1];
void Insert(int o, int l, int r, int ql, int qr, pii e) {
	if(ql <= l && r <= qr) E[o].push_back(e);
	else {
		int mid = (l + r) >> 1;
		if(ql <= mid) Insert(o << 1, l, mid, ql, qr, e);
		if(qr > mid) Insert(o << 1 | 1, mid + 1, r, ql, qr, e);
	}
}

int fa[N], a_siz[N], b_siz[N], st[N], top; ll cur_ans;
int Find(int x) { return fa[x] == x ? x : Find(fa[x]); }
void Merge(int x, int y) {
	int f_x = Find(x), f_y = Find(y);
	if(a_siz[f_x] + b_siz[f_x] > a_siz[f_y] + b_siz[f_y]) std::swap(f_x, f_y);
	if(f_x != f_y) {
		cur_ans -= 1LL * a_siz[f_y] * b_siz[f_y];
		cur_ans -= 1LL * a_siz[f_x] * b_siz[f_x];
		fa[f_x] = f_y;
		a_siz[f_y] += a_siz[f_x];
		b_siz[f_y] += b_siz[f_x];
		cur_ans += 1LL * a_siz[f_y] * b_siz[f_y];
		st[++top] = f_x;
	}
}
void Undo() {
	int x = st[top], y = fa[x]; --top;
	cur_ans -= 1LL * a_siz[y] * b_siz[y];
	fa[x] = x;
	a_siz[y] -= a_siz[x];
	b_siz[y] -= b_siz[x];
	cur_ans += 1LL * a_siz[y] * b_siz[y];
	cur_ans += 1LL * a_siz[x] * b_siz[x];
}
void Div(int o, int l, int r) {
	int _top = top;
	for(pii e : E[o]) Merge(e.fi, M + e.se);
	if(l == r) printf("%lld ", cur_ans);
	else {
		int mid = (l + r) >> 1;
		Div(o << 1, l, mid);
		Div(o << 1 | 1, mid + 1, r);
	}
	while(top != _top) Undo();
}

int q;
std::map <pii, int> S;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(q);
		for(int i = 1; i <= q; ++i) {
			int x, y; rd(x, y);
			if(!S.count(mkp(x, y))) S[mkp(x, y)] = i;
			else {
				Insert(1, 1, q, S[mkp(x, y)], i - 1, mkp(x, y));
				S.erase(mkp(x, y));
			}
		}
		for(auto t : S)
			Insert(1, 1, q, t.se, q, t.fi);
		for(int i = 1; i <= M << 1; ++i) {
			fa[i] = i; a_siz[i] = (i <= M); b_siz[i] = (i > M);
		}
		Div(1, 1, q);
		printf("\n");
	} return 0;
}