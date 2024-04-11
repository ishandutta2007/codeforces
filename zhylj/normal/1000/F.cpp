#include <bits/stdc++.h>

const int SIZE = 1 << 21;
char buf[SIZE], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
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
#define mkt std::make_tuple
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5;

int tag[N << 2];
void GetMax(int &x, int y) { x = std::max(x, y); }
void PushTag(int o) {
	if(tag[o]) {
		GetMax(tag[o << 1], tag[o]);
		GetMax(tag[o << 1 | 1], tag[o]);
		tag[o] = 0;
	}
}
void Modify(int o, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr) GetMax(tag[o], v);
	else {
		int mid = (l + r) >> 1;
		PushTag(o);
		if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
	}
}
int Query(int o, int l, int r, int p) {
	if(l == r) return tag[o];
	int mid = (l + r) >> 1;
	PushTag(o);
	if(p <= mid) return Query(o << 1, l, mid, p);
	else return Query(o << 1 | 1, mid + 1, r, p);
}

std::vector <std::tuple <int, int, int> > m[N];
std::vector <pii> ask[N];

std::vector <int> pos[N];
int n, ans[N], a[N], nxt[N], pre[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(!pos[a[i]].empty()) {
				pre[i] = pos[a[i]].back();
				nxt[pos[a[i]].back()] = i;
			}
			pos[a[i]].push_back(i);
		}
		int q; rd(q);
		for(int i = 1; i <= q; ++i) {
			int x, y; rd(x, y);
			ask[x].push_back(mkp(y, i));
		}
		for(int i = 1; i <= n; ++i) {
			int nx = nxt[i] ? nxt[i] : n + 1, pr = pre[i] ? pre[i] : 0;
			m[pr + 1].push_back(mkt(i, nx - 1, i));
		}
		for(int i = 1; i <= n; ++i) {
			for(auto t : m[i]) {
				int l = std::get<0>(t), r = std::get<1>(t), v = std::get<2>(t);
				Modify(1, 1, n, l, r, v);
			}
			for(pii p : ask[i]) {
				int res = Query(1, 1, n, p.fi);
				if(res >= i) ans[p.se] = a[res];
			}
		}
		for(int i = 1; i <= q; ++i)
			printf("%d\n", ans[i]);
	} return 0;
}