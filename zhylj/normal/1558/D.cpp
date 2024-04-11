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

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % Mod)
		if(b & 1) ret = 1LL * ret * bas % Mod;
	return ret;
}

int n, m, pos[N], i_x[N], i_y[N], d[N];

int seg[N << 3], tag[N << 3];
void Update(int o) {
	seg[o] = seg[o << 1] + seg[o << 1 | 1];
}
void PushTag(int o, int l, int r) {
	if(~tag[o]) {
		int mid = (l + r) >> 1;
		seg[o << 1] = tag[o] * (mid - l + 1);
		seg[o << 1 | 1] = tag[o] * (r - mid);
		tag[o << 1] = tag[o];
		tag[o << 1 | 1] = tag[o];
		tag[o] = -1;
	}
}
void Modify(int o, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr) seg[o] = v * (r - l + 1), tag[o] = v;
	else {
		int mid = (l + r) >> 1;
		PushTag(o, l, r);
		if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
		Update(o);
	}
}
int Query(int o, int l, int r, int k) {
	if(l == r) return l;
	int mid = (l + r) >> 1;
	PushTag(o, l, r);
	if(k <= seg[o << 1]) return Query(o << 1, l, mid, k);
	else return Query(o << 1 | 1, mid + 1, r, k - seg[o << 1]);
}

int fac[N], fac_inv[N];
void Init() {
	fac[0] = 1;
	for(int i = 1; i <= n * 2; ++i) fac[i] = 1LL * fac[i - 1] * i % Mod;
	fac_inv[n * 2] = QPow(fac[n * 2], Mod - 2);
	for(int i = n * 2 - 1; ~i; --i)
		fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % Mod;
}
int C(int x, int y) {
	if(x < y || y < 0) return 0;
	return 1LL * fac[x] * fac_inv[y] % Mod * fac_inv[x - y] % Mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	memset(tag, 0xff, sizeof(tag));
	n = 2e5; Init();
	while(test_case_cnt--) {
		rd(n, m);
		Modify(1, 1, n, 1, n, 1);
		for(int i = 1; i <= m; ++i) {
			rd(i_x[i], i_y[i]);
		}
		for(int i = m; i; --i) {
			pos[i] = Query(1, 1, n, i_y[i]);
			Modify(1, 1, n, pos[i], pos[i], 0);
			d[pos[i]] = i_x[i];
		}
		int cnt = 0;
		for(int i = 1; i <= m; ++i)
			if(d[pos[i]] > d[pos[i] + 1]) ++cnt;
		for(int i = 1; i <= m; ++i) d[pos[i]] = 0;
		printf("%d\n", C(n + n - cnt - 1, n));
	} return 0;
}