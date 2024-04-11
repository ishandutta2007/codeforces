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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, p, a[N], pw[N];

struct Hash {
	int len, h, hr;
} seg[N << 3];
Hash Merge(Hash x, Hash y) {
	Hash ret; ret.len = x.len + y.len;
	ret.h = (x.h + 1LL * y.h * pw[x.len]) % Mod;
	ret.hr = (y.hr + 1LL * x.hr * pw[y.len]) % Mod;
	return ret;
}
void Update(int o) { seg[o] = Merge(seg[o << 1], seg[o << 1 | 1]); }
void Build(int o, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid);
		Build(o << 1 | 1, mid + 1, r);
		Update(o);
	} else seg[o] = (Hash) { 1, 0, 0 };
}
void Modify(int o, int l, int r, int k, int v) {
	if(l == r) seg[o].h = seg[o].hr = v;
	else {
		int mid = (l + r) >> 1;
		if(k <= mid) Modify(o << 1, l, mid, k, v);
		else Modify(o << 1 | 1, mid + 1, r, k, v);
		Update(o);
	}
}
Hash Query(int o, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return seg[o];
	int mid = (l + r) >> 1; Hash ret = (Hash) { 0, 0, 0 };
	if(ql <= mid) ret = Merge(ret, Query(o << 1, l, mid, ql, qr));
	if(qr > mid) ret = Merge(ret, Query(o << 1 | 1, mid + 1, r, ql, qr));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		srand(time(0));
		rd(n); p = rand() % Mod;
		for(int i = 1; i <= n; ++i) rd(a[i]);
		Build(1, 1, n);
		pw[0] = 1;
		for(int i = 1; i <= n; ++i)
			pw[i] = 1LL * pw[i - 1] * p % Mod;
		bool flag = false;
		for(int i = 1; i <= n; ++i) {
			int d = std::min(n - a[i], a[i] - 1);
			Hash ret = Query(1, 1, n, a[i] - d, a[i] + d);
			if(ret.h != ret.hr) { flag = true; break; }
			Modify(1, 1, n, a[i], 1);
		}
		printf(flag ? "YES\n" : "NO\n");
	} return 0;
}