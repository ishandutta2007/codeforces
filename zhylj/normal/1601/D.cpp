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

int n, d, f[N];
pii p[N];
std::vector <int> c[N];

int seg[N << 3], tag[N << 3];
void Update(int o) {
	seg[o] = std::max(seg[o << 1], seg[o << 1 | 1]);
}
void PushTag(int o) {
	if(tag[o]) {
		seg[o << 1] += tag[o];
		seg[o << 1 | 1] += tag[o];
		tag[o << 1] += tag[o];
		tag[o << 1 | 1] += tag[o];
		tag[o] = 0;
	}
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
int Query(int o, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return seg[o];
	int mid = (l + r) >> 1, ret = 0;
	PushTag(o);
	if(ql <= mid) ret = std::max(ret, Query(o << 1, l, mid, ql, qr));
	if(qr > mid) ret = std::max(ret, Query(o << 1 | 1, mid + 1, r, ql, qr));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, d);
		for(int i = 1; i <= n; ++i) {
			int s, a; rd(s, a);
			if(s < d) { --i; --n; continue; }
			a = std::max(a, d);
			p[i] = mkp(a, s);
		}
		std::sort(p + 1, p + n + 1);
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int k : c[i])
				Modify(1, 0, n, 0, k - 1, -1);
			int nxt = std::lower_bound(p + 1, p + n + 1, mkp(p[i].se, INF)) - p;
			f[i] = Query(1, 0, n, 0, std::min(i - 1, nxt - 1)) + 1;
			Modify(1, 0, n, i, i, f[i]);
			ans = std::max(ans, f[i]);
			if(nxt > i) {
				Modify(1, 0, n, 0, i - 1, 1);
				c[nxt].push_back(i);
			}
		}
		printf("%d\n", ans);
	} return 0;
}