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
const int N = 1e6 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
ll s_pre[N], s_suf[N], s[N], mx[N << 2], f[N];

struct Itv {
	int l, r; 
	ll k, f;
};
std::vector <Itv> I[N << 2];
void Insert(int o, int l, int r, int ql, int qr, int k) {
	if(ql <= l && r <= qr) {
		mx[o] = std::max(mx[o], (ll)k);
	} else {
		int mid = (l + r) >> 1;
		if(ql <= mid) Insert(o << 1, l, mid, ql, qr, k);
		if(qr > mid) Insert(o << 1 | 1, mid + 1, r, ql, qr, k);
		if(ql <= mid && qr > mid) {
			I[o].push_back((Itv) { ql, qr, k, -INF });
		}
	}
}
void Div(int o, int l, int r) {
	if(l >= r) return;
	mx[o << 1] = std::max(mx[o], mx[o << 1]);
	mx[o << 1 | 1] = std::max(mx[o], mx[o << 1 | 1]);
	int mid = (l + r) >> 1;
	Div(o << 1, l, mid);
	if(mx[o] <= 2e9) I[o].push_back((Itv) { l, r, mx[o], -INF });
	std::sort(I[o].begin(), I[o].end(), [](const Itv &x, const Itv &y) {
		return x.l > y.l;
	});
	ll cur_mx = -INF;
	for(int i = 0, j = mid; i < I[o].size(); ++i) {
		for(; j >= l && j >= I[o][i].l; --j)
			cur_mx = std::max(cur_mx, f[j] - s[j - 1]);
		I[o][i].f = std::max(I[o][i].f, cur_mx);
	}
	cur_mx = -INF;
	std::sort(I[o].begin(), I[o].end(), [](const Itv &x, const Itv &y) {
		return x.r > y.r;
	});
	int j = r;
	for(int i = 0; i < I[o].size(); ++i) {
		for(; j > mid && j > I[o][i].r; --j)
			f[j] = std::max(f[j], cur_mx + s[j - 1]);
		cur_mx = std::max(I[o][i].f + I[o][i].k, cur_mx);
	}
	for(; j > mid; --j)
		f[j] = std::max(f[j], cur_mx + s[j - 1]);
	Div(o << 1 | 1, mid + 1, r);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(mx, ~0x3f, sizeof(mx));
		memset(f, ~0x3f, sizeof(f));
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(s_pre[i]), s_pre[i] += s_pre[i - 1];
		for(int i = 1; i <= n; ++i) rd(s[i << 1]);
		for(int i = 1; i <= n; ++i) rd(s_suf[i << 1]);
		for(int i = 1; i <= n << 1; ++i) {
			s[i] += s[i - 1];
		}
		for(int i = n << 1; i; --i) s_suf[i] += s_suf[i + 1];
		for(int i = 1; i <= n; ++i) f[(i << 1) - 1] = s_pre[i];
		for(int i = 1; i <= m; ++i) {
			int l, r, k; rd(l, r, k); k = -k;
			Insert(1, 1, n << 1, (l << 1) - 2, (r << 1) + 1, k);
		}
		Div(1, 1, n << 1);
		ll ans = -INF;
		for(int i = 2; i <= n << 1; i += 2)
			ans = std::max(ans, s_suf[i] + f[i] + s[i] - s[i - 1]);
		printf("%lld\n", ans);
	} return 0;
}