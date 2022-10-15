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
const int N = 1e6 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int seg[N << 3], tag[N << 3];
void Update(int o) {
	seg[o] = std::min(seg[o << 1], seg[o << 1 | 1]);
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
	if(ql > qr) return;
	if(ql <= l && r <= qr) seg[o] += v, tag[o] += v;
	else {
		int mid = (l + r) >> 1;
		PushTag(o);
		if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
		Update(o);
	}
}

struct Seg {
	int l, r; ll w;
} I[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int n, m; rd(n, m);
		for(int i = 1; i <= n; ++i) {
			rd(I[i].l, I[i].r, I[i].w);
		}
		std::sort(I + 1, I + n + 1, [](const Seg &x, const Seg &y) {
			return x.w < y.w;
		});
		ll ans = InfLL;
		for(int l = 1, r = 0; l <= n; ++l) {
			while(r + 1 <= n && !seg[1]) {
				++r;
				Modify(1, 1, m - 1, I[r].l, I[r].r - 1, 1);
			}
			if(seg[1]) {
				ans = std::min(ans, I[r].w - I[l].w);
			}
			Modify(1, 1, m - 1, I[l].l, I[l].r - 1, -1);
		}
		printf("%lld\n", ans);
	} return 0;
}