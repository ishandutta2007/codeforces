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
#define cnt(o) seg[o].cnt
#define Ls(o) seg[o].Ls
#define Rs(o) seg[o].Rs
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e5 + 5, B = 20, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int X;

struct Node {
	ll cnt;
	std::vector <pii> Ls, Rs;
	void Clear() { Ls.clear(); Rs.clear(); cnt = 0; }
	Node() { Clear(); }
} seg[N << 3];
void Assign(int o, int p, int v) {
	seg[o].Clear();
	cnt(o) = (v >= X);
	Ls(o).push_back(mkp(v, p));
	Rs(o).push_back(mkp(v, p));
}
bool Cmp(pii x, pii y) { return x.fi == y.fi; }
Node Merge(Node A, Node B, int l, int r) {
	Node ret;
	ret.cnt = A.cnt + B.cnt;
	for(pii i : A.Ls) ret.Ls.push_back(i);
	for(pii i : B.Ls) ret.Ls.push_back(mkp(i.fi | A.Ls.back().fi, i.se));
	for(pii i : B.Rs) ret.Rs.push_back(i);
	for(pii i : A.Rs) ret.Rs.push_back(mkp(i.fi | B.Rs.back().fi, i.se));
	ret.Ls.erase(std::unique(ret.Ls.begin(), ret.Ls.end(), Cmp), ret.Ls.end());
	ret.Rs.erase(std::unique(ret.Rs.begin(), ret.Rs.end(), Cmp), ret.Rs.end());
	for(int i = 0, j = B.Ls.size(); i < A.Rs.size(); ++i) {
		for(; j > 0 && (A.Rs[i].fi | B.Ls[j - 1].fi) >= X; --j);
		if(j == B.Ls.size()) continue;
		int pos_i = A.Rs[i].se, pos_j = B.Ls[j].se, cnt_i, cnt_j;
		cnt_i = pos_i - (i + 1 < A.Rs.size() ? A.Rs[i + 1].se : l - 1);
		cnt_j = r - pos_j + 1;
		ret.cnt += 1LL * cnt_i * cnt_j;
	}
	return ret;
}
void Update(int o, int l, int r) {
	seg[o] = Merge(seg[o << 1], seg[o << 1 | 1], l, r);
}
void Build(int o, int l, int r, int A[]) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid, A);
		Build(o << 1 | 1, mid + 1, r, A);
		Update(o, l, r);
	} else Assign(o, l, A[l]);
}
void Modify(int o, int l, int r, int p, int v) {
	if(l == r) Assign(o, p, v);
	else {
		int mid = (l + r) >> 1;
		if(p <= mid) Modify(o << 1, l, mid, p, v);
		else Modify(o << 1 | 1, mid + 1, r, p, v);
		Update(o, l, r);
	}
}
Node Query(int o, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return seg[o];
	int mid = (l + r) >> 1;
	if(ql <= mid && qr > mid)
		return Merge(
			Query(o << 1, l, mid, ql, mid),
			Query(o << 1 | 1, mid + 1, r, mid + 1, qr),
			ql, qr
		);
	else if(ql <= mid) return Query(o << 1, l, mid, ql, qr);
	else return Query(o << 1 | 1, mid + 1, r, ql, qr);
}

int A[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int n, q; rd(n, q, X);
		for(int i = 1; i <= n; ++i) rd(A[i]);
		Build(1, 1, n, A);
		while(q--) {
			int typ, x, y; rd(typ, x, y);
			if(typ == 1) {
				Modify(1, 1, n, x, y);
			} else {
				printf("%lld\n", Query(1, 1, n, x, y).cnt);
			}
		}
	} return 0;
}