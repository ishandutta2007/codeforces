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
#define mn(o) tr[o].mn
#define tag(o) tr[o].tag
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, MAX = 1e6 + 1;

struct Seg {
	int mn, tag;
} tr[N << 2];
void Update(int o) { mn(o) = std::min(mn(o << 1), mn(o << 1 | 1)); }
void PushTag(int o) {
	if(tag(o)) {
		mn(o << 1) += tag(o);
		tag(o << 1) += tag(o);
		mn(o << 1 | 1) += tag(o);
		tag(o << 1 | 1) += tag(o);
		tag(o) = 0;
	}
}
void Modify(int o, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr) mn(o) += v, tag(o) += v;
	else {
		int mid = (l + r) >> 1;
		PushTag(o);
		if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
		Update(o);
	}
}
int Query(int o, int l, int r) {
	if(l == r) return mn(o) < 0 ? l : -1;
	int mid = (l + r) >> 1;
	PushTag(o);
	if(mn(o << 1 | 1) < 0) return Query(o << 1 | 1, mid + 1, r);
	else return Query(o << 1, l, mid);
}
int Get(int o, int l, int r, int q) {
	if(l == r) return mn(o);
	else {
		int mid = (l + r) >> 1;
		PushTag(o);
		if(q <= mid) return Get(o << 1, l, mid, q);
		else return Get(o << 1 | 1, mid + 1, r, q);
	}
}

int n, m, a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(a[i]), Modify(1, 1, MAX, 1, a[i], -1);
		for(int i = 1; i <= m; ++i) rd(b[i]), Modify(1, 1, MAX, 1, b[i], 1);
		int q; rd(q);
		while(q--) {
			int opt, x, y; rd(opt, x, y);
			if(opt == 1) {
				Modify(1, 1, MAX, 1, a[x], 1);
				a[x] = y;
				Modify(1, 1, MAX, 1, a[x], -1);
			} else {
				Modify(1, 1, MAX, 1, b[x], -1);
				b[x] = y;
				Modify(1, 1, MAX, 1, b[x], 1);
			}
			printf("%d\n", Query(1, 1, MAX));
		}
	} return 0;
}