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
const int N = 1e5 + 5, M = 15, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, q; char g[N][M];

struct Mat {
	pii f[M]; int l;
} seg[N << 3];
int d[M][M];
Mat MakeRow(int r, char s[]) {
	memset(d, 0, sizeof(d));
	Mat ret; ret.l = r;
	for(int i = 1; i <= m; ++i) {
		d[i][i] = 1;
		if(s[i] == '>') d[i][i + 1] = 1;
		if(s[i] == '<') d[i][i - 1] = 1;
	}
	for(int k = 0; k <= m + 1; ++k)
		for(int i = 0; i <= m + 1; ++i)
			for(int j = 0; j <= m + 1; ++j)
				if(d[i][k] && d[k][j]) d[i][j] = 1;
	for(int i = 1; i <= m; ++i) {
		ret.f[i] = mkp(-1, -1);
		for(int j = 0; j <= m + 1; ++j) {
			if(d[i][j]) {
				if(s[j] == '^') ret.f[i] = mkp(r - 1, j);
				else if(j == 0 || j == m + 1) ret.f[i] = mkp(r, j);
			}
		}
	}
	return ret;
}
Mat Merge(Mat x, Mat y) {
	int mid = y.l - 1; Mat ret; ret.l = x.l;
	for(int i = 1; i <= m; ++i) {
		if(y.f[i].fi == mid) {
			ret.f[i] = x.f[y.f[i].se];
		} else ret.f[i] = y.f[i];
	}
	return ret;
}
void Update(int o) { seg[o] = Merge(seg[o << 1], seg[o << 1 | 1]); }
void Build(int o, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid);
		Build(o << 1 | 1, mid + 1, r);
		Update(o);
	} else seg[o] = MakeRow(l, g[l]);
}
void Modify(int o, int l, int r, int q) {
	if(l == r) seg[o] = MakeRow(l, g[l]);
	else {
		int mid = (l + r) >> 1;
		if(q <= mid) Modify(o << 1, l, mid, q);
		else Modify(o << 1 | 1, mid + 1, r, q);
		Update(o);
	}
}
pii Query(int o, int l, int r, pii s) {
	if(s.fi == r) return seg[o].f[s.se];
	int mid = (l + r) >> 1;
	if(s.fi > mid) s = Query(o << 1 | 1, mid + 1, r, s);
	if(s.fi <= mid && s.fi != -1) s = Query(o << 1, l, mid, s);
	return s;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, q);
		for(int i = 1; i <= n; ++i)
			scanf("%s", g[i] + 1);
		Build(1, 1, n);
		while(q--) {
			char opt[5], c[5]; scanf("%s", opt + 1);
			if(opt[1] == 'A') {
				int x, y; rd(x, y);
				pii ret = Query(1, 1, n, mkp(x, y));
				printf("%d %d\n", ret.fi, ret.se);
			} else if(opt[1] == 'C') {
				int x, y; rd(x, y); scanf("%s", c + 1);
				g[x][y] = c[1];
				Modify(1, 1, n, x);
			}
		}
	} return 0;
}